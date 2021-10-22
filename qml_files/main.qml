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
    objectName: "window_root"

//    property alias rect1: rect1

    title: qsTr("Chess Robot Stimulation")
    visible: true
//    width: Screen.desktopAvailableWidth // Screen.width
//    height: Screen.desktopAvailableHeight // Screen.height
    width: Screen.width // 1920
    height: Screen.height // 1080
    color: "#2f2f35"

    Item {
        id: field
        anchors.fill: parent
        objectName: "field_root"
//        property double cubeSizeHeight: Screen.desktopAvailableHeight/10.0 // Screen.width
//        property double cubeSizeWidth: (Screen.desktopAvailableHeight * 2.0)/15.0 // Screen.height
        property double cubeSizeHeight: Screen.height/10.0 // Screen.width
        property double cubeSizeWidth: (Screen.height * 2.0)/15.0 // Screen.height
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

        property bool showInitCHessBoardRepeat: false
        property bool showInitCHessBoardSingle: true

        property int modelTwoRepeat:  (showInitCHessBoardRepeat == true) ? 2:0
        property int modelOneRepeat:  (showInitCHessBoardRepeat == true) ? 1:0
        property int modelFiveRepeat: (showInitCHessBoardRepeat == true) ? 5:0
        property int modelTwoSingle:  (showInitCHessBoardRepeat == true) ? 2:0
        property int modelOneSingle:  (showInitCHessBoardRepeat == true) ? 1:0
        property int modelFiveSingle: (showInitCHessBoardRepeat == true) ? 5:0
        property double copyrightX: cubeSizeWidth/10.0
        property double copyrightY: Screen.height - cubeSizeHeight/1.5

        property double chessSize: cubeSizeWidth * 0.625

        property double b_gen_1_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_gen_1_posY: cubeSizeHeight * 4.5 - chessSize/2.0
        property double r_gen_1_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_gen_1_posY: cubeSizeHeight * 4.5 - chessSize/2.0

        property double b_adv_1_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_adv_1_posY: cubeSizeHeight * 3.5 - chessSize/2.0
        property double r_adv_1_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_adv_1_posY: cubeSizeHeight * 3.5 - chessSize/2.0
        property double b_adv_2_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_adv_2_posY: cubeSizeHeight * 5.5 - chessSize/2.0
        property double r_adv_2_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_adv_2_posY: cubeSizeHeight * 5.5 - chessSize/2.0

        property double b_ele_1_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_ele_1_posY: cubeSizeHeight * 2.5 - chessSize/2.0
        property double r_ele_1_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_ele_1_posY: cubeSizeHeight * 2.5 - chessSize/2.0
        property double b_ele_2_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_ele_2_posY: cubeSizeHeight * 6.5 - chessSize/2.0
        property double r_ele_2_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_ele_2_posY: cubeSizeHeight * 6.5 - chessSize/2.0

        property double b_hor_1_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_hor_1_posY: cubeSizeHeight * 1.5 - chessSize/2.0
        property double r_hor_1_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_hor_1_posY: cubeSizeHeight * 1.5 - chessSize/2.0
        property double b_hor_2_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_hor_2_posY: cubeSizeHeight * 7.5 - chessSize/2.0
        property double r_hor_2_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_hor_2_posY: cubeSizeHeight * 7.5 - chessSize/2.0

        property double b_cha_1_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_cha_1_posY: cubeSizeHeight/2.0 - chessSize/2.0
        property double r_cha_1_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_cha_1_posY: cubeSizeHeight/2.0 - chessSize/2.0
        property double b_cha_2_posX: cubeSizeWidth/2.0 - chessSize/2.0
        property double b_cha_2_posY: cubeSizeHeight * 8.5 - chessSize/2.0
        property double r_cha_2_posX: cubeSizeWidth * 9.5 - chessSize/2.0
        property double r_cha_2_posY: cubeSizeHeight * 8.5 - chessSize/2.0

        property double b_can_1_posX: cubeSizeWidth * 2.5 - chessSize/2.0
        property double b_can_1_posY: cubeSizeHeight * 1.5 - chessSize/2.0
        property double r_can_1_posX: cubeSizeWidth * 7.5 - chessSize/2.0
        property double r_can_1_posY: cubeSizeHeight * 1.5 - chessSize/2.0
        property double b_can_2_posX: cubeSizeWidth * 2.5 - chessSize/2.0
        property double b_can_2_posY: cubeSizeHeight * 7.5 - chessSize/2.0
        property double r_can_2_posX: cubeSizeWidth * 7.5 - chessSize/2.0
        property double r_can_2_posY: cubeSizeHeight * 7.5 - chessSize/2.0

        property double b_sol_1_posX: cubeSizeWidth * 3.5 - chessSize/2.0
        property double b_sol_1_posY: cubeSizeHeight/2.0 - chessSize/2.0
        property double r_sol_1_posX: cubeSizeWidth * 6.5 - chessSize/2.0
        property double r_sol_1_posY: cubeSizeHeight/2.0 - chessSize/2.0
        property double b_sol_2_posX: cubeSizeWidth * 3.5 - chessSize/2.0
        property double b_sol_2_posY: cubeSizeHeight * 2.5 - chessSize/2.0
        property double r_sol_2_posX: cubeSizeWidth * 6.5 - chessSize/2.0
        property double r_sol_2_posY: cubeSizeHeight * 2.5 - chessSize/2.0
        property double b_sol_3_posX: cubeSizeWidth * 3.5 - chessSize/2.0
        property double b_sol_3_posY: cubeSizeHeight * 4.5 - chessSize/2.0
        property double r_sol_3_posX: cubeSizeWidth * 6.5 - chessSize/2.0
        property double r_sol_3_posY: cubeSizeHeight * 4.5 - chessSize/2.0
        property double b_sol_4_posX: cubeSizeWidth * 3.5 - chessSize/2.0
        property double b_sol_4_posY: cubeSizeHeight * 6.5 - chessSize/2.0
        property double r_sol_4_posX: cubeSizeWidth * 6.5 - chessSize/2.0
        property double r_sol_4_posY: cubeSizeHeight * 6.5 - chessSize/2.0
        property double b_sol_5_posX: cubeSizeWidth * 3.5 - chessSize/2.0
        property double b_sol_5_posY: cubeSizeHeight * 8.5 - chessSize/2.0
        property double r_sol_5_posX: cubeSizeWidth * 6.5 - chessSize/2.0
        property double r_sol_5_posY: cubeSizeHeight * 8.5 - chessSize/2.0

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        property bool b_gen_1_alive: true
        property bool r_gen_1_alive: true

        property bool onlyTwoGeneralsInRow_blackWin: false
        property bool onlyTwoGeneralsInRow_redWin: false

        property bool isGameStop: !(b_gen_1_alive && r_gen_1_alive)
        property bool isBlackWin: (b_gen_1_alive && !(r_gen_1_alive)) || onlyTwoGeneralsInRow_blackWin
        property bool isRedWin:   (r_gen_1_alive && !(b_gen_1_alive)) || onlyTwoGeneralsInRow_redWin

        property bool b_adv_1_alive: true
        property bool r_adv_1_alive: true
        property bool b_adv_2_alive: true
        property bool r_adv_2_alive: true

        property bool b_ele_1_alive: true
        property bool r_ele_1_alive: true
        property bool b_ele_2_alive: true
        property bool r_ele_2_alive: true

        property bool b_hor_1_alive: true
        property bool r_hor_1_alive: true
        property bool b_hor_2_alive: true
        property bool r_hor_2_alive: true

        property bool b_cha_1_alive: true
        property bool r_cha_1_alive: true
        property bool b_cha_2_alive: true
        property bool r_cha_2_alive: true

        property bool b_can_1_alive: true
        property bool r_can_1_alive: true
        property bool b_can_2_alive: true
        property bool r_can_2_alive: true

        property bool b_sol_1_alive: true
        property bool r_sol_1_alive: true
        property bool b_sol_2_alive: true
        property bool r_sol_2_alive: true
        property bool b_sol_3_alive: true
        property bool r_sol_3_alive: true
        property bool b_sol_4_alive: true
        property bool r_sol_4_alive: true
        property bool b_sol_5_alive: true
        property bool r_sol_5_alive: true

//        property double BAPosX: cubeSizeWidth/2.0
//        property double BAPosY: cubeSizeHeight * 3.5
//        property double boundaryWidthWidth: cubeSizeWidth * 0.075

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        property int turn_cube_x: Screen.width - Screen.width/4.0
        property int turn_cube_y: Screen.height/7.5
        property int turn_cube_width: Screen.width/5.0
        property int turn_cube_height: Screen.height/10.0
        property int turn_width: boundaryWidth * 2.5
        property bool ai_turn: false
        property bool humen_turn: !ai_turn
        property int turn_text_width: ai_turn ? turn_cube_width/4.5 : turn_cube_width/8.0
        property int turn_text_height: turn_cube_height/5.0

        property int time_cube_x: turn_cube_x
        property int time_cube_y: turn_cube_y * 6.0
        property int time_cube_width: turn_cube_width
        property int time_text_width: turn_cube_width * 0.125
        property int time_cube_height: turn_cube_height/2.0
        property int time_text_height: turn_cube_height/10.0
        property int time_width: boundaryWidth * 0.75
        property int time_delte: 45

        property bool is_endgame_mode: false
        property bool is_endgame_show: !is_endgame_mode
        property bool is_vision_board_done: false
        property bool is_vision_board_show: !is_vision_board_done
        property int vision_cube_x: turn_cube_x
        property int vision_cube_y: turn_cube_y * 2.0
        property int vision_cube_width: turn_cube_width
        property int vision_cube_height: turn_cube_height * 0.75
        property int vision_text_width: vision_cube_width/15.0
        property int vision_text_height: vision_cube_height/4.5
        property int vision_width: turn_width * 0.75

        property bool is_strategy_mode: false
        property bool is_strategy_show: !is_strategy_mode
        property int strategy_mode: 0
        property int strategy_cube_x: turn_cube_x
        property int strategy_cube_y: turn_cube_y * 2.0
        property int strategy_cube_width: turn_cube_width
        property int strategy_cube_height: turn_cube_height * 0.75
        property int strategy_text_width: vision_cube_width/15.0
        property int strategy_text_height: vision_cube_height/27.5
        property int strategy_width: turn_width * 0.75

        property int rule_text_size: 20
        property int rule_text_x: turn_cube_x
        property int rule_text_y: turn_cube_y * 3

        property int win_text_x: turn_cube_x
        property int win_text_y: turn_cube_y * 4

        property var lastMousePosX: -999
        property var lastMousePosY: -999
        property var curMousePosX: -1
        property var curMousePosY: -1

        property var selectChessX: -9999
        property var selectChessY: -9999
        property var selectChessSize: chessSize * 1.20
        property var selectChessWidth: turn_width/2.0

        property bool selectChessShow: true

        property bool isBackgroundSet: true
        property bool isBackgroundText: true

        property double background_text_posX: cubeSizeWidth * 1.0
        property double background_text_posY: cubeSizeHeight * 1.5
        property int background_text_size: 300

        property bool isAnimation: false
        property double animation_start_X: -100
        property double animation_start_Y: -100
        property double animation_end_X: -100
        property double animation_end_Y: -100
        property bool isLeftXie: (animation_start_X - animation_end_X) * (animation_start_Y - animation_end_Y) >= 0
        property double animation_posX: cubeSizeWidth * (animation_start_X + animation_end_X)/2.0
        property double animation_posY: cubeSizeHeight * (animation_start_Y + animation_end_Y)/2.0
        property double animation_width: cubeSizeWidth * Math.abs(animation_start_X - animation_end_X)
        property double animation_height: cubeSizeHeight * Math.abs(animation_start_Y - animation_end_Y)
        property double animation_xie: Math.sqrt(animation_width * animation_width + animation_height * animation_height)
        property double animation_cos: animation_width/animation_xie
        property double animation_sin: animation_height/animation_xie

        property bool killedChessDisplay: true
        property double killedChessDisplay_x_www: turn_cube_x
        property double killedChessDisplay_y_www: turn_cube_y * 4.75
        property double killedChessDisplay_x: turn_cube_x + cubeSizeWidth * 1.5
        property double killedChessDisplay_y: killedChessDisplay_y_www
        property double killedChessDisplay_x_text: turn_cube_x + cubeSizeWidth
        property double killedChessDisplay_y_text: killedChessDisplay_y_www
    }

    Image {
        id: kill
        source: "../chess/red_General.svg"
        width: field.chessSize
        height: width
        x: field.killedChessDisplay_x_www + field.chessSize * 0.35
        y: field.killedChessDisplay_y_www - field.chessSize * 0.25
    }

    Image {
        id: bekilled
        source: "../chess/red_General.svg"
        width: field.chessSize
        height: width
        x: field.killedChessDisplay_x + field.chessSize * 0.35
        y: field.killedChessDisplay_y - field.chessSize * 0.25
    }
    Text {
        id: chesskill
        text: (field.killedChessDisplay) ? "KILLS" : ""
        font.family: "Consolas"
        opacity: 1.0
        font.styleName: ""
        font.pixelSize: field.rule_text_size * 1.25
        font.bold: true
        color: (field.killedChessDisplay) ? "#fffef9" : ""
        x: field.killedChessDisplay_x_text
        y: field.killedChessDisplay_y_text
    }

    Image {
        id: background
        source: (field.isBackgroundSet) ? "../background/Ocean.jpg" : ""
    }

    Text {
        id: text_background
        text: "Chess\n    Robot"
        font.family: "Consolas"
        opacity: 0.15
        font.styleName: ""
        font.pixelSize: field.background_text_size
        font.bold: true
        color: (field.isBackgroundText) ? "#2486b9" : ""
        x: field.background_text_posX
        y: field.background_text_posY
    }

    Rectangle {
            id: xiu
            x: field.animation_posX + field.cubeSizeWidth * 0.5 - field.animation_xie * 0.5 - field.chessSize * 0.5 - 10
            y: field.animation_posY + field.cubeSizeHeight * 0.5 - field.chessSize * 0.5 - 10
            width: field.animation_xie + field.chessSize + 20
            height: field.chessSize + 20
            color: (field.isAnimation) ? "#bc84a8" : "#ccccd6"
            opacity: (field.isAnimation) ? 0.5 : 0.1
            rotation: (field.isLeftXie) ? Math.asin(field.animation_sin) * 180/Math.PI : 180.0 - Math.asin(field.animation_sin) * 180/Math.PI
            radius: 10
            border.width: 10
            border.color: (field.isAnimation) ? "#fffef9" : "#ccccd6"
            z: 1
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

    Rectangle {
        id: rect_turn
        x: field.turn_cube_x
        y: field.turn_cube_y
        width: field.turn_cube_width
        height: field.turn_cube_height
        color: "transparent"
        border.color: field.ai_turn ? "#0eb0c9" : "#d2357d"
        border.width: field.turn_width
    }

    Text {
        id: text_turn
        text: field.ai_turn ? "AI_TURN" : "YOUR_TURN"
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel
        color: field.ai_turn ? "#0eb0c9" : "#d2357d"
        x: field.turn_cube_x + field.turn_text_width
        y: field.turn_cube_y + field.turn_text_height
    }

    Rectangle {
        id: rect_time
        x: field.time_cube_x
        y: field.time_cube_y
        width: field.time_cube_width
        height: field.time_cube_height
        color: "transparent"
        border.color: "#fffef9"
        border.width: field.time_width
    }

    Text{
        id: textDateTime
        text: currentDateTime();
        font.family: "Consolas"
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel/2.0
        color: "#fffef9"
        x: field.time_cube_x + field.time_text_width - field.time_delte
        y: field.time_cube_y + field.time_text_height
    }

    Rectangle {
        id: rect_vision_board
        x: field.vision_cube_x
        y: field.vision_cube_y
        width: field.vision_cube_width
        height: field.vision_cube_height
        color: "transparent"
        border.color: field.is_endgame_show ? "transparent" : (field.is_vision_board_show ? "#7a7374" : "#f9d770")
        border.width: field.vision_width
    }

    Text{
        id: text_vision_board
        text: field.is_endgame_show ? "" : (field.is_vision_board_show ? "Vision Detecting ..." : " Vision Board Done! ")
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel * 0.75
        color: field.is_vision_board_show ? "#7a7374" : "#983680"
        x: field.vision_cube_x + field.vision_text_width
        y: field.vision_cube_y + field.vision_text_height
    }

    Rectangle {
        id: strategy_vision_board
        x: field.strategy_cube_x
        y: field.strategy_cube_y
        width: field.strategy_cube_width
        height: field.strategy_cube_height
        color: "transparent"
        border.color: field.is_strategy_show ? "transparent" : "#d9b750"
        border.width: field.strategy_width
    }

    Text{
        id: text_strategy_board
        text: field.is_strategy_show ? "" : currentStrategyMode()
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel
        color: "#d9b750"
        x: field.strategy_cube_x + field.strategy_text_width
        y: field.strategy_cube_y + field.strategy_text_height
    }

    function currentStrategyMode() {
        switch (field.strategy_mode) {
            case 0: return "    梅    花    譜   ";
            case 1: return "    桔    中    秘   ";
            case 2: return "  梦   入   神   机  ";
            case 3: return "    湖    涯    集   ";
            case 4: return "  韬   略   元   机  ";
            case 5: return "  渊   深   海   阔  ";
            case 6: return "  锦   秘   豹   略  ";
            default: return "invalid strategy";
        }
    }

//    MeiHuaPu, // index = 0
//    JuZhongMi,
//    MengRuShenJi,
//    HuYaJi,
//    TaoLueYuanJi,
//    YuanShenHaiKuo

    function currentDateTime(){
        return Qt.formatDateTime(new Date(), " yyyy-MM-dd hh:mm:ss:zzz");
    }

    Timer{
        id: timer
        interval: 1
        repeat: true
        onTriggered:{
            textDateTime.text = currentDateTime();
        }
    }

    Component.onCompleted: {
        timer.start();
    }

/*  Rectangle {
        // use for test
        id: rect2
        x: field.cubeSizeWidth/2.0
        y: field.cubeSizeHeight/2.0
        width: field.cubeSizeWidth
        height: field.cubeSizeHeight
        color: "transparent"
        border.color: "#fffef9"
        border.width: field.chessBoardWidth
    }*/

    Repeater {
        model: 8
        Rectangle{
            width: field.cubeSizeWidth
            height: field.cubeSizeHeight
            // anchors.top: parent
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
            // anchors.top: parent
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
            // anchors.top: parent
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
            // anchors.top: parent
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
            // anchors.top: parent
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
            // anchors.top: parent
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
            // anchors.top: parent
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
            // anchors.top: parent
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

    Text {
        id: text_rule
        text: "Human <Red> \nPlay chess by clicking icon\n\nA I <Black> \nFully automatically !"
        font.family: "Consolas"
        font.styleName: ""
        rotation: 0
        font.pixelSize: field.rule_text_size
        color: "#fffef9"
        x: field.rule_text_x
        y: field.rule_text_y
    }

    Text {
        id: black_win
        text: field.isBlackWin ? " AI \nWin!" : ""
        font.family: "Consolas"
        font.styleName: ""
        rotation: 0
        font.pixelSize: field.textSizeInPixel * 2
        color: "#0eb0c9"
        x: field.win_text_x + field.cubeSizeWidth*0.5
        y: field.win_text_y
    }

    Text {
        id: red_win
        text: field.isRedWin ? "Human\n Win!" : ""
        font.family: "Consolas"
        font.styleName: ""
        rotation: 0
        font.pixelSize: field.textSizeInPixel * 2
        color: "#d2357d"
        x: field.win_text_x
        y: field.win_text_y
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
            ctx.fillText("Copyright: LI Haodong, ZHOU Jin, XU Xiayan, 2021.     Description: Stimulation platform of SRTP-SmartChessRobot by LI     URL: https://github.com/LeBronLiHD/chessRobotSimulation_QT     Information: ---< CIMC Final >-----< 2021.11 >-----< HuZhou, Zhejiang province of China >-----< All Rights Reserved >--- ", field.copyrightX, field.copyrightY)
            ctx.strokeStyle = "#fffef9"
            ctx.stroke()
            // ctx.endPath()
        }

    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            field.lastMousePosX = mouseX
            field.lastMousePosY = mouseY
//            console.log("MouseX -> ", mouseX, "   MouseY -> ", mouseY)
//            console.log("lastMousePosX -> ", field.lastMousePosX, "   lastMousePosY -> ", field.lastMousePosY)
        }
    }

    Rectangle {
            // use for test
            id: rect_select
            x: field.selectChessX + field.chessSize/2.0 - field.selectChessSize/2.0
            y: field.selectChessY + field.chessSize/2.0 - field.selectChessSize/2.0
            width: field.selectChessSize
            height: field.selectChessSize
            color: "transparent"
            border.color: field.selectChessShow ? "#81d8d0" : "transparent"
            border.width: field.selectChessWidth
        }

    Repeater {
        model: field.modelOneRepeat
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
        model: field.modelOneRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelTwoRepeat
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
        model: field.modelFiveRepeat
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
        model: field.modelFiveRepeat
        Image {
            id: rs
            source: "../chess/red_Soldier.svg"
            width: field.chessSize
            height: width
            x: field.cubeSizeWidth * 6.5 - width/2.0
            y: field.cubeSizeHeight*(0.5 + index * 2) - height/2.0
        }
    }

    Image {
        id: b_gen
        source: (field.showInitCHessBoardSingle == true && field.b_gen_1_alive) ? "../chess/black_General.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_gen_1_posX
        y: field.b_gen_1_posY
    }
    Image {
        id: r_gen
        source: (field.showInitCHessBoardSingle == true && field.r_gen_1_alive) ? "../chess/red_General.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_gen_1_posX
        y: field.r_gen_1_posY
    }
    Image {
        id: b_adv_1
        source: (field.showInitCHessBoardSingle == true && field.b_adv_1_alive) ? "../chess/black_Advisor.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_adv_1_posX
        y: field.b_adv_1_posY
    }
    Image {
        id: r_adv_1
        source: (field.showInitCHessBoardSingle == true && field.r_adv_1_alive) ? "../chess/red_Advisor.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_adv_1_posX
        y: field.r_adv_1_posY
    }
    Image {
        id: b_adv_2
        source: (field.showInitCHessBoardSingle == true && field.b_adv_2_alive) ? "../chess/black_Advisor.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_adv_2_posX
        y: field.b_adv_2_posY
    }
    Image {
        id: r_adv_2
        source: (field.showInitCHessBoardSingle == true && field.r_adv_2_alive) ? "../chess/red_Advisor.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_adv_2_posX
        y: field.r_adv_2_posY
    }
    Image {
        id: b_ele_1
        source: (field.showInitCHessBoardSingle == true && field.b_ele_1_alive) ? "../chess/black_Elephant.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_ele_1_posX
        y: field.b_ele_1_posY
    }
    Image {
        id: r_ele_1
        source: (field.showInitCHessBoardSingle == true && field.r_ele_1_alive) ? "../chess/red_Elephant.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_ele_1_posX
        y: field.r_ele_1_posY
    }
    Image {
        id: b_ele_2
        source: (field.showInitCHessBoardSingle == true && field.b_ele_2_alive) ? "../chess/black_Elephant.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_ele_2_posX
        y: field.b_ele_2_posY
    }
    Image {
        id: r_ele_2
        source: (field.showInitCHessBoardSingle == true && field.r_ele_2_alive) ? "../chess/red_Elephant.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_ele_2_posX
        y: field.r_ele_2_posY
    }
    Image {
        id: b_hor_1
        source: (field.showInitCHessBoardSingle == true && field.b_hor_1_alive) ? "../chess/black_Horse.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_hor_1_posX
        y: field.b_hor_1_posY
    }
    Image {
        id: r_hor_1
        source: (field.showInitCHessBoardSingle == true && field.r_hor_1_alive) ? "../chess/red_Horse.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_hor_1_posX
        y: field.r_hor_1_posY
    }
    Image {
        id: b_hor_2
        source: (field.showInitCHessBoardSingle == true && field.b_hor_2_alive) ? "../chess/black_Horse.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_hor_2_posX
        y: field.b_hor_2_posY
    }
    Image {
        id: r_hor_2
        source: (field.showInitCHessBoardSingle == true && field.r_hor_2_alive) ? "../chess/red_Horse.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_hor_2_posX
        y: field.r_hor_2_posY
    }
    Image {
        id: b_cha_1
        source: (field.showInitCHessBoardSingle == true && field.b_cha_1_alive) ? "../chess/black_Chariot.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_cha_1_posX
        y: field.b_cha_1_posY
    }
    Image {
        id: r_cha_1
        source: (field.showInitCHessBoardSingle == true && field.r_cha_1_alive) ? "../chess/red_Chariot.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_cha_1_posX
        y: field.r_cha_1_posY
    }
    Image {
        id: b_cha_2
        source: (field.showInitCHessBoardSingle == true && field.b_cha_2_alive) ? "../chess/black_Chariot.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_cha_2_posX
        y: field.b_cha_2_posY
    }
    Image {
        id: r_cha_2
        source: (field.showInitCHessBoardSingle == true && field.r_cha_2_alive) ? "../chess/red_Chariot.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_cha_2_posX
        y: field.r_cha_2_posY
    }
    Image {
        id: b_can_1
        source: (field.showInitCHessBoardSingle == true && field.b_can_1_alive) ? "../chess/black_Cannon.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_can_1_posX
        y: field.b_can_1_posY
    }
    Image {
        id: r_can_1
        source: (field.showInitCHessBoardSingle == true && field.r_can_1_alive) ? "../chess/red_Cannon.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_can_1_posX
        y: field.r_can_1_posY
    }
    Image {
        id: b_can_2
        source: (field.showInitCHessBoardSingle == true && field.b_can_2_alive) ? "../chess/black_Cannon.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_can_2_posX
        y: field.b_can_2_posY
    }
    Image {
        id: r_can_2
        source: (field.showInitCHessBoardSingle == true && field.r_can_2_alive) ? "../chess/red_Cannon.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_can_2_posX
        y: field.r_can_2_posY
    }

    Image {
        id: b_sol_1
        source: (field.showInitCHessBoardSingle == true && field.b_sol_1_alive) ? "../chess/black_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_sol_1_posX
        y: field.b_sol_1_posY
    }
    Image {
        id: r_sol_1
        source: (field.showInitCHessBoardSingle == true && field.r_sol_1_alive) ? "../chess/red_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_sol_1_posX
        y: field.r_sol_1_posY
    }
    Image {
        id: b_sol_2
        source: (field.showInitCHessBoardSingle == true && field.b_sol_2_alive) ? "../chess/black_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_sol_2_posX
        y: field.b_sol_2_posY
    }
    Image {
        id: r_sol_2
        source: (field.showInitCHessBoardSingle == true && field.r_sol_2_alive) ? "../chess/red_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_sol_2_posX
        y: field.r_sol_2_posY
    }
    Image {
        id: b_sol_3
        source: (field.showInitCHessBoardSingle == true && field.b_sol_3_alive) ? "../chess/black_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_sol_3_posX
        y: field.b_sol_3_posY
    }
    Image {
        id: r_sol_3
        source: (field.showInitCHessBoardSingle == true && field.r_sol_3_alive) ? "../chess/red_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_sol_3_posX
        y: field.r_sol_3_posY
    }
    Image {
        id: b_sol_4
        source: (field.showInitCHessBoardSingle == true && field.b_sol_4_alive) ? "../chess/black_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_sol_4_posX
        y: field.b_sol_4_posY
    }
    Image {
        id: r_sol_4
        source: (field.showInitCHessBoardSingle == true && field.r_sol_4_alive) ? "../chess/red_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_sol_4_posX
        y: field.r_sol_4_posY
    }
    Image {
        id: b_sol_5
        source: (field.showInitCHessBoardSingle == true && field.b_sol_5_alive) ? "../chess/black_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.b_sol_5_posX
        y: field.b_sol_5_posY
    }
    Image {
        id: r_sol_5
        source: (field.showInitCHessBoardSingle == true && field.r_sol_5_alive) ? "../chess/red_Soldier.svg" : ""
        width: field.chessSize
        height: width
        x: field.r_sol_5_posX
        y: field.r_sol_5_posY
    }

}
