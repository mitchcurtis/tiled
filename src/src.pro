include(../tiled.pri)

TEMPLATE  = subdirs
CONFIG   += ordered

SUBDIRS = \
    libtiled

minQtVersion(5, 4, 0) {
    SUBDIRS += \
        tiledquickplugin
}
