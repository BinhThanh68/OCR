QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TextHandling.cpp \
    imageinput.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Struct_and_Enum.h \
    TextHandling.h \
    imageinput.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../OpenCV_4.5.2/opencv/build/x64/vc14/lib/ -lopencv_world452
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../OpenCV_4.5.2/opencv/build/x64/vc14/lib/ -lopencv_world452d
#else:unix: LIBS += -L$$PWD/../../OpenCV_4.5.2/opencv/build/x64/vc14/lib/ -lopencv_world452

#INCLUDEPATH += $$PWD/../../OpenCV_4.5.2/opencv/build/include
#DEPENDPATH += $$PWD/../../OpenCV_4.5.2/opencv/build/include


RESOURCES += \
    Images.qrc



INCLUDEPATH += /usr/local/include/opencv4
LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_videoio -lopencv_dnn -lopencv_text

QMAKE_LFLAGS += -no-pie
