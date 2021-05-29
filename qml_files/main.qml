import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Window 2.2
import QtQuick.Controls 1.1
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.3
// import QtQuick 2.15

Window {
    id: root

//    property alias rect1: rect1

    title: qsTr("Chess Robot Stimulation")
    visible: true
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight
    color: "#2f2f35"

    Item {
        id: field
        property double cubeSizeHeight: Screen.desktopAvailableHeight/9.0
        property double cubeSizeWidth: (Screen.desktopAvailableHeight * 2.0)/15.0
        property double distBetweenBoardAndBoundaryHeight: cubeSizeHeight * 0.1
        property double distBetweenBoardAndBoundaryWidth: cubeSizeWidth * 0.1
        property double distOfSpecialChessPositionHeight: cubeSizeHeight * 0.075
        property double distOfSpecialChessPositionWidth: cubeSizeWidth * 0.075
        property double lengthOfSpecialChessPositionHeight: cubeSizeHeight * 0.2
        property double lengthOfSpecialChessPositionWidth: cubeSizeWidth * 0.2
        property double boundaryWidth: cubeSizeHeight * 0.025
        property double chessBoardWidth: boundaryWidth * 0.25
        property int numberX: 9
        property int numberY: 8
        property double beginX: cubeSizeWidth/2.0
        property double beginY: cubeSizeHeight/2.0
        property double beginXofRiver: cubeSizeWidth * 4.5
        property double beginYofRiver: cubeSizeHeight * 0.5
        property int textSizeInPixel: 50
        property int textSpaceHeight: 50
        property int textSpaceWidth: 50
        property bool showInitCHessBoard: true
        property int modelTwo:  2
        property int modelOne:  1
        property int modelFive: 5
        property double copyrightX: cubeSizeWidth/10.0
        property double copyrightY: cubeSizeHeight/10.0
        property double chessSize: cubeSizeWidth * 0.45
//        property double BAPosX: cubeSizeWidth/2.0
//        property double BAPosY: cubeSizeHeight * 3.5
//        property double boundaryWidthWidth: cubeSizeWidth * 0.075
    }

    Rectangle {
        // the entire boundaryu of the chess board
        id: rect1
        x: field.cubeSizeWidth/2.0 - field.distBetweenBoardAndBoundaryWidth
        y: field.cubeSizeHeight/2.0 - field.distBetweenBoardAndBoundaryHeight
        width: field.cubeSizeWidth * 9 + field.distBetweenBoardAndBoundaryWidth * 2
        height: field.cubeSizeHeight * 8 + field.distBetweenBoardAndBoundaryHeight * 2
        color: "transparent"
        border.color: "#fffef9"
        border.width: field.boundaryWidth
    }

//    Rectangle {
//        // use for test
//        id: rect2
//        x: field.cubeSizeWidth/2.0
//        y: field.cubeSizeHeight/2.0
//        width: field.cubeSizeWidth
//        height: field.cubeSizeHeight
//        color: "transparent"
//        border.color: "#fffef9"
//        border.width: field.chessBoardWidth
//    }

    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item1
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item2
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth * 2
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item3
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth * 3
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item4
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth * 5
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item5
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth * 6
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item6
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth * 7
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item7
            border.width: field.chessBoardWidth
        }
    }
    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            anchors.top: parent
            x: field.beginX + field.cubeSizeWidth * 8
            y: field.beginY + field.cubeSizeHeight * index
            color: "transparent"
            border.color: "#fffef9"
            id: item8
            border.width: field.chessBoardWidth
        }
    }

    Rectangle{
        width: field.cubeSizeWidth - 2 * field.distBetweenBoardAndBoundaryWidth/2.0
        height: field.cubeSizeHeight * 8 + 2 * field.distBetweenBoardAndBoundaryHeight
        x: field.beginXofRiver + field.distBetweenBoardAndBoundaryWidth/2.0
        y: field.beginYofRiver - field.distBetweenBoardAndBoundaryHeight
        color: "transparent"
        border.color: "#fffef9"
        id: rect2
        border.width: field.chessBoardWidth * 3
    }

    FontLoader {
        id: fixedFont
        name: "Courier"
    }

    Text {
        id: text1
        text: "楚"
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel
        color: "#fffef9"
        x: rect2.x + rect2.width/2.0 - field.textSpaceWidth/2.0
        y: rect2.y + rect2.height/2.0 - field.textSpaceHeight - field.cubeSizeHeight * 3
    }
    Text {
        id: text2
        text: "河"
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel
        color: "#fffef9"
        x: rect2.x + rect2.width/2.0 - field.textSpaceWidth/2.0
        y: rect2.y + rect2.height/2.0 - field.textSpaceHeight - field.cubeSizeHeight * 1
    }
    Text {
        id: text3
        text: "界"
        font.styleName: ""
        rotation: 180
        font.pixelSize: field.textSizeInPixel
        color: "#fffef9"
        x: rect2.x + rect2.width/2.0 - field.textSpaceWidth/2.0
        y: rect2.y + rect2.height/2.0 - field.textSpaceHeight + field.cubeSizeHeight * 1
    }
    Text {
        id: text4
        text: "汉"
        font.styleName: ""
        rotation: 180
        font.pixelSize: field.textSizeInPixel
        color: "#fffef9"
        x: rect2.x + rect2.width/2.0 - field.textSpaceWidth/2.0
        y: rect2.y + rect2.height/2.0 - field.textSpaceHeight + field.cubeSizeHeight * 3
    }

    Canvas{
        id: canvas
        width: parent.width
        height: parent.height
        onPaint: {
              var ctx = getContext("2d");
              draw(ctx);
        }

        function draw(ctx ) {
            ctx.clearRect(0, 0, parent.width, parent.height)
            ctx.fillStyle ="transparent"
            ctx.fillRect(0, 0,parent.width, parent.height)

            ctx.fillStyle ="#fffef9"
            ctx.lineWidth = field.chessBoardWidth * 2

            ctx.beginPath()
            ctx.moveTo(field.cubeSizeWidth/2.0, field.cubeSizeHeight * 3.5)
            ctx.lineTo(field.cubeSizeWidth * 2.5, field.cubeSizeHeight * 5.5)
            ctx.moveTo(field.cubeSizeWidth/2.0, field.cubeSizeHeight * 5.5)
            ctx.lineTo(field.cubeSizeWidth * 2.5, field.cubeSizeHeight * 3.5)
            ctx.moveTo(field.cubeSizeWidth * 7.5, field.cubeSizeHeight * 3.5)
            ctx.lineTo(field.cubeSizeWidth * 9.5, field.cubeSizeHeight * 5.5)
            ctx.moveTo(field.cubeSizeWidth * 9.5, field.cubeSizeHeight * 3.5)
            ctx.lineTo(field.cubeSizeWidth * 7.5, field.cubeSizeHeight * 5.5)

            ctx.moveTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)
            //************************************************************************************************************************

            ctx.moveTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 - field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 - field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight - field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 8.5 - field.distOfSpecialChessPositionHeight)

            //------------------------------------------------------------------------------------------------------------------------
            ctx.moveTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 - field.distOfSpecialChessPositionWidth  - field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)
            //------------------------------------------------------------------------------------------------------------------------
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            ctx.moveTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 1.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 7.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 2.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 7.5 + field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 3.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)

            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 2.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 4.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 6.5 + field.distOfSpecialChessPositionHeight)
            ctx.moveTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight + field.lengthOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)
            ctx.lineTo(field.cubeSizeWidth  * 6.5 + field.distOfSpecialChessPositionWidth  + field.lengthOfSpecialChessPositionWidth,
                       field.cubeSizeHeight * 0.5 + field.distOfSpecialChessPositionHeight)
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            // copyright
            ctx.fillText("Stimulation platform of SRTP -> Smart Chess Robot Li", field.copyrightX, field.copyrightY)
            ctx.strokeStyle = "#fffef9"
            ctx.stroke()
            ctx.endPath()
        }
    }


    Repeater {
        model: field.modelOne
        Image {
            id: bg
            source: "../chess/black_General.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth/2.0 - width/2.0
            y: field.cubeSizeHeight*(4.5 + index * 2) - height/2.0
        }
    }
    Repeater {
        model: field.modelOne
        Image {
            id: rg
            source: "../chess/red_General.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 9.5 - width/2.0
            y: field.cubeSizeHeight*(4.5 + index * 2) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: ba
            source: "../chess/black_Advisor.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth/2.0 - width/2.0
            y: field.cubeSizeHeight*(3.5 + index * 2) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: ra
            source: "../chess/red_Advisor.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 9.5 - width/2.0
            y: field.cubeSizeHeight*(3.5 + index * 2) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: be
            source: "../chess/black_Elephant.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth/2.0 - width/2.0
            y: field.cubeSizeHeight*(2.5 + index * 4) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: re
            source: "../chess/red_Elephant.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 9.5 - width/2.0
            y: field.cubeSizeHeight*(2.5 + index * 4) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: bh
            source: "../chess/black_Horse.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth/2.0 - width/2.0
            y: field.cubeSizeHeight*(1.5 + index * 6) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: rh
            source: "../chess/red_Horse.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 9.5 - width/2.0
            y: field.cubeSizeHeight*(1.5 + index * 6) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: bc
            source: "../chess/black_Chariot.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth/2.0 - width/2.0
            y: field.cubeSizeHeight*(0.5 + index * 8) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: rc
            source: "../chess/red_Chariot.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 9.5 - width/2.0
            y: field.cubeSizeHeight*(0.5 + index * 8) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: bC
            source: "../chess/black_Cannon.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 2.5 - width/2.0
            y: field.cubeSizeHeight*(1.5 + index * 6) - height/2.0
        }
    }
    Repeater {
        model: field.modelTwo
        Image {
            id: rC
            source: "../chess/red_Cannon.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 7.5 - width/2.0
            y: field.cubeSizeHeight*(1.5 + index * 6) - height/2.0
        }
    }
    Repeater {
        model: field.modelFive
        Image {
            id: bs
            source: "../chess/black_Soldier.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 3.5 - width/2.0
            y: field.cubeSizeHeight*(0.5 + index * 2) - height/2.0
        }
    }
    Repeater {
        model: field.modelFive
        Image {
            id: rs
            source: "../chess/red_Soldier.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 6.5 - width/2.0
            y: field.cubeSizeHeight*(0.5 + index * 2) - height/2.0
        }
    }

}
