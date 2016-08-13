TEMPLATE = app
FORMS = untitled.ui
HEADERS = wtf.h \
    lvlpreviewview.h \
    lvlPrevScene.h
SOURCES = main.cpp wtf.cpp lvlPrevScene.cpp \
    lvlpreviewview.cpp
RESOURCES = std.qrc
QT += widgets
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
