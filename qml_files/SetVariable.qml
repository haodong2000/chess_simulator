import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.1

Rectangle {
    id: root
    x: 0
    y: 0
    border.width: 0
    color: "transparent"

    Item {
        id: setField
        property int textWidth: Screen.width/10.0
        property int textHeight: Screen.height/15.0
        property double cubeSizeHeight: Screen.height/10.0 // Screen.width
        property double cubeSizeWidth: (Screen.height * 2.0)/15.0 // Screen.height

        property int initWindowDelta: cubeSizeWidth * 0.5
        property int initWindowWidth: cubeSizeWidth * 3.7
        property int initWindowHeight: cubeSizeHeight * 3.5
    }

    Row {
        x: setField.initWindowDelta + 100
        y: setField.cubeSizeHeight * 4.75 + 5
        z: (setField.initWindowShow) ? 4 : -4
        spacing: setField.initWindowDelta * 3.70
        TextField {
            width: setField.cubeSizeWidth * 1.75
            height: setField.textHeight

            text: "5"
            background: Rectangle{
                color: "#c06f98"
                opacity: 0.75
                radius: 20
                border.width: 20
                border.color: "#c06f98"
            }
            font.pixelSize: 19
            font.family: "Consolas"
            color: "#fffef9"
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: { InitSetUp.mode = text }
        }

        TextField {
            width: setField.textWidth
            height: setField.textHeight

            text: "3"
            background: Rectangle{
                color: "#c06f98"
                opacity: 0.75
                radius: 20
                border.width: 20
                border.color: "#c06f98"
            }
            font.pixelSize: 19
            font.family: "Consolas"
            color: "#fffef9"
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: { InitSetUp.difficulty = text }
        }
    }

    Column {
        x: setField.cubeSizeWidth * 7.75
        y: setField.cubeSizeHeight * 4.75 + 19
        z: (setField.initWindowShow) ? 4 : -4
        spacing: setField.initWindowDelta * 0.2
        TextField {
            width: setField.textWidth
            height: Screen.height/30.0

            text: "1"
            background: Rectangle{
                color: "#c06f98"
                opacity: 0.75
                radius: 20
                border.width: 20
                border.color: "#c06f98"
            }
            font.pixelSize: 19
            font.family: "Consolas"
            color: "#fffef9"
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: { InitSetUp.end = text }
        }
        TextField {
            width: setField.textWidth
            height: Screen.height/30.0

            text: "1"
            background: Rectangle{
                color: "#c06f98"
                opacity: 0.75
                radius: 20
                border.width: 20
                border.color: "#c06f98"
            }
            font.pixelSize: 19
            font.family: "Consolas"
            color: "#fffef9"
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: { InitSetUp.manual = text }
        }
    }

    Row {
        x: setField.cubeSizeWidth * 7.75 + setField.initWindowDelta * 4.0 + Screen.width/10.0
        y: setField.cubeSizeHeight * 4.75 + 5
        z: (setField.initWindowShow) ? 4 : -4
        spacing: setField.initWindowDelta * 4.0
        TextField {
            width: setField.textWidth
            height: setField.textHeight

            text: "1"
            background: Rectangle{
                color: "#c06f98"
                opacity: 0.75
                radius: 20
                border.width: 20
                border.color: "#c06f98"
            }
            font.pixelSize: 19
            font.family: "Consolas"
            color: "#fffef9"
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: { InitSetUp.back = text }
        }
    }
}
