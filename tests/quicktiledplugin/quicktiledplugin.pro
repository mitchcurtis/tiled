TEMPLATE = app
TARGET = tst_quicktiledplugin
CONFIG += warn_on qmltestcase
SOURCES += tst_quicktiledplugin.cpp

OTHER_FILES += data/*.qml

TESTDATA += data/tst_*

CONFIG(debug, debug|release) {
    VARIANT = debug
} else {
    VARIANT = release
}

# Adpated from http://stackoverflow.com/a/39234363/904422
win32 {
    copyQmlImport.commands = $(COPY_DIR) \"$$clean_path($$OUT_PWD/../../qml)\" \"$$shell_path($$OUT_PWD)/$$VARIANT\"
    copyTiledLibs.commands = $(COPY_DIR) \"$$clean_path($$OUT_PWD/../../lib)\" \"$$shell_path($$OUT_PWD)/$$VARIANT\"
} else {
    copyQmlImport.commands = $(COPY_DIR) \"$$clean_path($$OUT_PWD/../../qml)\" \"$$shell_path($$OUT_PWD)\"
    copyTiledLibs.commands = $(COPY_DIR) \"$$clean_path($$OUT_PWD/../../lib)\" \"$$shell_path($$OUT_PWD)\"
}
first.depends = $(first) copyQmlImport copyTiledLibs
export(first.depends)
export(copyQmlImport.commands)
export(copyTiledLibs.commands)
QMAKE_EXTRA_TARGETS += first copyQmlImport copyTiledLibs
