import qbs 1.0
import qbs.Environment

Project {
    name: "Tiled"

    qbsSearchPaths: "qbs"
    minimumQbsVersion: "1.8"

    property string version: Environment.getEnv("TILED_VERSION") || "1.1.5";
    property bool sparkleEnabled: Environment.getEnv("TILED_SPARKLE")
    property bool snapshot: Environment.getEnv("TILED_SNAPSHOT")
    property bool release: Environment.getEnv("TILED_RELEASE")
    property bool installHeaders: false
    property bool useRPaths: true
    property bool windowsInstaller: false

    references: [
        "src/libtiled",
        "src/tiledquickplugin"
    ]
}
