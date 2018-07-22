import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
//import net.sharkpp.authwith.method 1.0
import "qmetatype.js" as QMetaType

Pane {
    id: pane
    //contentWidth: parent.width - 100

    property variant _listObject: null
    property variant method: null

    Component {
        id: typeInt
        TextField {
            //anchors.fill: parent
            anchors.right: parent.right
            anchors.left: parent.left
            //placeholderText: qsTr("const QString &text")
        }
    }

    Component {
        id: typeBool
        Switch {
            anchors.right: parent.right
            anchors.left: parent.left
            //anchors.fill: parent
            checked: true
        }
    }

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
                text: method.prototype
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
                id: methodDescription
                wrapMode: Text.WrapAnywhere
                anchors.left: parent.left
                anchors.right: parent.right
                text: method.description
            }

            GroupBox {
                //title: "tryout"
                leftPadding: 4
                //topPadding: 20
                topPadding: 0
                rightPadding: 4
                bottomPadding: 4
                anchors.left: parent.left
                anchors.right: parent.right

                background: Rectangle {
                    color: "#ffffff"
                    border.color: "#ccc"
                }

                /*Repeater {
                    model: method.args

                    Row {
                        anchors.fill: parent

                        Repeater {
                            model: modelData

                            Column {
                                Label { text: modelData.prototype }
                                Label { text: modelData.required ? qsTr("true") : qsTr("false") }
                                Label { text: qsTr("***") }
                                Label { text: modelData.description }
                            }
                        }
                    }
                }*/


                /*Grid {
                    id: grid_
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


                    Repeater {
                        model: method.args

                         {


                            Label { text: modelData.prototype }
                            Label { text: modelData.required ? qsTr("true") : qsTr("false") }
                            Label { text: qsTr("***") }
                            Label { text: modelData.description }
                        }
                    }

                }*/


                GridLayout {
                    id: methodArgs
                    anchors.fill: parent
                    columns: 4
                    rowSpacing: 4
                    columnSpacing: 4
                    //anchors.margins: 4

                    Label { font.bold: true; text: qsTr("prototype") }
                    Label { font.bold: true; text: qsTr("required") }
                    Label { font.bold: true; text: qsTr("value") }
                    Label { font.bold: true; text: qsTr("description") }

                    Repeater {
                        model: method.args
                        Label {
                            Layout.row: 1 + index
                            Layout.column: 0
                            //Layout.fillWidth: true
                            //Layout.fillHeight: true
                            Layout.alignment: Qt.AlignVCenter
                            //verticalAlignment: Text.AlignVCenter
                            text: modelData.prototype
                            /*background: Rectangle {
                                color: "#fcc"
                                border.color: "#cfc"
                            }*/
                        }
                    }

                    Repeater {
                        model: method.args
                        Label {
                            Layout.row: 1 + index
                            Layout.column: 1
                            //Layout.fillWidth: true
                            //Layout.fillHeight: true
                            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                            text: modelData.required ? qsTr("true") : qsTr("false")
                        }
                    }

                    Repeater {
                        model: method.args
                        id: value
                        Item {
                            id: valueEditorContainer
                            Layout.row: 1 + index
                            Layout.column: 2
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.alignment: Qt.AlignVCenter
                            Component.onCompleted: {
                                var editor;
                                switch (modelData.type) {
                                case QMetaType.Int:
                                    editor = typeInt.createObject(
                                                valueEditorContainer, {
                                                    placeholderText: modelData.prototype
                                                })
                                    break;
                                case QMetaType.Bool:
                                    editor = typeBool.createObject(valueEditorContainer)
                                    break;
                                default:
                                   console.log("unknwon type "+modelData.type);
                                }

                                if (editor) {
                                    valueEditorContainer.Layout.preferredHeight = editor.height
                                    //valueEditorContainer.Layout.preferredWidth  = editor.width
                                }
                            }
                        }

                    }

                    Repeater {
                        model: method.args
                        Label {
                            Layout.row: 1 + index
                            Layout.column: 3
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.alignment: Qt.AlignVCenter
                            text: modelData.description
                            //Layout.preferredHeight: 50
                        }
                    }
                }
            }

            Row {
                id: row

                ToolButton {
                    icon.name: "play_circle"

                    ToolTip.visible: hovered
                    ToolTip.text: qsTr("Try out code")

                    onClicked: {
                        method.exec()
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

