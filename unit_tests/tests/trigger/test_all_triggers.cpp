/**
 * @file test_all_triggers.cpp
 */
#include "pch.h"
#include "TriggerMeta.h"

// uncomment to test starting from specific trigger
//#define TEST_FROM_TRIGGER_ID ((int)TT_MAZDA_MIATA_NA)
// uncomment to test only newest trigger
//#define TEST_FROM_TRIGGER_ID ((int)TT_UNUSED - 1)
#define TEST_FROM_TRIGGER_ID 1

#define TEST_TO_TRIGGER_ID trigger_type_e::TT_UNUSED
// uncomment to test only one trigger
//#define TEST_TO_TRIGGER_ID (TEST_FROM_TRIGGER_ID + 1)

struct TriggerExportHelper
{
	FILE* fp;

	TriggerExportHelper() {
		fp = fopen (TRIGGERS_FILE_NAME, "w+");

		fprintf(fp, "# Generated by rusEFI unit test suite\n");
		fprintf(fp, "# This file is used by TriggerImage tool\n");
		fprintf(fp, "# See 'gen_trigger_images.bat'\n");
	}

	~TriggerExportHelper() {
		fclose(fp);
		printf("All triggers exported to %s\n", TRIGGERS_FILE_NAME);
	}
};

static TriggerExportHelper exportHelper;

class AllTriggersFixture : public ::testing::TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(
	Triggers,
	AllTriggersFixture,
	// Test all triggers from the first valid trigger thru the last
	// (Skip index 0, that's custom toothed wheel which is covered by others)
	::testing::Range((int)TEST_FROM_TRIGGER_ID, (int)TEST_TO_TRIGGER_ID)
);

extern bool printTriggerDebug;
extern bool printTriggerTrace;

TEST_P(AllTriggersFixture, TestTrigger) {
	// handy debugging options
	//printTriggerDebug = true;
	//printTriggerTrace = true;

	trigger_type_e tt = (trigger_type_e)GetParam();
	auto fp = exportHelper.fp;

	printf("Exporting %s\r\n", getTrigger_type_e(tt));

	persistent_config_s pc;
	memset(&pc, 0, sizeof(pc));
	Engine e;
	Engine* engine = &e;
	EngineTestHelperBase base(engine, &pc.engineConfiguration, &pc);

#if EFI_UNIT_TEST
extern TriggerDecoderBase initState;
    for (size_t i = 0;i<efi::size(initState.gapRatio);i++) {
      initState.gapRatio[i] = NAN;
    }
#endif // EFI_UNIT_TEST

	engineConfiguration->trigger.type = tt;
    setCamOperationMode();

	TriggerWaveform *shape = &engine->triggerCentral.triggerShape;
	TriggerFormDetails *triggerFormDetails = &engine->triggerCentral.triggerFormDetails;
	engine->updateTriggerWaveform();

	ASSERT_FALSE(shape->shapeDefinitionError) << "Trigger shapeDefinitionError";

	fprintf(fp, "TRIGGERTYPE %d %d %s %.2f\n", tt, shape->getLength(), getTrigger_type_e(tt), shape->tdcPosition);

	fprintf(fp, "%s=%s\n", TRIGGER_HARDCODED_OPERATION_MODE, shape->knownOperationMode ? "true" : "false");
	operation_mode_e mode = shape->getWheelOperationMode();
	bool isOneOfCrankShapes = mode == FOUR_STROKE_CRANK_SENSOR ||
			mode == FOUR_STROKE_THREE_TIMES_CRANK_SENSOR ||
			mode == FOUR_STROKE_SYMMETRICAL_CRANK_SENSOR ||
			mode == FOUR_STROKE_TWELVE_TIMES_CRANK_SENSOR;
	fprintf(fp, "%s=%s\n", TRIGGER_IS_CRANK_KEY, shape->knownOperationMode && isOneOfCrankShapes ? "true" : "false");

	fprintf(fp, "%s=%s\n", TRIGGER_HAS_SECOND_CHANNEL, shape->needSecondTriggerInput ? "true" : "false");
	fprintf(fp, "%s=%s\n", TRIGGER_IS_SECOND_WHEEL_CAM, shape->isSecondWheelCam ? "true" : "false");
	fprintf(fp, "%s=%d\n", TRIGGER_CYCLE_DURATION, (int)shape->getCycleDuration());
	fprintf(fp, "%s=%d\n", TRIGGER_GAPS_COUNT, shape->gapTrackingLength);
	fprintf(fp, "%s=%d\n", TRIGGER_WITH_SYNC, shape->isSynchronizationNeeded);
	for (int i = 0; i < shape->gapTrackingLength; i++) {
		fprintf(fp, "%s.%d=%f\n", TRIGGER_GAP_FROM, i, shape->syncronizationRatioFrom[i]);
		fprintf(fp, "%s.%d=%f\n", TRIGGER_GAP_TO, i, shape->syncronizationRatioTo[i]);
	}
	fprintf(fp, "# end of meta section\n");

	for (size_t i = 0; i < shape->getLength(); i++) {
		int triggerDefinitionCoordinate = (shape->getTriggerWaveformSynchPointIndex() + i) % shape->getSize();

		fprintf(fp, "event %d %d %d %.2f %f\n",
				i,
				shape->triggerSignalIndeces[triggerDefinitionCoordinate],
				shape->triggerSignalStates[triggerDefinitionCoordinate],
				triggerFormDetails->eventAngles[i],
				initState.gapRatio[i]
				);
	}
}
