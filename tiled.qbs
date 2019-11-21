import qbs 1.0
import qbs.Environment

Project {
    name: "Tiled"

    qbsSearchPaths: "qbs"
    minimumQbsVersion: "1.8"

    property string version: Environment.getEnv("TILED_VERSION") || "1.5.0";
    property bool snapshot: Environment.getEnv("TILED_SNAPSHOT") == "true"
    property bool release: Environment.getEnv("TILED_RELEASE") == "true"
    property bool installHeaders: false
    property bool useRPaths: true
    property bool windowsInstaller: false
    property bool enableZstd: false
    property string openSslPath: Environment.getEnv("OPENSSL_PATH")

    references: [
        "src/libtiled",
        "src/libtiledquick",
        "src/tiledquickplugin"
    ]
}
