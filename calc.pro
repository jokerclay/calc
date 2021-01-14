# 导入 Q core gui
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# 支持 C++ 11
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

# 源文件
SOURCES += \
    main.cpp \
    calc.cpp
# 头文件
HEADERS += \
    calc.h
# 程序的UI 文件
FORMS += \
    calc.ui

# 默认的构建目录
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
