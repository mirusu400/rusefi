package com.rusefi.output;

import com.rusefi.ReaderState;
import com.rusefi.ToolUtil;
import com.rusefi.util.LazyFile;

import java.io.File;
import java.io.IOException;

import static com.rusefi.ToolUtil.EOL;

/**
 * This class generates java representation of rusEfi data structures used by rusEfi console
 */
public class FileJavaFieldsConsumer extends JavaFieldsConsumer {
    private static final String JAVA_PACKAGE = "com.rusefi.config.generated";

    private final LazyFile javaFields;
    private final String className;

    public FileJavaFieldsConsumer(ReaderState state, String javaDestination, int baseOffset) {
        super(state, baseOffset);
        javaFields = new LazyFile(javaDestination);
        String className = new File(javaDestination).getName();
        this.className = className.substring(0, className.indexOf('.'));
    }

    @Override
    public void startFile() {
        javaFields.write("package " + JAVA_PACKAGE + ";" + ToolUtil.EOL + ToolUtil.EOL);
        javaFields.write("// this file " + state.getHeader() + ToolUtil.EOL + EOL);
        javaFields.write("// by " + getClass() + EOL);
        javaFields.write("import com.rusefi.config.*;" + EOL + EOL);
        javaFields.write("public class " + className + " {" + ToolUtil.EOL);
    }

    @Override
    public void endFile() throws IOException {
        javaFields.write(state.getVariableRegistry().getJavaConstants());
        javaFields.write(getContent());

        if (allFields.length() > 0) {
            javaFields.write("\tpublic static final Field[] VALUES = {" + EOL);
            allFields.append("\t};" + EOL);
            javaFields.write(allFields.toString());
        }

        javaFields.write("}" + ToolUtil.EOL);
        javaFields.close();
    }
}
