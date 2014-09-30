/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Sep 30 17:24:06 2014
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_Login;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_Name;
    QLabel *label_2;
    QLineEdit *lineEdit_Code;
    QPushButton *pushButton_Logout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Login;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_Quit;
    QWidget *tab_Manager;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *lineEdit_AddBus;
    QLabel *label_21;
    QLineEdit *lineEdit_AddTime;
    QLabel *label_9;
    QLabel *label_10;
    QPlainTextEdit *plainTextEdit_AddBus;
    QPushButton *pushButton_Add;
    QLabel *label_6;
    QLabel *label_11;
    QLineEdit *lineEdit_DeleteBus;
    QPushButton *pushButton_DeleteBus;
    QLabel *label_7;
    QLabel *label_12;
    QLineEdit *lineEdit_UpdateBus;
    QLabel *label_20;
    QLineEdit *lineEdit_UpdateTime;
    QLabel *label_13;
    QSpinBox *spinBox_UpdateStationNum;
    QLabel *label_14;
    QPlainTextEdit *plainTextEdit_UpdateStation;
    QLabel *label_25;
    QLabel *label_26;
    QDoubleSpinBox *doubleSpinBox_AddPrice;
    QDoubleSpinBox *doubleSpinBox_UpdatePrice;
    QPushButton *pushButton_Update;
    QSpinBox *spinBox_StationNum;
    QWidget *tab_Search;
    QFormLayout *formLayout_2;
    QTextBrowser *textBrowser_AllBus;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_22;
    QLineEdit *lineEdit_OneBus;
    QLabel *label_23;
    QPushButton *pushButton_OneBus;
    QTextBrowser *textBrowser_OneBus;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_16;
    QLineEdit *lineEdit_Station;
    QLabel *label_17;
    QPushButton *pushButton_StationQuery;
    QTextBrowser *textBrowser_SomeBus;
    QVBoxLayout *verticalLayout;
    QLabel *label_15;
    QLabel *label_24;
    QPushButton *pushButton_QueryAll;
    QWidget *tab_Transfer;
    QGridLayout *gridLayout_4;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QLineEdit *lineEdit_Start;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QLineEdit *lineEdit_End;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *_2;
    QRadioButton *radioButton_Unconditional;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_ChangeLess;
    QSpinBox *spinBox_ChangeNum;
    QRadioButton *radioButton_DistanceLess;
    QRadioButton *radioButton_PriceLess;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_BusChange;
    QSpacerItem *horizontalSpacer_7;
    QTextBrowser *textBrowser_BusChange;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_27;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(607, 498);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_Login = new QWidget();
        tab_Login->setObjectName(QString::fromUtf8("tab_Login"));
        gridLayout_2 = new QGridLayout(tab_Login);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(tab_Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\256\213\344\275\223\";\n"
"font: 10pt \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit_Name = new QLineEdit(tab_Login);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        gridLayout_2->addWidget(lineEdit_Name, 0, 1, 1, 4);

        label_2 = new QLabel(tab_Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_Code = new QLineEdit(tab_Login);
        lineEdit_Code->setObjectName(QString::fromUtf8("lineEdit_Code"));

        gridLayout_2->addWidget(lineEdit_Code, 1, 1, 1, 4);

        pushButton_Logout = new QPushButton(tab_Login);
        pushButton_Logout->setObjectName(QString::fromUtf8("pushButton_Logout"));

        gridLayout_2->addWidget(pushButton_Logout, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        pushButton_Login = new QPushButton(tab_Login);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));

        gridLayout_2->addWidget(pushButton_Login, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 5, 1, 1);

        pushButton_Quit = new QPushButton(tab_Login);
        pushButton_Quit->setObjectName(QString::fromUtf8("pushButton_Quit"));

        gridLayout_2->addWidget(pushButton_Quit, 3, 2, 1, 1);

        tabWidget->addTab(tab_Login, QString());
        tab_Manager = new QWidget();
        tab_Manager->setObjectName(QString::fromUtf8("tab_Manager"));
        gridLayout_3 = new QGridLayout(tab_Manager);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(tab_Manager);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAcceptDrops(false);
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"text-decoration: underline;\n"
"font: 9pt \"\345\256\213\344\275\223\";\n"
"font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 2);

        label_8 = new QLabel(tab_Manager);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_AddBus = new QLineEdit(tab_Manager);
        lineEdit_AddBus->setObjectName(QString::fromUtf8("lineEdit_AddBus"));

        gridLayout_3->addWidget(lineEdit_AddBus, 1, 1, 1, 1);

        label_21 = new QLabel(tab_Manager);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 1, 2, 1, 1);

        lineEdit_AddTime = new QLineEdit(tab_Manager);
        lineEdit_AddTime->setObjectName(QString::fromUtf8("lineEdit_AddTime"));

        gridLayout_3->addWidget(lineEdit_AddTime, 1, 3, 1, 1);

        label_9 = new QLabel(tab_Manager);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label_9, 1, 7, 1, 1);

        label_10 = new QLabel(tab_Manager);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 2);

        plainTextEdit_AddBus = new QPlainTextEdit(tab_Manager);
        plainTextEdit_AddBus->setObjectName(QString::fromUtf8("plainTextEdit_AddBus"));

        gridLayout_3->addWidget(plainTextEdit_AddBus, 3, 0, 1, 8);

        pushButton_Add = new QPushButton(tab_Manager);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));

        gridLayout_3->addWidget(pushButton_Add, 3, 8, 1, 1);

        label_6 = new QLabel(tab_Manager);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"text-decoration: underline;\n"
