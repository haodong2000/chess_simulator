import QtQuick 2.14
import QtQuick.Controls 2.14

Rectangle {
    id: root
    width: 260; height: 100
    border.color: "gray"

    Grid {
        id: layout
        columns: 2
        spacing: 5
        anchors.centerIn: root

        // 修改InitSetUp 的 m_strName 属性
        Text {
            width: 100; height: 25
            text: qsTr("修改 m_strDifficulty：")
            verticalAlignment: Text.AlignVCenter
        }


        TextField {
            width: 120; height: 25

            text: "TestDifficulty"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }
            onTextChanged: { InitSetUp.difficulty = text }
        }

        // 修改InitSetUp 的 m_strName 属性
        Text {
            width: 100; height: 25
            text: qsTr("修改 m_strMode：")
            verticalAlignment: Text.AlignVCenter
        }


        TextField {
            width: 120; height: 25

            text: "TestMode"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }
            onTextChanged: { InitSetUp.mode = text }
        }

        // 修改InitSetUp 的 m_strName 属性
        Text {
            width: 100; height: 25
            text: qsTr("修改 m_strEnd：")
            verticalAlignment: Text.AlignVCenter
        }


        TextField {
            width: 120; height: 25

            text: "TestEnd"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }
            onTextChanged: { InitSetUp.end = text }
        }

        // 修改InitSetUp 的 m_strName 属性
        Text {
            width: 100; height: 25
            text: qsTr("修改 m_strManual：")
            verticalAlignment: Text.AlignVCenter
        }


        TextField {
            width: 120; height: 25

            text: "TestManual"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }
            onTextChanged: { InitSetUp.manual = text }
        }

        Text {
            width: 100; height: 25
            text: qsTr("修改 m_strBack：")
            verticalAlignment: Text.AlignVCenter
        }


        TextField {
            width: 120; height: 25

            text: "TestBack"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }
            onTextChanged: { InitSetUp.back = text }
        }


        // 修改InitSetUp 的 m_nAge 属性
        Text {
            width: 100; height: 25
            text: qsTr("修改 m_nAge：")
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            width: 120; height: 25
            text: "18"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }

            onTextChanged: {
                var age = Number(text)
                if(isNaN(age))
                    log.text = "m_aAge 数值无效 ..."
                else{
                    InitSetUp.age = age
                    log.text = "这里显示错误信息"
                }
            }
        }
    }
}
