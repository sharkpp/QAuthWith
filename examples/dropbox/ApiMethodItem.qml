import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Pane {
    id: pane
    //contentWidth: parent.width - 100

    property variant _listObject: null
    property variant method: null
    property variant exec: null

    Column {
        id: column
        anchors.fill: parent

        //Row {
            //width: parent.width

            Label {
                //id: label
                //width: parent.width
                anchors.left: parent.left
                anchors.right: parent.right
                wrapMode: Text.WrapAnywhere
                //text: qsTr("QPushButton::QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)")
                text: method
            }

            /*Label {
                id: label5
                text: qsTr("[slot]")
                //anchors.right: parent
            }*/

        //}

        Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            height: 2
            color: "#ccc"
        }

        Column {
            id: column1
            anchors.left: parent.left
            anchors.right: parent.right
            //visible: false
            spacing: 4

            Label {
                id: label1
                wrapMode: Text.WrapAnywhere
                anchors.left: parent.left
                anchors.right: parent.right
                text: qsTr("Constructs a push button with an icon and a text, and a parent.\nNote that you can also pass a QPixmap object as an icon (thanks to the implicit type conversion provided by C++).")
            }

            GroupBox {
                title: "tryout"
                leftPadding: 4
                topPadding: 20
                rightPadding: 4
                bottomPadding: 4

                background: Rectangle {
                    color: "#ffffff"
                    border.color: "#ccc"
                }

                Grid {
                    id: grid
                    anchors.fill: parent
                    columns: 4
                    spacing: 8
                    //anchors.verticalCenterOffset: 2;

                    Label { font.bold: true; text: qsTr("prototype") }
                    Label { font.bold: true; text: qsTr("required") }
                    Label { font.bold: true; text: qsTr("value") }
                    Label { font.bold: true; text: qsTr("description") }

                    Label { text: qsTr("const QIcon &icon") }
                    Label { text: qsTr("true") }
                    Button { text: qsTr("...") }
                    Label { text: qsTr("hoge fuga hoge fuga ") }

                    Label { text: qsTr("const QString &text") }
                    Label { text: qsTr("true") }
                    TextField { placeholderText: qsTr("const QString &text") }
                    Label { text: qsTr("hoge fuga hoge fuga ") }

                    Label { text: qsTr("QWidget *parent") }
                    Label { text: qsTr("false") }
                    Label { text: qsTr("***") }
                    Label { text: qsTr("hoge fuga hoge fuga ") }
                }

            }

            Row {
                id: row

                ToolButton {
                    icon.name: "play_circle"

                    ToolTip.visible: hovered
                    ToolTip.text: qsTr("Try out code")

                    onClicked: {
                        exec.exec()
                    }
                }

                ToolButton {
                    icon.name: "file_copy"

                    ToolTip.visible: hovered
                    ToolTip.text: qsTr("Copy code")
                }

            }
        }

    }
}