"font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_3->addWidget(label_6, 4, 0, 1, 2);

        label_11 = new QLabel(tab_Manager);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 5, 0, 1, 1);

        lineEdit_DeleteBus = new QLineEdit(tab_Manager);
        lineEdit_DeleteBus->setObjectName(QString::fromUtf8("lineEdit_DeleteBus"));

        gridLayout_3->addWidget(lineEdit_DeleteBus, 5, 1, 1, 1);

        pushButton_DeleteBus = new QPushButton(tab_Manager);
        pushButton_DeleteBus->setObjectName(QString::fromUtf8("pushButton_DeleteBus"));

        gridLayout_3->addWidget(pushButton_DeleteBus, 5, 8, 1, 1);

        label_7 = new QLabel(tab_Manager);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"text-decoration: underline;\n"
"font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_3->addWidget(label_7, 6, 0, 1, 2);

        label_12 = new QLabel(tab_Manager);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 7, 0, 1, 1);

        lineEdit_UpdateBus = new QLineEdit(tab_Manager);
        lineEdit_UpdateBus->setObjectName(QString::fromUtf8("lineEdit_UpdateBus"));

        gridLayout_3->addWidget(lineEdit_UpdateBus, 7, 1, 1, 1);

        label_20 = new QLabel(tab_Manager);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 7, 2, 1, 1);

        lineEdit_UpdateTime = new QLineEdit(tab_Manager);
        lineEdit_UpdateTime->setObjectName(QString::fromUtf8("lineEdit_UpdateTime"));

        gridLayout_3->addWidget(lineEdit_UpdateTime, 7, 3, 1, 1);

        label_13 = new QLabel(tab_Manager);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 7, 7, 1, 1);

        spinBox_UpdateStationNum = new QSpinBox(tab_Manager);
        spinBox_UpdateStationNum->setObjectName(QString::fromUtf8("spinBox_UpdateStationNum"));

        gridLayout_3->addWidget(spinBox_UpdateStationNum, 7, 8, 1, 1);

        label_14 = new QLabel(tab_Manager);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 8, 0, 1, 2);

        plainTextEdit_UpdateStation = new QPlainTextEdit(tab_Manager);
        plainTextEdit_UpdateStation->setObjectName(QString::fromUtf8("plainTextEdit_UpdateStation"));

        gridLayout_3->addWidget(plainTextEdit_UpdateStation, 9, 0, 1, 8);

        label_25 = new QLabel(tab_Manager);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label_25, 1, 4, 1, 1);

        label_26 = new QLabel(tab_Manager);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_3->addWidget(label_26, 7, 4, 1, 1);

        doubleSpinBox_AddPrice = new QDoubleSpinBox(tab_Manager);
        doubleSpinBox_AddPrice->setObjectName(QString::fromUtf8("doubleSpinBox_AddPrice"));
        doubleSpinBox_AddPrice->setSingleStep(0.1);

        gridLayout_3->addWidget(doubleSpinBox_AddPrice, 1, 6, 1, 1);

        doubleSpinBox_UpdatePrice = new QDoubleSpinBox(tab_Manager);
        doubleSpinBox_UpdatePrice->setObjectName(QString::fromUtf8("doubleSpinBox_UpdatePrice"));
        doubleSpinBox_UpdatePrice->setSingleStep(0.1);

        gridLayout_3->addWidget(doubleSpinBox_UpdatePrice, 7, 5, 1, 2);

        pushButton_Update = new QPushButton(tab_Manager);
        pushButton_Update->setObjectName(QString::fromUtf8("pushButton_Update"));

        gridLayout_3->addWidget(pushButton_Update, 9, 8, 1, 1);

        spinBox_StationNum = new QSpinBox(tab_Manager);
        spinBox_StationNum->setObjectName(QString::fromUtf8("spinBox_StationNum"));
        spinBox_StationNum->setMinimum(0);

        gridLayout_3->addWidget(spinBox_StationNum, 1, 8, 1, 1);

        tabWidget->addTab(tab_Manager, QString());
        tab_Search = new QWidget();
        tab_Search->setObjectName(QString::fromUtf8("tab_Search"));
        formLayout_2 = new QFormLayout(tab_Search);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        textBrowser_AllBus = new QTextBrowser(tab_Search);
        textBrowser_AllBus->setObjectName(QString::fromUtf8("textBrowser_AllBus"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, textBrowser_AllBus);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_22 = new QLabel(tab_Search);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_3->addWidget(label_22);

        lineEdit_OneBus = new QLineEdit(tab_Search);
        lineEdit_OneBus->setObjectName(QString::fromUtf8("lineEdit_OneBus"));

        verticalLayout_3->addWidget(lineEdit_OneBus);

        label_23 = new QLabel(tab_Search);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_3->addWidget(label_23);

        pushButton_OneBus = new QPushButton(tab_Search);
        pushButton_OneBus->setObjectName(QString::fromUtf8("pushButton_OneBus"));

        verticalLayout_3->addWidget(pushButton_OneBus);


        formLayout_2->setLayout(2, QFormLayout::LabelRole, verticalLayout_3);

        textBrowser_OneBus = new QTextBrowser(tab_Search);
        textBrowser_OneBus->setObjectName(QString::fromUtf8("textBrowser_OneBus"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, textBrowser_OneBus);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_16 = new QLabel(tab_Search);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font;
        font.setPointSize(10);
        label_16->setFont(font);

        verticalLayout_2->addWidget(label_16);

        lineEdit_Station = new QLineEdit(tab_Search);
        lineEdit_Station->setObjectName(QString::fromUtf8("lineEdit_Station"));

        verticalLayout_2->addWidget(lineEdit_Station);

        label_17 = new QLabel(tab_Search);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);

        verticalLayout_2->addWidget(label_17);

        pushButton_StationQuery = new QPushButton(tab_Search);
        pushButton_StationQuery->setObjectName(QString::fromUtf8("pushButton_StationQuery"));

        verticalLayout_2->addWidget(pushButton_StationQuery);


        formLayout_2->setLayout(4, QFormLayout::LabelRole, verticalLayout_2);

        textBrowser_SomeBus = new QTextBrowser(tab_Search);
        textBrowser_SomeBus->setObjectName(QString::fromUtf8("textBrowser_SomeBus"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, textBrowser_SomeBus);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_15 = new QLabel(tab_Search);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        verticalLayout->addWidget(label_15);

        label_24 = new QLabel(tab_Search);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout->addWidget(label_24);

        pushButton_QueryAll = new QPushButton(tab_Search);
        pushButton_QueryAll->setObjectName(QString::fromUtf8("pushButton_QueryAll"));

        verticalLayout->addWidget(pushButton_QueryAll);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        tabWidget->addTab(tab_Search, QString());
        tab_Transfer = new QWidget();
        tab_Transfer->setObjectName(QString::fromUtf8("tab_Transfer"));
        gridLayout_4 = new QGridLayout(tab_Transfer);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_19 = new QLabel(tab_Transfer);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";\n"
"text-decoration: underline;"));

        gridLayout_4->addWidget(label_19, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_3 = new QLabel(tab_Transfer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(31, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_Start = new QLineEdit(tab_Transfer);
        lineEdit_Start->setObjectName(QString::fromUtf8("lineEdit_Start"));
        lineEdit_Start->setMaximumSize(QSize(100, 21));

        horizontalLayout_2->addWidget(lineEdit_Start);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_4 = new QLabel(tab_Transfer);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_End = new QLineEdit(tab_Transfer);
        lineEdit_End->setObjectName(QString::fromUtf8("lineEdit_End"));
        lineEdit_End->setMaximumSize(QSize(100, 21));

        horizontalLayout_3->addWidget(lineEdit_End);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        _2 = new QVBoxLayout();
        _2->setSpacing(6);
        _2->setObjectName(QString::fromUtf8("_2"));
        radioButton_Unconditional = new QRadioButton(tab_Transfer);
        radioButton_Unconditional->setObjectName(QString::fromUtf8("radioButton_Unconditional"));

        _2->addWidget(radioButton_Unconditional);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        radioButton_ChangeLess = new QRadioButton(tab_Transfer);
        radioButton_ChangeLess->setObjectName(QString::fromUtf8("radioButton_ChangeLess"));

        verticalLayout_5->addWidget(radioButton_ChangeLess);

        spinBox_ChangeNum = new QSpinBox(tab_Transfer);
        spinBox_ChangeNum->setObjectName(QString::fromUtf8("spinBox_ChangeNum"));
        spinBox_ChangeNum->setMinimumSize(QSize(150, 0));
        spinBox_ChangeNum->setMaximumSize(QSize(199, 16777215));

        verticalLayout_5->addWidget(spinBox_ChangeNum);


        _2->addLayout(verticalLayout_5);

        radioButton_DistanceLess = new QRadioButton(tab_Transfer);
        radioButton_DistanceLess->setObjectName(QString::fromUtf8("radioButton_DistanceLess"));

        _2->addWidget(radioButton_DistanceLess);

        radioButton_PriceLess = new QRadioButton(tab_Transfer);
        radioButton_PriceLess->setObjectName(QString::fromUtf8("radioButton_PriceLess"));

        _2->addWidget(radioButton_PriceLess);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        _2->addItem(verticalSpacer);

        pushButton_BusChange = new QPushButton(tab_Transfer);
        pushButton_BusChange->setObjectName(QString::fromUtf8("pushButton_BusChange"));

        _2->addWidget(pushButton_BusChange);


        gridLayout_4->addLayout(_2, 3, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 4, 1, 1, 1);

        textBrowser_BusChange = new QTextBrowser(tab_Transfer);
        textBrowser_BusChange->setObjectName(QString::fromUtf8("textBrowser_BusChange"));

        gridLayout_4->addWidget(textBrowser_BusChange, 3, 1, 1, 1);

        tabWidget->addTab(tab_Transfer, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_27 = new QLabel(tab);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        QFont font1;
        font1.setPointSize(11);
        label_27->setFont(font1);

        verticalLayout_4->addWidget(label_27);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\214\227\344\272\254\345\205\254\344\272\244\346\237\245\350\257\242\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\345\257\206 \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Logout->setText(QApplication::translate("Widget", "\346\263\250\351\224\200", 0, QApplication::UnicodeUTF8));
        pushButton_Login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_Quit->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Login), QApplication::translate("Widget", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\344\270\200\346\235\241\347\272\277\350\267\257\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "\347\272\277\350\267\257\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Widget", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "\347\253\231\347\202\271\346\225\260\347\233\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\347\253\231\347\202\271\357\274\210\344\273\245\347\251\272\346\240\274\345\210\206\345\274\200\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Add->setText(QApplication::translate("Widget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\344\270\200\346\235\241\347\272\277\350\267\257\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget", "\347\272\277\350\267\257\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteBus->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "\346\233\264\346\226\260\344\270\200\346\235\241\347\272\277\350\267\257\344\277\241\346\201\257\357\274\232", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget", "\347\272\277\350\267\257\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Widget", "\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Widget", "\347\253\231\347\202\271\346\225\260\347\233\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Widget", "\346\211\200\346\234\211\347\253\231\347\202\271\357\274\210\344\273\245\347\251\272\346\240\274\345\210\206\345\274\200\357\274\211\357\274\232", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Widget", "\347\245\250\344\273\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("Widget", "\347\245\250\344\273\267\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_Update->setText(QApplication::translate("Widget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Manager), QApplication::translate("Widget", "\344\277\241\346\201\257\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Widget", "2\343\200\201\347\272\277\350\267\257", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Widget", "  \347\232\204\346\211\200\346\234\211\344\277\241\346\201\257;", 0, QApplication::UnicodeUTF8));
        pushButton_OneBus->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Widget", "3\343\200\201\347\273\217\350\277\207\347\253\231\347\202\271\357\274\232", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Widget", "      \347\232\204\346\211\200\346\234\211\347\272\277\350\267\257", 0, QApplication::UnicodeUTF8));
        pushButton_StationQuery->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Widget", "1\343\200\201\346\211\200\346\234\211\345\205\254\344\272\244\350\267\257\347\272\277\357\274\232", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Widget", "    (\346\214\211\347\205\247\350\265\267\347\202\271\346\216\222\345\272\217)    ", 0, QApplication::UnicodeUTF8));
        pushButton_QueryAll->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Search), QApplication::translate("Widget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Widget", "\346\215\242\344\271\230\346\237\245\350\257\242\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Widget", "\350\265\267\347\202\271", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\347\273\210\347\202\271", 0, QApplication::UnicodeUTF8));
        radioButton_Unconditional->setText(QApplication::translate("Widget", "\346\227\240\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8));
        radioButton_ChangeLess->setText(QApplication::translate("Widget", "\346\215\242\344\271\230\346\254\241\346\225\260\345\260\221\344\272\216\347\255\211\344\272\216", 0, QApplication::UnicodeUTF8));
        radioButton_DistanceLess->setText(QApplication::translate("Widget", "\350\267\235\347\246\273\346\234\200\347\237\255", 0, QApplication::UnicodeUTF8));
        radioButton_PriceLess->setText(QApplication::translate("Widget", "\347\245\250\344\273\267\346\234\200\345\260\221", 0, QApplication::UnicodeUTF8));
        pushButton_BusChange->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_Transfer), QApplication::translate("Widget", "\346\215\242\344\271\230\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("Widget", "by \350\265\265\345\270\205\346\261\237 \350\265\265\345\270\205\345\205\265", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\233\270\345\205\263\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
