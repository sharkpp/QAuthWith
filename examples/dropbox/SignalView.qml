import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
//import net.sharkpp.authwith.method 1.0
import "qmetatype.js" as QMetaType

Pane {
    id: pane

    property variant _listObject: null
    property variant signal_: null

    Component {
        id: typeInt
        Label {
            property variant argIndex: null
            anchors.right: parent.right
            anchors.left: parent.left
            text: ""
        }
    }

    Component {
        id: typeQString
        Label {
            property variant argIndex: null
            anchors.right: parent.right
            anchors.left: parent.left
            text: ""
            Component.onCompleted: {
                console.log(">>>>",this,argIndex);
                signal_.bind(argIndex, this);
            }
        }
    }

    Component {
        id: typeBool
        Switch {
            property variant argIndex: null
            anchors.right: parent.right
            anchors.left: parent.left
            checked: true
        }
    }

    Column {
        id: column
        anchors.fill: parent
        spacing: 4

        Row {
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 4

            // signal prototype
            Label {
                id: prototype
                wrapMode: Text.WrapAnywhere
                width: parent.width - annotation.width
                font.bold: true
                text: signal_.prototype
            }

            // annotation
            Label {
                id: annotation
                font.bold: true
                text: "[signal]"
            }

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
            text: signal_.description
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
                //id: methodArgs
                anchors.fill: parent
                columns: 4
                rowSpacing: 4
                columnSpacing: 4
                //anchors.margins: 4

                Label { font.bold: true; text: qsTr("prototype") }
                Label { font.bold: true; text: qsTr("value") }
                Label { font.bold: true; text: qsTr("description") }

                Repeater {
                    model: signal_.args
                    Label {
                        Layout.row: 1 + index
                        Layout.column: 0
                        Layout.alignment: Qt.AlignVCenter
                        text: modelData.prototype
                    }
                }

                Repeater {
                    model: signal_.args
                    id: value
                    Item {
                        id: valueEditorContainer
                        Layout.row: 1 + index
                        Layout.column: 1
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignVCenter
                        Component.onCompleted: {
                            var viewer;
                            switch (modelData.type) {
                            case QMetaType.Int:
                                viewer = typeInt.createObject(
                                            valueEditorContainer, {
                                                argIndex: index
                                            })
                                break;
                            case QMetaType.QString:
                                viewer = typeQString.createObject(
                                            valueEditorContainer, {
                                                argIndex: index
                                            })
                                break;
                            case QMetaType.Bool:
                                viewer = typeBool.createObject(
                                            valueEditorContainer, {
                                                argIndex: index
                                            })
                                break;
                            default:
                               console.log("unknwon type "+modelData.type);
                            }

                            if (viewer) {
                                valueEditorContainer.Layout.preferredHeight = viewer.height
                                //valueEditorContainer.Layout.preferredWidth  = viewer.width
                            }
                        }
                    }

                }

                Repeater {
                    model: signal_.args
                    Label {
                        Layout.row: 1 + index
                        Layout.column: 2
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
                icon.name: "file_copy"

                ToolTip.visible: hovered
                ToolTip.text: qsTr("Copy code")
            }

        }

    }
}
