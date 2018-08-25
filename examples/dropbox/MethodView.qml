import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
//import net.sharkpp.authwith.method 1.0
import "qmetatype.js" as QMetaType

Pane {
    id: pane

    property variant _listObject: null
    property variant method: null
    property var     argsBuff: ({})

    Component {
        id: typeInt
        TextField {
            anchors.right: parent.right
            anchors.left: parent.left
            signal valueChanged(var value);
            text: ""
            onTextChanged: {
                valueChanged(text)
            }
        }
    }

    Component {
        id: typeQString
        TextField {
            anchors.right: parent.right
            anchors.left: parent.left
            text: ""
            signal valueChanged(var value);
            onTextChanged: {
                valueChanged(text)
            }
        }
    }

    Component {
        id: typeBool
        Switch {
            anchors.right: parent.right
            anchors.left: parent.left
            checked: true
            signal valueChanged(var value);
            onCheckedChanged: {
                valueChanged(checked)
            }
        }
    }

    Component {
        id: typeQByteArray
        Button {
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.margins: 4
            signal valueChanged(var value);
            function onFileDialogAccepted() {
                //console.log("file selected",fileDialog.fileUrls);
                onFileDialogRejected()
                valueChanged(fileDialog.fileUrls);
            }
            function onFileDialogRejected() {
                fvalueChanged("");
                ileDialog.onAccepted.disconnect(onFileDialogAccepted)
                fileDialog.onRejected.disconnect(onFileDialogRejected)
            }

            onClicked: {
                fileDialog.onAccepted.connect(onFileDialogAccepted)
                fileDialog.onRejected.connect(onFileDialogRejected)
                fileDialog.visible = true;
            }
        }
    }

    Column {
        id: column
        anchors.fill: parent
        spacing: 4

        // function prototype
        Label {
            anchors.left: parent.left
            anchors.right: parent.right
            wrapMode: Text.WrapAnywhere
            font.bold: true
            text: method.prototype
        }

        // hoz border
        Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            height: 2
            color: "#ccc"
        }

        // description
        Label {
            wrapMode: Text.WrapAnywhere
            anchors.left: parent.left
            anchors.right: parent.right
            text: method.description
        }

        GroupBox {
            //title: "tryout"
            padding: 4
            anchors.left: parent.left
            anchors.right: parent.right

            background: Rectangle {
                color: "#ffffff"
                border.color: "#ccc"
            }

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

                /*Repeater {
                    model: 4
                    Rectangle {
                        Layout.fillWidth: true
                        //Layout.fillHeight: true
                        //anchors.left: parent.left
                        //anchors.right: parent.right
                        height: 2
                        color: "#ccc"
                    }
                }*/

                Repeater {
                    model: method.args
                    Label {
                        Layout.row: 1 + index
                        Layout.column: 0
                        Layout.alignment: Qt.AlignVCenter
                        text: modelData.prototype
                    }
                }

                Repeater {
                    model: method.args
                    Label {
                        Layout.row: 1 + index
                        Layout.column: 1
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
                                                placeholderText: modelData.name
                                            })
                                break;
                            case QMetaType.QString:
                                editor = typeQString.createObject(
                                            valueEditorContainer, {
                                                placeholderText: modelData.name
                                            })
                                break;
                            case QMetaType.QByteArray:
                                editor = typeQByteArray.createObject(
                                            valueEditorContainer, {
                                                text: modelData.name + " ..."
                                            })
                                break;
                            case QMetaType.Bool:
                                editor = typeBool.createObject(valueEditorContainer)
                                break;
                            default:
                               console.log("unknwon type "+modelData.type);
                            }

                            if (editor) {
                                editor.valueChanged.connect(function (value) {
                                    argsBuff[modelData.name] = value
                                })
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
                        //Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignVCenter
                        text: modelData.description
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
                    //console.log(JSON.stringify(argsBuff));
                    method.exec(argsBuff)
                }
            }

            ToolButton {
                icon.name: "file_copy"

                ToolTip.visible: hovered
                ToolTip.text: qsTr("Copy code")
            }

        }

    }

    FileDialog {
        id: fileDialog
        title: qsTr("Please choose a file")
        folder: shortcuts.home
    }
}

