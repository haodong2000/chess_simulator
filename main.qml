import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    title: qsTr("Hello World")
    visible: true
    width: 600
    height: 600
    Canvas{
        id:canvas
        width: 300
        height: 300
        anchors.centerIn: parent
        property int j: 0
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0,0,width,height);
            ctx.save();
            ctx.strokeStyle = "#148014";
            ctx.lineWidth = 10
            ctx.strokeRect(0,0,width,height);
            ctx.restore();
            ctx.beginPath();
            ctx.moveTo(0,0);

            for(var i=0;i < width;i+=1)
            {
                ctx.lineTo(i,100+12*Math.sin((i+j)/180*Math.PI));
            }
            ctx.lineTo(width,height);
            ctx.lineTo(0,height);
            ctx.closePath();

            ctx.fillStyle = "green"
            ctx.fill();
        }

        Timer{
            repeat: true
            interval: 20
            running: true
            onTriggered: {
                canvas.j+=5;
                canvas.requestPaint();
            }
        }
    }
}
