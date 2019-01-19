import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Controls.Universal 2.2
import Qt.labs.settings 1.0

ApplicationWindow {
    id: window
    width: 640-100
    height: 480
    visible: true
    title: "AuthWith - " + appData.appName

    header: ToolBar {
        Material.foreground: "white"

        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                icon.name: "menu"

                onClicked: {
                    drawer.open()
                }
            }

            Label {
                id: titleLabel
                text: listView.currentItem ? listView.currentItem.text : "AuthWith - dropbox"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                icon.name: "more_vert"

                ToolTip.visible: hovered
                ToolTip.text: qsTr("Options")

                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }
            }
        }
    }

    Drawer {
        id: drawer
        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height
        //interactive: stackView.depth === 1

        ListView {
            id: listView

            focus: true
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.modelData.name
                highlighted: ListView.isCurrentItem
                onClicked: {
                    listView.currentIndex   = index
                    methodList.currentIndex = index
                    //stackView.push(model.source)
                    drawer.close()
                }
            }

            model: methodList.model

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    ScrollView {
        id: apiView
        anchors.fill: parent
        //width: parent.width

        ListView {
            id: methodList
            anchors.fill: parent
            model: appData.definitions
            /*delegate: MethodView { // MethodView.qml
                width: parent.width
                method: model.modelData
                _listObject: methodList
            }*/
            /*delegate: Item {
                id: listContainer
                anchors.fill: parent
                //Layout.row: 1 + index
                //Layout.column: 2
                //Layout.fillWidth: true
                //Layout.fillHeight: true
                //Layout.alignment: Qt.AlignVCenter
                Component.onCompleted: {
                    var MethodView_ = Qt.createComponent("MethodView.qml");
                    MethodView_.createObject(listContainer, {
                        "anchors.fill": parent,
                        width: parent.width,
                        method: model.modelData,
                        _listObject: methodList,
                    });
                }
            }*/
            delegate: Component {
                Loader {
                    id: listContainer
                    height: childrenRect.height
                    width: parent.width
                    source: switch(model.modelData.definitionType) {
                        case "method":
                            var MethodView_ = Qt.createComponent("MethodView.qml");
                            MethodView_.createObject(listContainer, {
                                //"anchors.fill": parent,
                                width: parent.width,
                                method: model.modelData,
                                //_listObject: methodList,
                            });
                            return MethodView_;
                        case "signal":
                            var SignalView_ = Qt.createComponent("SignalView.qml");
                            SignalView_.createObject(listContainer, {
                                //"anchors.fill": parent,
                                width: parent.width,
                                signal_: model.modelData,
                                //_listObject: methodList,
                            });
                            return SignalView_;
                        default:
                            console.log("**",model.modelData.definitionType);
                            return Item;
                    }
                }
            }
        }


        /*Label {
            id: titleLabel2
            text: "Gallery"
            font.pixelSize: 20
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
        }*/

    }

    Dialog {
        id: aboutDialog
        modal: true
        focus: true
        title: "About"
        x: (window.width - width) / 2
        y: window.height / 6
        width: Math.min(window.width, window.height) / 3 * 2
        contentHeight: aboutColumn.height

        Column {
            id: aboutColumn
            spacing: 20

            Label {
                width: aboutDialog.availableWidth
                text: "The Qt Quick Controls 2 module delivers the next generation user interface controls based on Qt Quick."
                wrapMode: Label.Wrap
                font.pixelSize: 12
            }

            Label {
                width: aboutDialog.availableWidth
                text: "In comparison to the desktop-oriented Qt Quick Controls 1, Qt Quick Controls 2 "
                    + "are an order of magnitude simpler, lighter and faster, and are primarily targeted "
                    + "towards embedded and mobile platforms."
                wrapMode: Label.Wrap
                font.pixelSize: 12
            }
        }
    }

    Timer {
        interval: 1000;
        running: true;
        repeat: true
        onTriggered: notify.append("test test "+(new Date()).toString(), "title")
    }

    InsideNotificationManager {
        id: notify
    }
}
