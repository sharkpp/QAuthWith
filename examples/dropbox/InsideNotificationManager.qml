import QtQuick 2.9

Item {
    anchors.fill: parent
    //activeFocusOnTab: false
    //focus: false
    //clip: true

    Component {
        id: singleShot
        Timer {
            property var action
            running: true
            onTriggered: {
                action && action();
                this.destroy()
            }
        }
    }

    ListModel {
        id: model
    }

    Component {
        id: frame
        Rectangle {
            id: wrapper
            width: Math.max(200, contactInfo.width)
            height: contactInfo.height
            anchors.right: parent.right
            color: "#ccc"
            radius: 8
            Column {
                id: contactInfo
                padding: 4
                Text {
                    padding: 4
                    color: "#000"
                    font.bold: true
                    text: title
                }
                Text {
                    padding: 4
                    color: "#000"
                    text: message
                }
            }

        }
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 4
        model: model
        delegate: frame
        //activeFocusOnTab: false
        //focus: false
        enabled: false
    }


    /*MouseArea {
        anchors.fill: parent
        enabled: false
        propagateComposedEvents: true
        hoverEnabled: false
        onClicked: mouse.accepted = false
        onReleased: mouse.accepted = false
        onEntered: mouse.accepted = false
        onExited:  mouse.accepted = false
        onWheel:  mouse.accepted = false

    }*/
/*
    MouseArea {
        anchors.fill: parent
        propagateComposedEvents: false
        onWheel: {
            console.log('ListView MouseArea onWheel');
            wheel.accepted = false;
        }
        onClicked: {
            console.log('ListView MouseArea onClicked');
            mouse.accepted = false;
            //parent.parent.parent.clicked();
        }

    }*/

    function append(message, title) {
        model.insert(0, {
            title: title,
            message: message,
            t: singleShot.createObject(this, {
                    action: function() {
                            model.remove(model.count-1);
                        },
                    interval: 1000 + 100
                })
        });
    }
}
