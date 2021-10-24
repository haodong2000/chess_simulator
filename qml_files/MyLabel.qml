import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.1


Rectangle {
    width: Screen.width/10.0
    height: Screen.height/10.0
    color: "#606060"
    border.color: "#303030"

    property alias text: info.text

    Text {
        id: info
        text: qsTr("MyLabel")
        font.pixelSize: 24
        color: "#00FFFF"

        anchors.centerIn: parent
    }

}

