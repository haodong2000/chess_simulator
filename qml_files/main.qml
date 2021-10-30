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
import QtQuick.Controls 2.14
import QtQuick.Window 2.14
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
        property int vision_cube_y: turn_cube_y * 2.0 - 10
        property int vision_cube_width: turn_cube_width
        property int vision_cube_height: turn_cube_height * 0.75 + 10
        property int vision_text_width: vision_cube_width/15.0
        property int vision_text_height: vision_cube_height/4.5 + 10
        property int vision_width: turn_width * 0.75

        property bool is_strategy_mode: false
        property bool is_strategy_show: !is_strategy_mode
        property int strategy_mode: 0
        property int strategy_cube_x: turn_cube_x
        property int strategy_cube_y: turn_cube_y * 2.0 - 15
        property int strategy_cube_width: turn_cube_width
        property int strategy_cube_height: turn_cube_height * 0.75 + 10
        property int strategy_text_width: vision_cube_width/15.0
        property int strategy_text_height: vision_cube_height/27.5 + 10
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
        property var selectChessWidth: turn_width/1.5

        property bool selectChessShow: true

        property bool isBackgroundSet: false
        property bool isBackgroundText: true
        property string background_source: "../background/ChristmasTree.jpg"

        property double background_text_posX: cubeSizeWidth * 0.5
        property double background_text_posY: cubeSizeHeight * 1.0
        property int background_text_size: 350

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

        property bool killedChessDisplay: false
        property double killedChessDisplay_x_www: turn_cube_x
        property double killedChessDisplay_y_www: turn_cube_y * 4.75
        property double killedChessDisplay_x: turn_cube_x + cubeSizeWidth * 1.5
        property double killedChessDisplay_y: killedChessDisplay_y_www
        property double killedChessDisplay_x_text: turn_cube_x + cubeSizeWidth
        property double killedChessDisplay_y_text: killedChessDisplay_y_www
        property string killer: "../chess/red_General.svg"
        property string killed: "../chess/red_General.svg"

        property bool initEnvironmentDone: false
        property bool initWindowShow: ! initEnvironmentDone
        property int initWindowDelta: cubeSizeWidth * 0.5
        property int initWindowWidth: cubeSizeWidth * 3.7
        property int initWindowHeight: cubeSizeHeight * 3.5

        property bool infomationDone: false
        property bool infomationShow: ! infomationDone

        property bool isEnglishOrChinese: true

        property bool isPlayEvaluateShow: false
        property int playerEvaluateLevel: 1
        property string playerEvaluateScore: "playerEvaluateScore"
    }

    Text {
        id: player_evaluate
        text: field.isPlayEvaluateShow ? playerEvaluateText(field.playerEvaluateLevel) : ""
        font.family: "Consolas"
        font.bold: true
        font.styleName: ""
        rotation: 0
        font.pixelSize: field.textSizeInPixel * 0.65
        color: field.isBlackWin ? "#d2357d" : "#0eb0c9"
        x: field.cubeSizeWidth * 2.5
        y: field.cubeSizeHeight * 5.75
        z: 2
    }

    function playerEvaluateText(level) {
        switch(level) {
        case 1:
            return "建议难度(Recommended Difficulty)\n=====> Simple-Level"
        case 2:
            return "建议难度(Recommended Difficulty)\n=====> Middle-Level"
        case 3:
            return "建议难度(Recommended Difficulty)\n=====> Hard-Level"
        default:
            console.log("Error: main.qml line:325 playerEvaluateText() level invalid!")
        }
    }

    Text {
        id: player_evaluate_score
        text: field.isPlayEvaluateShow ? "能力评估" + field.playerEvaluateScore : ""
        font.family: "Consolas"
        font.bold: true
        font.styleName: ""
        rotation: 0
        font.pixelSize: field.textSizeInPixel * 0.65
        color: field.isBlackWin ? "#d2357d" : "#0eb0c9"
        x: field.cubeSizeWidth * 2.5
        y: field.cubeSizeHeight * 4.75
        z: 2
    }

    Row {
        x: field.cubeSizeWidth * 8.0
        y: field.cubeSizeHeight * 5.0
        z: (field.isPlayEvaluateShow) ? 3 : -4
        spacing: field.initWindowDelta * 0.75

        Button {
            id: end_game
            width: (field.isPlayEvaluateShow) ? (field.initWindowWidth * 0.75) : 0
            height: (field.isPlayEvaluateShow) ? (width * 0.618 * 0.5) : 0
            highlighted: true
            text: "退出游戏\n(Exit the Game)"
            background: Rectangle {
                color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#29b7cb" : "#c06f98")
                opacity: 0.75
                radius: 50
                border.width: radius
                border.color: color
            }
            font.family: "Consolas"
            font.pixelSize: field.textSizeInPixel * 0.5
            onClicked: InitSetUp.exitGameFunc()
        }
    }

    Repeater {
        model: 2
        Rectangle{
            width: field.initWindowWidth * 0.75 * 2 + field.initWindowDelta * 0.75
            height: field.initWindowHeight + field.cubeSizeHeight * 0.5
            x: field.initWindowDelta * (index + 1.0) * 0.75 + index * width
            y: field.cubeSizeHeight * 2.5
            color: "#22202e"
            opacity: 0.75
            z: (field.infomationShow) ? 7 : -4
            id: rect_win_info
            radius: 50
            border.width: 50
            border.color: "#22202e"
        }
    }

    Repeater {
        model: 2
        Text{
            x: (field.initWindowDelta * index * 0.75 + index * field.initWindowWidth + field.initWindowWidth * 0.5 - 200) * 0.75 * 2
            y: field.cubeSizeHeight * 2.6
            color: "#fffef9"
            z: (field.infomationShow) ? 8 : -4
            id: text_win_info
            font.family: "Consolas"
            font.bold: false
            opacity: 0.95
            rotation: 0
            font.pixelSize: field.textSizeInPixel * 0.4
            text: currentInformation(index)
        }
    }

    function currentInformation(idx) {
        switch(idx) {
        case 0:
            return "模式 (Mode)
1 -> AI_AI -----------------> AI与AI对弈(软件仿真)
2 -> Human_AI --------------> 人类与AI对弈(软件仿真)
3 -> Human_Human -----------> 人类与人类对弈(软件仿真)
4 -> Human_AI_CIMC ---------> 人类与AI对弈(机械臂+视觉实机下棋)
5 -> Human_AI_CIMC_EndGame -> 人类与AI残局对弈(机械臂+视觉实机下棋)
6 -> AI_AI_EndGame ---------> AI与AI残局对弈(软件仿真)
7 -> Human_AI --------------> 人类与AI残局对弈(软件仿真)
8 -> Human_Human -----------> 人类与人类残局对弈(软件仿真)

难度 (Difficulty)
1 -> Simple-Level ----------> 初级水平
2 -> Middle-Level ----------> 中级水平
3 -> Hard-Level ------------> 进阶水平
"
        case 1:
            return "残局 (Endgame)                   \t棋谱 (Chess Manual)
0 -> EndGame_Mode ----> 残局模式\t1 -> Mei Hua Pu --------> 梅花譜
1 -> FullGame_Mode ---> 全局模式\t2 -> Ju Zhong Mi -------> 橘中秘
                              \t3 -> Meng Ru Shen Ji ---> 梦入神机
外观(Background)               \t4 -> Hu Ya Ji ----------> 湖涯集
0 -> Picture_Mode ----> 自然风光\t5 -> Tao Lue Yuan Ji ---> 韬略元机
1 -> Light_Gray_Mode -> 淡雅灰色\t6 -> Yuan Shen Hai Kuo -> 渊深海阔
                               \t7 -> Mi Jin Bao Lue ----> 锦秘豹略
                               \t8 -> Empty Manual ------> 空(全局模式)
"
        default:
            console.log("Error: main.qml line:338 currentInformation() idx invalid!")
        }
    }

    Repeater {
        model: 2
        Text {
            id: text_info_head
            text: currentInfoHeadText(index)
            font.family: "Consolas"
            opacity: 0.75
            font.styleName: ""
            font.pixelSize: field.background_text_size * 0.15
            font.bold: false
            color: "#fffef9"
            x: field.background_text_posX * 4.5
            y: field.background_text_posY * 0.3 * (index * 3.0 + 1.0)
            z: (field.infomationShow) ? 7 : -4
        }
    }

    function currentInfoHeadText(idx) {
        switch(idx) {
        case 0:
            return "        智能象棋机器人用户使用说明"
        case 1:
            return "User Instructions for Smart Chess Robot"
        default:
            console.log("Error: main.qml line:368 currentInfoHeadText() idx invalid!")
        }
    }

    Row {
        x: (field.initWindowDelta * (1.0 + 0.1) + 1.0 * field.initWindowWidth + field.initWindowWidth * 0.5 - 150) * 0.75 - 50 * 0.75
        y: field.cubeSizeHeight * 3.0 + field.initWindowHeight + 50
        z: (field.infomationShow) ? 6 : -4
        spacing: field.initWindowDelta * 0.75

        Button {
            id: btn01_info
            width: (field.infomationShow) ? (field.initWindowWidth * 0.75) : 0
            height: (field.infomationShow) ? (width * 0.618 * 0.5) : 0
            highlighted: true
            text: "退出游戏\n(Exit the Game)"
            background: Rectangle {
                color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#29b7cb" : "#c06f98")
                opacity: 0.75
                radius: 50
                border.width: radius
                border.color: color
            }
            font.family: "Consolas"
            font.pixelSize: field.textSizeInPixel * 0.5
            onClicked: InitSetUp.exitGameFunc()
        }
        Button {
            id: btn02_info
            width: (field.infomationShow) ? (field.initWindowWidth * 0.75) : 0
            height: (field.infomationShow) ? (width * 0.618 * 0.5) : 0
            highlighted: true
            background: Rectangle {
                color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#29b7cb" : "#c06f98")
                opacity: 0.75
                radius: 50
                border.width: radius
                border.color: color
            }
            text: "我已知晓\n(I Understand)"
            font.pixelSize: field.textSizeInPixel * 0.5
            font.family: "Consolas"
            onClicked: InitSetUp.exitInfoFunc()
        }
    }

    Repeater {
        model: 4
        Rectangle{
            width: field.initWindowWidth * 0.75
            height: field.initWindowHeight
            x: field.initWindowDelta * (index + 1.0) * 0.75 + index * width
            y: field.cubeSizeHeight * 3.0
            color: "#22202e"
            opacity: 0.75
            z: (field.initWindowShow) ? 4 : -4
            id: rect_win_init
            radius: 50
            border.width: 50
            border.color: "#22202e"
        }
    }

    Repeater {
        model: 4
        Text{
            x: (field.initWindowDelta * (index + 0.1) + index * field.initWindowWidth + field.initWindowWidth * 0.5 - 150) * 0.75
            y: field.cubeSizeHeight * 3.0
            color: "#fffef9"
            z: (field.initWindowShow) ? 4 : -4
            id: text_win_init
            font.family: "Consolas"
            font.bold: false
            opacity: 0.95
            rotation: 0
            font.pixelSize: field.textSizeInPixel * 0.5
            text: currentInitMode(index)
        }
    }

    Repeater {
        model: 4
        Text{
            x: (field.initWindowDelta * (index + 0.1) + index * field.initWindowWidth + field.initWindowWidth * 0.5 - 150) * 0.75
            y: field.cubeSizeHeight * 6.0
            color: "#fffef9"
            z: (field.initWindowShow) ? 4 : -4
            id: text_info_init
            font.family: "Consolas"
            font.bold: false
            opacity: 0.95
            rotation: 0
            font.pixelSize: 19
            text: currentInitModeInfo(index)
        }
    }

    Repeater {
        model: 4
        Text{
            x: (field.initWindowDelta * (index + 0.1) + index * field.initWindowWidth + field.initWindowWidth * 0.5 - 150) * 0.75
            y: field.cubeSizeHeight * 4.0
            color: "#fffef9"
            z: (field.initWindowShow) ? 4 : -4
            id: text_input_init
            font.family: "Consolas"
            font.bold: false
            opacity: 0.95
            rotation: 0
            font.pixelSize: 19
            text: currentInitModeInput(index)
        }
    }

    Repeater {
        model: 4
        Text{
            x: (field.initWindowDelta * (index + 0.1) + index * field.initWindowWidth + field.initWindowWidth * 0.5 - 150) * 0.75
            y: field.cubeSizeHeight * 5.0
            color: "#fffef9"
            z: (field.initWindowShow) ? 4 : -4
            id: text_enter_init
            font.family: "Consolas"
            font.bold: false
            opacity: 0.95
            rotation: 0
            font.pixelSize: 19
            text: currentInitModeEnter(index)
        }
    }

    function currentInitMode(idx) {
        switch(idx) {
        case 0: return "      模式(Mode)"
        case 1: return "   难度(Difficulty)"
        case 2: return "       残局&棋谱\n(Endgame&Chess Manual)"
        case 3: return "   外观(Background)"
        default: return console.log("Error: main.qml line:334 idx invalid!")
        }
    }

    function currentInitModeInfo(idx) {
        switch(idx) {
        case 0: return "请输入(Please Enter): 1~8"
        case 1: return "请输入(Please Enter): 1~3"
        case 2: return "请输入(Please Enter): \n0~1(Endgame), 1~8(Manual)"
        case 3: return "请输入(Please Enter): 0~1"
        default: return console.log("Error: main.qml line:334 idx invalid!")
        }
    }

    function currentInitModeInput(idx) {
        switch(idx) {
        case 0: return "Mode: "
        case 1: return "Difficulty: "
        case 2: return "Endgame: \n\nManual: "
        case 3: return "Background: "
        default: return console.log("Error: main.qml line:334 idx invalid!")
        }
    }

    function currentInitModeEnter(idx) {
        switch(idx) {
        case 0: return "Input: "
        case 1: return "Input: "
        case 2: return "Input(E): \n\nInput(M): "
        case 3: return "Input: "
        default: return console.log("Error: main.qml line:334 idx invalid!")
        }
    }

    Row {
        x: field.initWindowDelta + 100
        y: field.cubeSizeHeight * 4.0 - 25
        z: (field.initWindowShow) ? 4 : -4
        spacing: field.initWindowDelta * 3.70

        MyLabel {
            width: field.cubeSizeWidth * 1.75
            id: modeLabel
        }
        MyLabel {
            id: difficultyLabel
        }
    }

    Column {
        x: field.cubeSizeWidth * 7.75
        y: field.cubeSizeHeight * 4.0 - 10
        z: (field.initWindowShow) ? 4 : -4
        spacing: field.initWindowDelta * 0.2
        MyLabel {
            height: Screen.height/30.0
            id: endLabel
        }
        MyLabel {
            height: Screen.height/30.0
            id: manualLabel
        }
    }

    Row {
        x: field.cubeSizeWidth * 7.75 + field.initWindowDelta * 4.0 + Screen.width/10.0
        y: field.cubeSizeHeight * 4.0 - 25
        z: (field.initWindowShow) ? 4 : -4
        spacing: field.initWindowDelta * 4.0
        MyLabel {
            id: backLabel
        }
        MyLabel {
            id: timeLabel
        }
    }

    Row {
        x: Screen.width/2.0 - 300
        y: field.cubeSizeHeight * 8.75
        z: (field.initWindowShow) ? 8 : -4
        spacing: field.initWindowDelta * 0.75
        Text {
            id: init_copyright
            text: qsTr("Copyright: Smart Chess Robot 2021.")
            font.pixelSize: 12
            font.family: "Consolas"
            color: "#fffef9"
        }
        Text {
            id: init_copyright_time
            text: timeLabel.text
            font.pixelSize: 12
            font.family: "Consolas"
            color: "#fffef9"
        }
    }

    Row {
        x: (field.initWindowDelta * (1.0 + 0.1) + 1.0 * field.initWindowWidth + field.initWindowWidth * 0.5 - 150) * 0.75 - 50 * 0.75
        y: field.cubeSizeHeight * 3.0 + field.initWindowHeight + 50
        z: (field.initWindowShow) ? 4 : -4
        spacing: field.initWindowDelta * 0.75

        Button {
            id: btn01_init
            width: (field.initWindowShow) ? (field.initWindowWidth * 0.75) : 0
            height: (field.initWindowShow) ? (width * 0.618 * 0.5) : 0
            highlighted: true
            text: "退出游戏\n(Exit the Game)"
            background: Rectangle {
                color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#29b7cb" : "#c06f98")
                opacity: 0.75
                radius: 50
                border.width: radius
                border.color: color
            }
            font.family: "Consolas"
            font.pixelSize: field.textSizeInPixel * 0.5
            onClicked: InitSetUp.exitGameFunc()
        }
        Button {
            id: btn02_init
            width: (field.initWindowShow) ? (field.initWindowWidth * 0.75) : 0
            height: (field.initWindowShow) ? (width * 0.618 * 0.5) : 0
            highlighted: true
            background: Rectangle {
                color: parent.down ? "#bbbbbb" :
                        (parent.hovered ? "#29b7cb" : "#c06f98")
                opacity: 0.75
                radius: 50
                border.width: radius
                border.color: color
            }
            text: "开始游戏\n(Start the Game)"
            font.pixelSize: field.textSizeInPixel * 0.5
            font.family: "Consolas"
            onClicked: InitSetUp.startGameFunc()
        }
    }

    function refreshCurrentTime(strTime){
        timeLabel.text = strTime
    }

    function changeDifficulty(){
        difficultyLabel.text = currentDifficulty()
    }

    function currentDifficulty() {
        switch(InitSetUp.difficulty) {
        case "1":
            InitSetUp.int_difficulty = Number(InitSetUp.difficulty)
            return "Simple-Level"
        case "2":
            InitSetUp.int_difficulty = Number(InitSetUp.difficulty)
            return "Middle-Level"
        case "3":
            InitSetUp.int_difficulty = Number(InitSetUp.difficulty)
            return "Hard-Level"
        default: return "InValid! 1~3!"
        }
    }

    function changeMode(){
        modeLabel.text = currentMode()
    }

    function currentMode() {
        switch(InitSetUp.mode) {
        case "1":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "AI_AI"
        case "2":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "Human_AI"
        case "3":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "Human_Human"
        case "4":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "Human_AI_CIMC"
        case "5":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "Human_AI_CIMC_EndGame"
        case "6":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "AI_AI_EndGame"
        case "7":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "Human_AI_EndGame"
        case "8":
            InitSetUp.int_mode = Number(InitSetUp.mode)
            return "Human_Human_EndGame"
        default: return "InValid! 1~8!"
        }
    }

    function changeEnd(){
        endLabel.text = currentEnd()
    }

    function currentEnd() {
        switch(InitSetUp.end) {
        case "1":
            InitSetUp.int_end = Number(InitSetUp.end)
            return "EndGame_Mode"
        case "0":
            InitSetUp.int_end = Number(InitSetUp.end)
            return "FullGame_Mode"
        default: return "InValid! 0~1!"
        }
    }

    function changeManual(){
        manualLabel.text = currentManual()
    }

    function currentManual() {
        switch(InitSetUp.manual) {
        case "1":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Mei Hua Pu"
        case "2":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Ju Zhong Mi"
        case "3":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Meng Ru Shen Ji"
        case "4":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Hu Ya Ji"
        case "5":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Tao Lue Yuan Ji"
        case "6":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Yuan Shen Hai Kuo"
        case "7":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Mi Jin Bao Lue"
        case "8":
            InitSetUp.int_manual = Number(InitSetUp.manual)
            return "Empty Manual"
        default: return "InValid! 1~8!"
        }
    }

    function changeBack(){
        backLabel.text = currentBack()
    }

    function currentBack() {
        switch(InitSetUp.back) {
        case "1":
            InitSetUp.int_back = Number(InitSetUp.back)
            return "Picture_Mode"
        case "0":
            InitSetUp.int_back = Number(InitSetUp.back)
            return "Light_Gray_Mode"
        default: return "InValid! 0~1!"
        }
    }

    Component.onCompleted: {
        InitSetUp.refreshTime.connect(refreshCurrentTime)
        InitSetUp.onDifficultyChanged.connect(changeDifficulty)
//        InitSetUp.onAgeChanged.connect(changeAge)
        InitSetUp.onModeChanged.connect(changeMode)
        InitSetUp.onEndChanged.connect(changeEnd)
        InitSetUp.onManualChanged.connect(changeManual)
        InitSetUp.onBackChanged.connect(changeBack)

        difficultyLabel.text = qsTr(InitSetUp.difficulty)
        modeLabel.text = qsTr(InitSetUp.mode)
        endLabel.text = qsTr(InitSetUp.end)
        backLabel.text = qsTr(InitSetUp.back)
        manualLabel.text = qsTr(InitSetUp.manual)
//        ageLabel.text = qsTr(String(InitSetUp.age))
        timer_qml.start()
    }

    SetVariable{
        id: testInfo
        z: (field.initWindowShow) ? 4 : -4
    }

    Rectangle {
        id: init_background
        x: 0
        y: 0
        width: Screen.width
        height: Screen.height
        color: "#fffef9"
        opacity: 0.25
        z: field.infomationShow ? 6 : ((field.initWindowShow) ? 3 : -4)
    }
    Image {
        id: init_background_image
        source: (field.initWindowShow) ? field.background_source : ""
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        z: field.infomationShow ? 5 : ((field.initWindowShow) ? 2 : -4)
    }
    Text {
        id: text_init_background_welcome
        text: "Welcome to the Startup Settings of"
        font.family: "Consolas"
        opacity: 0.75
        font.styleName: ""
        font.pixelSize: field.background_text_size * 0.1
        font.bold: false
        color: "#fffef9"
        x: field.background_text_posX * 7.7
        y: field.background_text_posY * 0.4
        z: (field.initWindowShow) ? 3 : -4
    }
    Text {
        id: text_init_background
        text: "Smart Chess Robot"
        font.family: "Consolas"
        opacity: 0.875
        font.styleName: ""
        font.pixelSize: field.background_text_size * 0.475
        font.bold: true
        SequentialAnimation on color {
            loops: Animation.Infinite
            ColorAnimation {
                from: "#29b7cb"
                to: "#c06f98"
                duration: 2000 }
            ColorAnimation {
                from: "#c06f98"
                to: "#29b7cb"
                duration: 2000 }
        }
        x: field.background_text_posX
        y: field.background_text_posY
        z: (field.initWindowShow) ? 3 : -4
    }

    Image {
        id: kill
        source: (field.killedChessDisplay) ? field.killer : ""
        width: field.chessSize
        height: width
        x: field.killedChessDisplay_x_www + field.chessSize * 0.35
        y: field.killedChessDisplay_y_www - field.chessSize * 0.25
    }
    Image {
        id: bekilled
        source: (field.killedChessDisplay) ? field.killed : ""
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
        font.pixelSize: field.rule_text_size * 1.5
        font.bold: true
        color: (field.killedChessDisplay) ? "#fffef9" : ""
        x: field.killedChessDisplay_x_text - 5
        y: field.killedChessDisplay_y_text
    }

    Image {
        id: background
        source: (field.isBackgroundSet) ? field.background_source : ""
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
        z: -1
    }
    Rectangle {
        id: background_rect
        x: 0
        y: 0
        width: Screen.width
        height: Screen.height
        color: (field.isBackgroundSet) ? "#fffef9" : "#2f2f35"
        opacity: (field.isBackgroundSet) ? 0.25 : 1.0
        z: -1
    }

    Text {
        id: text_background
        text: "Chess\n   Robot"
        font.family: "Consolas"
        opacity: 0.25
        font.styleName: ""
        font.pixelSize: field.background_text_size
        font.bold: true
        color: (field.isBackgroundText) ? "#fffef9" : ""
        x: field.background_text_posX
        y: field.background_text_posY
        z: -1
    }

    Rectangle {
        id: xiu
        x: field.animation_posX + field.cubeSizeWidth * 0.5 - field.animation_xie * 0.5 - field.chessSize * 0.5 - 10
        y: field.animation_posY + field.cubeSizeHeight * 0.5 - field.chessSize * 0.5 - 10
        width: field.animation_xie + field.chessSize + 20
        height: field.chessSize + 20
        color: (field.isAnimation) ? "#bc84a8" : "#c8adc4"
        opacity: (field.isAnimation) ? 0.5 : 0.25
        rotation: (field.isLeftXie) ? Math.asin(field.animation_sin) * 180/Math.PI : 180.0 - Math.asin(field.animation_sin) * 180/Math.PI
        radius: 10
        border.width: 10
        border.color: (field.isAnimation) ? "#fffef9" : "#fffef9"
        z: -1
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
        y: field.turn_cube_y - 35
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
        y: field.turn_cube_y + field.turn_text_height - 35
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
        border.color: field.is_endgame_show ? "transparent" : (field.is_vision_board_show ? "#20a162" : "#f9d770")
        border.width: field.vision_width
    }

    Text{
        id: text_vision_board
        text: field.is_endgame_show ? "" : (field.is_vision_board_show ? "Vision Detecting ..." : " Vision Board Done! ")
        font.styleName: ""
        font.pixelSize: field.textSizeInPixel * 0.75
        color: field.is_vision_board_show ? "#20a162" : "#f9d770"
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
        x: field.strategy_cube_x + field.strategy_text_width - 8
        y: field.strategy_cube_y + field.strategy_text_height - 8
    }

    function currentStrategyMode() {
        switch (field.strategy_mode) {
            case 0: return "    梅    花    譜   ";
            case 1: return "    橘    中    秘   ";
            case 2: return "  梦   入   神   机  ";
            case 3: return "    湖    涯    集   ";
            case 4: return "  韬   略   元   机  ";
            case 5: return "  渊   深   海   阔  ";
            case 6: return "  锦   秘   豹   略  ";
            case 7: return "invalid strategy";
            default: return "  象   棋   全   局  "
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
        id: timer_qml
        interval: 1
        repeat: true
        onTriggered:{
            textDateTime.text = currentDateTime();
        }
    }

//    Component.onCompleted: {
//        timer_qml.start();
//    }

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
        text: field.isBlackWin ? " AI  Win!" : ""
        font.family: "Consolas"
        font.styleName: ""
        font.bold: false
        rotation: 0
        font.pixelSize: field.textSizeInPixel * 3
        color: "#0eb0c9"
        x: field.cubeSizeWidth * 3.5
        y: field.cubeSizeHeight * 3.0
        z: 2
    }

    Text {
        id: red_win
        text: field.isRedWin ? "Human Win!" : ""
        font.family: "Consolas"
        font.bold: false
        font.styleName: ""
        rotation: 0
        font.pixelSize: field.textSizeInPixel * 3
        color: "#d2357d"
        x: field.cubeSizeWidth * 3.5
        y: field.cubeSizeHeight * 3.0
        z: 2
    }

    Rectangle{
        width: Screen.width
        height: field.cubeSizeHeight * 6
        x: 0
        y: field.cubeSizeHeight * 1.5
        color: field.isBlackWin ? "#22202e" : (field.isRedWin ? "#22202e" : "transparent")
        opacity: field.isBlackWin ? 0.75 : (field.isRedWin ? 0.75 : 0.0)
        z: 1
        id: rect_win
        border.width: 0
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
