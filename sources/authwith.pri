#-------------------------------------------------
#
# written by sharkpp
#
#-------------------------------------------------

QT += network networkauth
QT += gui

INCLUDEPATH += $$PWD
VPATH       += $$PWD

equals(POPOVER_USE_STATIC_LIB,1) {
  CONFIG(debug,debug|release){
    win32:LIBS +=   $$PWD/../dist/debug/libAuthWith.lib
    unix:LIBS  += -L$$PWD/../dist/debug/ -lAuthWith
  } else {
    win32:LIBS +=   $$PWD/../dist/release/libAuthWith.lib
    unix:LIBS  += -L$$PWD/../dist/release/ -lAuthWith
  }
} else {
  SOURCES += \
    dropbox.cpp \
    twitter.cpp
}

HEADERS += \
    dropbox.h \
    twitter.h
