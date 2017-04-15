import QtQuick 2.4
import QtTest 1.0

import org.mapeditor.Tiled 1.0

TestCase {
    id: testCase
    width: 600
    height: 600
    visible: true
    when: windowShown
    name: "MapItem"

    MapLoader {
        id: mapLoader
        source:  "../../../examples/isometric_grass_and_water.tmx"
    }

    MapItem {
        id: mapItem
        map: mapLoader.map
        visibleArea: Qt.rect(0, 0, testCase.width, testCase.height)
    }

    Rectangle {
        id: player
        width: 32
        height: 64
        color: "darkorange"
        opacity: 0.5
    }

    function initTestCase() {
        compare(mapLoader.status, MapLoader.Ready);
    }

    function test_coordinateConversion() {
        // TODO: expose tile size properties in Map as properties
        var playerPosInScreenCoords = mapItem.pixelToScreenCoords(64 / 2 - player.width / 2, 0);
        player.x = playerPosInScreenCoords.x;
        player.y = playerPosInScreenCoords.y;
        wait(3000);
    }
}
