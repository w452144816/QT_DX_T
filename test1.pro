#-------------------------------------------------
#
# Project created by QtCreator 2019-05-07T17:07:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dx_t.cpp \
    WET1.cpp \
    WEWidgetDecorator.cpp \
    wedxt1.cpp

HEADERS  += mainwindow.h \
    dx_t.h \
    WET1.h \
    WEWidgetDecorator.h \
    wedxt1.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$(DXSDK_DIR)/Include
INCLUDEPATH += $$(windir)/system32
INCLUDEPATH += C:/Program Files/Microsoft DNX/Dnvm
LIBS += $$(DXSDK_DIR)/Lib/x86/d3d9.lib
LIBS += $$(DXSDK_DIR)/Lib/x86/d3dx10d.lib
LIBS += $$(DXSDK_DIR)/Lib/x86/d3dx9d.lib
LIBS += $$(DXSDK_DIR)/Lib/x86/dxerr.lib
LIBS += $$(DXSDK_DIR)/Lib/x86/dxguid.lib
LIBS += $$(WINSDK)/x86/WinMM.lib
LIBS += $$(WINSDK)/x86/ComCtl32.lib
LIBS += $$(WINSDK)/x86/User32.lib

#win32 {
#    INCLUDEPATH += $(DXSDK_DIR)/Include
#    LIBS +=     $$(DXSDK_DIR)/Lib/winmm.lib \
#         $$(DXSDK_DIR)/Lib/dxguid.lib \
#         $$(DXSDK_DIR)/Lib/dinput8.lib \
#         $$(DXSDK_DIR)/Lib/setupapi.lib
#}



