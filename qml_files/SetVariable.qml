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
            text: qsTr("修改 m_strName：")
            verticalAlignment: Text.AlignVCenter
        }


        TextField {
            width: 120; height: 25

            text: "悟空"
            background: Rectangle{
                color: "#FFE0E0"
                border.color: "black"
            }
            onTextChanged: { InitSetUp.name = text }
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
