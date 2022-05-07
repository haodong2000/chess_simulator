import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.1


Rectangle {
    width: 1920/10.0
    height: 1080/15.0
    color: "#c06f98"
    opacity: 0.75
    radius: 20
    border.width: 20
    border.color: "#c06f98"

    property alias text: info.text

    Text {
        id: info
        text: qsTr("MyLabel")
        font.pixelSize: 19
        font.family: "Consolas"
        color: "#fffef9"

        anchors.centerIn: parent
    }

}

