QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_menu.cpp \
    admin_sign_in.cpp \
    delete_user.cpp \
    login_ui.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    number.cpp \
    result.cpp \
    set_question.cpp \
    show_database.cpp \
    show_user_question.cpp \
    sign_confirm.cpp \
    sign_up.cpp \
    view_question.cpp

HEADERS += \
    admin_menu.h \
    admin_sign_in.h \
    delete_user.h \
    login_ui.h \
    mainwindow.h \
    menu.h \
    number.h \
    result.h \
    set_question.h \
    show_database.h \
    show_user_question.h \
    sign_confirm.h \
    sign_up.h \
    view_question.h

FORMS += \
    admin_menu.ui \
    admin_sign_in.ui \
    delete_user.ui \
    login_ui.ui \
    mainwindow.ui \
    menu.ui \
    number.ui \
    result.ui \
    set_question.ui \
    show_database.ui \
    show_user_question.ui \
    sign_confirm.ui \
    sign_up.ui \
    view_question.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
