TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        cell.cpp \
        main.cpp \
        supertictactoe.cpp \
        tictactoe.cpp

HEADERS += \
    board.h \
    cell.h \
    supertictactoe.h \
    tictactoe.h
