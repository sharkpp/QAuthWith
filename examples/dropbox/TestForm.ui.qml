import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Pane {
    id: pane
    width: 400
    height: 400
    topPadding: 6

    Column {
        id: column
        anchors.fill: parent

        Label {
            id: label
            text: qsTr("hogehogehogeho hogehogehogehogehoge hogehogehogehoge hogehogehogegehogehogehoge")
            wrapMode: Text.WrapAnywhere
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Column {
            id: column1
            spacing: 4
            anchors.top: label.bottom
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.topMargin: 0

            Label {
                id: label1
                text: qsTr("Label")
                font.weight: Font.ExtraLight
                font.capitalization: Font.AllUppercase
                renderType: Text.NativeRendering
                anchors.verticalCenterOffset: 2
                anchors.verticalCenter: parent.verticalCenter
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
            }

            Grid {
                id: grid
                spacing: 4
                columns: 3
                anchors.bottomMargin: 0
                anchors.rightMargin: 0
                anchors.top: label1.bottom
                anchors.right: parent.right
                anchors.bottom: row.top
                anchors.left: parent.left
                anchors.topMargin: 0

                Label {
                    id: label2
                    text: qsTr("Label")
                    font.bold: true
                    lineHeight: 0.9
                    fontSizeMode: Text.VerticalFit
                    renderType: Text.NativeRendering
                }

                Label {
                    id: label3
                    text: qsTr("Label")
                }

                Label {
                    id: label4
                    text: qsTr("Label")
                }
            }

            Row {
                id: row
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0

                ToolButton {
                    id: toolButton
                    text: qsTr("EXEC")
                }

                ToolButton {
                    id: toolButton1
                    text: qsTr("COPY")
                }

            }
        }

    }
}
