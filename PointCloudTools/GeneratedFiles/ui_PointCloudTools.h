/********************************************************************************
** Form generated from reading UI file 'PointCloudTools.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTCLOUDTOOLS_H
#define UI_POINTCLOUDTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PointCloudToolsClass
{
public:
    QAction *openAction;
    QAction *saveAction;
    QAction *saveasAction;
    QAction *cubeAction;
    QAction *helpAction;
    QAction *aboutAction;
    QAction *exitAction;
    QAction *pointcolorAction;
    QAction *bgcolorAction;
    QAction *mainviewAction;
    QAction *leftviewAction;
    QAction *topviewAction;
    QAction *dataAction;
    QAction *propertyAction;
    QAction *consoleAction;
    QAction *RGBAction;
    QAction *clearAction;
    QAction *sphereAction;
    QAction *cylinderAction;
    QAction *meshsurfaceAction;
    QAction *wireframeAction;
    QAction *windowsThemeAction;
    QAction *darculaThemeAction;
    QAction *englishAction;
    QAction *chineseAction;
    QAction *saveBinaryAction;
    QAction *filterAction;
    QAction *voxelAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVTKWidget *screen;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuGenerate;
    QMenu *menuBasic_shapes;
    QMenu *menuAbout;
    QMenu *menuOption;
    QMenu *themeAction;
    QMenu *langAction;
    QMenu *menuView;
    QMenu *menuAngle_view;
    QMenu *menuView_2;
    QMenu *menuProcess;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *imageDock;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *imageDepth;
    QPushButton *colormapBtn;
    QLabel *imageColor;
    QPushButton *convertBtn;
    QDockWidget *dataDock;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *dataTree;
    QDockWidget *propertyDock;
    QWidget *dockWidgetContents_6;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *fyLineedit;
    QLineEdit *k2Lineedit;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *cxLineedit;
    QLineEdit *p1Lineedit;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *cyLineedit;
    QLineEdit *p2Lineedit;
    QLabel *label_3;
    QLineEdit *fxLineedit;
    QLineEdit *k1Lineedit;
    QLabel *label;
    QLabel *label_10;
    QLineEdit *aLineedit;
    QLabel *label_11;
    QLineEdit *k3Lineedit;
    QDockWidget *consoleDock;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *consoleTable;
    QDockWidget *RGBDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_14;
    QLCDNumber *sizeLCD;
    QSlider *pSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QRadioButton *colormap_x;
    QRadioButton *colormap_y;
    QRadioButton *colormap_z;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *colorMapLeft;
    QLineEdit *colorMapRight;
    QPushButton *colorBtn;
    QCheckBox *cooCbx;

    void setupUi(QMainWindow *PointCloudToolsClass)
    {
        if (PointCloudToolsClass->objectName().isEmpty())
            PointCloudToolsClass->setObjectName(QStringLiteral("PointCloudToolsClass"));
        PointCloudToolsClass->resize(1295, 802);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(85);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PointCloudToolsClass->sizePolicy().hasHeightForWidth());
        PointCloudToolsClass->setSizePolicy(sizePolicy);
        PointCloudToolsClass->setMinimumSize(QSize(900, 650));
        PointCloudToolsClass->setMaximumSize(QSize(16777215, 16777215));
        PointCloudToolsClass->setStyleSheet(QStringLiteral(""));
        PointCloudToolsClass->setAnimated(true);
        PointCloudToolsClass->setTabShape(QTabWidget::Rounded);
        PointCloudToolsClass->setDockNestingEnabled(false);
        openAction = new QAction(PointCloudToolsClass);
        openAction->setObjectName(QStringLiteral("openAction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        saveAction = new QAction(PointCloudToolsClass);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon1);
        saveasAction = new QAction(PointCloudToolsClass);
        saveasAction->setObjectName(QStringLiteral("saveasAction"));
        cubeAction = new QAction(PointCloudToolsClass);
        cubeAction->setObjectName(QStringLiteral("cubeAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/images/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        cubeAction->setIcon(icon2);
        helpAction = new QAction(PointCloudToolsClass);
        helpAction->setObjectName(QStringLiteral("helpAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpAction->setIcon(icon3);
        aboutAction = new QAction(PointCloudToolsClass);
        aboutAction->setObjectName(QStringLiteral("aboutAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Resources/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutAction->setIcon(icon4);
        exitAction = new QAction(PointCloudToolsClass);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Resources/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAction->setIcon(icon5);
        pointcolorAction = new QAction(PointCloudToolsClass);
        pointcolorAction->setObjectName(QStringLiteral("pointcolorAction"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Resources/images/pointcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointcolorAction->setIcon(icon6);
        bgcolorAction = new QAction(PointCloudToolsClass);
        bgcolorAction->setObjectName(QStringLiteral("bgcolorAction"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Resources/images/bgcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        bgcolorAction->setIcon(icon7);
        mainviewAction = new QAction(PointCloudToolsClass);
        mainviewAction->setObjectName(QStringLiteral("mainviewAction"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Resources/images/mainview.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainviewAction->setIcon(icon8);
        leftviewAction = new QAction(PointCloudToolsClass);
        leftviewAction->setObjectName(QStringLiteral("leftviewAction"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Resources/images/leftview.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftviewAction->setIcon(icon9);
        topviewAction = new QAction(PointCloudToolsClass);
        topviewAction->setObjectName(QStringLiteral("topviewAction"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Resources/images/topview.png"), QSize(), QIcon::Normal, QIcon::Off);
        topviewAction->setIcon(icon10);
        dataAction = new QAction(PointCloudToolsClass);
        dataAction->setObjectName(QStringLiteral("dataAction"));
        dataAction->setCheckable(true);
        dataAction->setChecked(true);
        propertyAction = new QAction(PointCloudToolsClass);
        propertyAction->setObjectName(QStringLiteral("propertyAction"));
        propertyAction->setCheckable(true);
        propertyAction->setChecked(true);
        consoleAction = new QAction(PointCloudToolsClass);
        consoleAction->setObjectName(QStringLiteral("consoleAction"));
        consoleAction->setCheckable(true);
        consoleAction->setChecked(true);
        RGBAction = new QAction(PointCloudToolsClass);
        RGBAction->setObjectName(QStringLiteral("RGBAction"));
        RGBAction->setCheckable(true);
        RGBAction->setChecked(true);
        clearAction = new QAction(PointCloudToolsClass);
        clearAction->setObjectName(QStringLiteral("clearAction"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Resources/images/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearAction->setIcon(icon11);
        sphereAction = new QAction(PointCloudToolsClass);
        sphereAction->setObjectName(QStringLiteral("sphereAction"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Resources/images/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        sphereAction->setIcon(icon12);
        cylinderAction = new QAction(PointCloudToolsClass);
        cylinderAction->setObjectName(QStringLiteral("cylinderAction"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Resources/images/sylinder.png"), QSize(), QIcon::Normal, QIcon::Off);
        cylinderAction->setIcon(icon13);
        meshsurfaceAction = new QAction(PointCloudToolsClass);
        meshsurfaceAction->setObjectName(QStringLiteral("meshsurfaceAction"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Resources/images/meshsurface.png"), QSize(), QIcon::Normal, QIcon::Off);
        meshsurfaceAction->setIcon(icon14);
        wireframeAction = new QAction(PointCloudToolsClass);
        wireframeAction->setObjectName(QStringLiteral("wireframeAction"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Resources/images/wireframe.png"), QSize(), QIcon::Normal, QIcon::Off);
        wireframeAction->setIcon(icon15);
        windowsThemeAction = new QAction(PointCloudToolsClass);
        windowsThemeAction->setObjectName(QStringLiteral("windowsThemeAction"));
        darculaThemeAction = new QAction(PointCloudToolsClass);
        darculaThemeAction->setObjectName(QStringLiteral("darculaThemeAction"));
        englishAction = new QAction(PointCloudToolsClass);
        englishAction->setObjectName(QStringLiteral("englishAction"));
        chineseAction = new QAction(PointCloudToolsClass);
        chineseAction->setObjectName(QStringLiteral("chineseAction"));
        saveBinaryAction = new QAction(PointCloudToolsClass);
        saveBinaryAction->setObjectName(QStringLiteral("saveBinaryAction"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Resources/images/saveBinary.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveBinaryAction->setIcon(icon16);
        filterAction = new QAction(PointCloudToolsClass);
        filterAction->setObjectName(QStringLiteral("filterAction"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Resources/images/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterAction->setIcon(icon17);
        voxelAction = new QAction(PointCloudToolsClass);
        voxelAction->setObjectName(QStringLiteral("voxelAction"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/Resources/images/voxel.png"), QSize(), QIcon::Normal, QIcon::Off);
        voxelAction->setIcon(icon18);
        centralWidget = new QWidget(PointCloudToolsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        screen = new QVTKWidget(centralWidget);
        screen->setObjectName(QStringLiteral("screen"));
        screen->setMinimumSize(QSize(600, 400));

        horizontalLayout_2->addWidget(screen);

        PointCloudToolsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PointCloudToolsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1295, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        menuBar->setFont(font);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuGenerate = new QMenu(menuBar);
        menuGenerate->setObjectName(QStringLiteral("menuGenerate"));
        menuBasic_shapes = new QMenu(menuGenerate);
        menuBasic_shapes->setObjectName(QStringLiteral("menuBasic_shapes"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/Resources/images/shape.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuBasic_shapes->setIcon(icon19);
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        themeAction = new QMenu(menuOption);
        themeAction->setObjectName(QStringLiteral("themeAction"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/Resources/images/theme.png"), QSize(), QIcon::Normal, QIcon::Off);
        themeAction->setIcon(icon20);
        langAction = new QMenu(menuOption);
        langAction->setObjectName(QStringLiteral("langAction"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/Resources/images/language.png"), QSize(), QIcon::Normal, QIcon::Off);
        langAction->setIcon(icon21);
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuAngle_view = new QMenu(menuView);
        menuAngle_view->setObjectName(QStringLiteral("menuAngle_view"));
        menuView_2 = new QMenu(menuBar);
        menuView_2->setObjectName(QStringLiteral("menuView_2"));
        menuProcess = new QMenu(menuBar);
        menuProcess->setObjectName(QStringLiteral("menuProcess"));
        PointCloudToolsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PointCloudToolsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PointCloudToolsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PointCloudToolsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PointCloudToolsClass->setStatusBar(statusBar);
        imageDock = new QDockWidget(PointCloudToolsClass);
        imageDock->setObjectName(QStringLiteral("imageDock"));
        imageDock->setMinimumSize(QSize(338, 584));
        imageDock->setMaximumSize(QSize(338, 524287));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        imageDepth = new QLabel(dockWidgetContents_4);
        imageDepth->setObjectName(QStringLiteral("imageDepth"));
        imageDepth->setMinimumSize(QSize(320, 240));
        imageDepth->setMaximumSize(QSize(320, 240));
        imageDepth->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageDepth);

        colormapBtn = new QPushButton(dockWidgetContents_4);
        colormapBtn->setObjectName(QStringLiteral("colormapBtn"));

        verticalLayout_2->addWidget(colormapBtn);

        imageColor = new QLabel(dockWidgetContents_4);
        imageColor->setObjectName(QStringLiteral("imageColor"));
        imageColor->setMinimumSize(QSize(320, 240));
        imageColor->setMaximumSize(QSize(320, 240));
        imageColor->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(imageColor);

        convertBtn = new QPushButton(dockWidgetContents_4);
        convertBtn->setObjectName(QStringLiteral("convertBtn"));

        verticalLayout_2->addWidget(convertBtn);

        imageDock->setWidget(dockWidgetContents_4);
        PointCloudToolsClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), imageDock);
        dataDock = new QDockWidget(PointCloudToolsClass);
        dataDock->setObjectName(QStringLiteral("dataDock"));
        dataDock->setMinimumSize(QSize(250, 150));
        dataDock->setMaximumSize(QSize(300, 524287));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        dataDock->setFont(font1);
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        dataTree = new QTreeWidget(dockWidgetContents_5);
        dataTree->setObjectName(QStringLiteral("dataTree"));
        dataTree->setMinimumSize(QSize(0, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        dataTree->setFont(font2);
        dataTree->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_3->addWidget(dataTree);

        dataDock->setWidget(dockWidgetContents_5);
        PointCloudToolsClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dataDock);
        propertyDock = new QDockWidget(PointCloudToolsClass);
        propertyDock->setObjectName(QStringLiteral("propertyDock"));
        sizePolicy1.setHeightForWidth(propertyDock->sizePolicy().hasHeightForWidth());
        propertyDock->setSizePolicy(sizePolicy1);
        propertyDock->setMinimumSize(QSize(250, 186));
        propertyDock->setMaximumSize(QSize(250, 186));
        propertyDock->setFont(font1);
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QStringLiteral("dockWidgetContents_6"));
        gridLayoutWidget = new QWidget(dockWidgetContents_6);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 231, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        fyLineedit = new QLineEdit(gridLayoutWidget);
        fyLineedit->setObjectName(QStringLiteral("fyLineedit"));

        gridLayout->addWidget(fyLineedit, 1, 1, 1, 1);

        k2Lineedit = new QLineEdit(gridLayoutWidget);
        k2Lineedit->setObjectName(QStringLiteral("k2Lineedit"));

        gridLayout->addWidget(k2Lineedit, 1, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        cxLineedit = new QLineEdit(gridLayoutWidget);
        cxLineedit->setObjectName(QStringLiteral("cxLineedit"));

        gridLayout->addWidget(cxLineedit, 2, 1, 1, 1);

        p1Lineedit = new QLineEdit(gridLayoutWidget);
        p1Lineedit->setObjectName(QStringLiteral("p1Lineedit"));

        gridLayout->addWidget(p1Lineedit, 2, 3, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        cyLineedit = new QLineEdit(gridLayoutWidget);
        cyLineedit->setObjectName(QStringLiteral("cyLineedit"));

        gridLayout->addWidget(cyLineedit, 3, 1, 1, 1);

        p2Lineedit = new QLineEdit(gridLayoutWidget);
        p2Lineedit->setObjectName(QStringLiteral("p2Lineedit"));

        gridLayout->addWidget(p2Lineedit, 3, 3, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        fxLineedit = new QLineEdit(gridLayoutWidget);
        fxLineedit->setObjectName(QStringLiteral("fxLineedit"));

        gridLayout->addWidget(fxLineedit, 0, 1, 1, 1);

        k1Lineedit = new QLineEdit(gridLayoutWidget);
        k1Lineedit->setObjectName(QStringLiteral("k1Lineedit"));

        gridLayout->addWidget(k1Lineedit, 0, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        aLineedit = new QLineEdit(gridLayoutWidget);
        aLineedit->setObjectName(QStringLiteral("aLineedit"));

        gridLayout->addWidget(aLineedit, 4, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        k3Lineedit = new QLineEdit(gridLayoutWidget);
        k3Lineedit->setObjectName(QStringLiteral("k3Lineedit"));

        gridLayout->addWidget(k3Lineedit, 4, 3, 1, 1);

        propertyDock->setWidget(dockWidgetContents_6);
        PointCloudToolsClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), propertyDock);
        consoleDock = new QDockWidget(PointCloudToolsClass);
        consoleDock->setObjectName(QStringLiteral("consoleDock"));
        consoleDock->setMinimumSize(QSize(200, 111));
        consoleDock->setMaximumSize(QSize(524287, 220));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        consoleTable = new QTableWidget(dockWidgetContents_7);
        if (consoleTable->columnCount() < 5)
            consoleTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        consoleTable->setObjectName(QStringLiteral("consoleTable"));
        consoleTable->setShowGrid(false);
        consoleTable->setGridStyle(Qt::SolidLine);
        consoleTable->setRowCount(0);
        consoleTable->setColumnCount(5);
        consoleTable->horizontalHeader()->setVisible(true);
        consoleTable->horizontalHeader()->setDefaultSectionSize(200);
        consoleTable->horizontalHeader()->setStretchLastSection(true);
        consoleTable->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(consoleTable);

        consoleDock->setWidget(dockWidgetContents_7);
        PointCloudToolsClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), consoleDock);
        RGBDock = new QDockWidget(PointCloudToolsClass);
        RGBDock->setObjectName(QStringLiteral("RGBDock"));
        RGBDock->setMinimumSize(QSize(250, 220));
        RGBDock->setMaximumSize(QSize(250, 220));
        RGBDock->setFont(font1);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        label_14 = new QLabel(dockWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout->addWidget(label_14);

        sizeLCD = new QLCDNumber(dockWidgetContents);
        sizeLCD->setObjectName(QStringLiteral("sizeLCD"));
        sizeLCD->setAutoFillBackground(false);
        sizeLCD->setStyleSheet(QStringLiteral("gridline-color: rgb(255, 0, 255);"));
        sizeLCD->setSegmentStyle(QLCDNumber::Flat);
        sizeLCD->setProperty("intValue", QVariant(1));

        horizontalLayout->addWidget(sizeLCD);


        verticalLayout->addLayout(horizontalLayout);

        pSlider = new QSlider(dockWidgetContents);
        pSlider->setObjectName(QStringLiteral("pSlider"));
        pSlider->setMinimum(1);
        pSlider->setMaximum(10);
        pSlider->setValue(1);
        pSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(pSlider);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 50));
        label_5->setFont(font1);
        label_5->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_6->addWidget(label_5);

        colormap_x = new QRadioButton(dockWidgetContents);
        colormap_x->setObjectName(QStringLiteral("colormap_x"));

        horizontalLayout_6->addWidget(colormap_x);

        colormap_y = new QRadioButton(dockWidgetContents);
        colormap_y->setObjectName(QStringLiteral("colormap_y"));

        horizontalLayout_6->addWidget(colormap_y);

        colormap_z = new QRadioButton(dockWidgetContents);
        colormap_z->setObjectName(QStringLiteral("colormap_z"));
        colormap_z->setChecked(true);

        horizontalLayout_6->addWidget(colormap_z);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        colorMapLeft = new QLineEdit(dockWidgetContents);
        colorMapLeft->setObjectName(QStringLiteral("colorMapLeft"));

        horizontalLayout_7->addWidget(colorMapLeft);

        colorMapRight = new QLineEdit(dockWidgetContents);
        colorMapRight->setObjectName(QStringLiteral("colorMapRight"));

        horizontalLayout_7->addWidget(colorMapRight);


        verticalLayout->addLayout(horizontalLayout_7);

        colorBtn = new QPushButton(dockWidgetContents);
        colorBtn->setObjectName(QStringLiteral("colorBtn"));
        QFont font3;
        font3.setFamily(QStringLiteral("Times New Roman"));
        font3.setPointSize(11);
        colorBtn->setFont(font3);
        colorBtn->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(colorBtn);


        verticalLayout_4->addLayout(verticalLayout);

        cooCbx = new QCheckBox(dockWidgetContents);
        cooCbx->setObjectName(QStringLiteral("cooCbx"));
        cooCbx->setFont(font1);

        verticalLayout_4->addWidget(cooCbx);

        RGBDock->setWidget(dockWidgetContents);
        PointCloudToolsClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), RGBDock);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(k1Lineedit);
        label_4->setBuddy(k2Lineedit);
        label_6->setBuddy(cxLineedit);
        label_8->setBuddy(cyLineedit);
        label_7->setBuddy(p1Lineedit);
        label_9->setBuddy(p2Lineedit);
        label_3->setBuddy(fyLineedit);
        label->setBuddy(fxLineedit);
        label_10->setBuddy(aLineedit);
        label_11->setBuddy(k3Lineedit);
        label_5->setBuddy(colormap_x);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(fxLineedit, fyLineedit);
        QWidget::setTabOrder(fyLineedit, cxLineedit);
        QWidget::setTabOrder(cxLineedit, cyLineedit);
        QWidget::setTabOrder(cyLineedit, aLineedit);
        QWidget::setTabOrder(aLineedit, k1Lineedit);
        QWidget::setTabOrder(k1Lineedit, k2Lineedit);
        QWidget::setTabOrder(k2Lineedit, p1Lineedit);
        QWidget::setTabOrder(p1Lineedit, p2Lineedit);
        QWidget::setTabOrder(p2Lineedit, k3Lineedit);
        QWidget::setTabOrder(k3Lineedit, colormap_x);
        QWidget::setTabOrder(colormap_x, colormap_y);
        QWidget::setTabOrder(colormap_y, colormap_z);
        QWidget::setTabOrder(colormap_z, colorMapLeft);
        QWidget::setTabOrder(colorMapLeft, colorMapRight);
        QWidget::setTabOrder(colorMapRight, colorBtn);
        QWidget::setTabOrder(colorBtn, cooCbx);
        QWidget::setTabOrder(cooCbx, consoleTable);
        QWidget::setTabOrder(consoleTable, dataTree);
        QWidget::setTabOrder(dataTree, convertBtn);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuView_2->menuAction());
        menuBar->addAction(menuGenerate->menuAction());
        menuBar->addAction(menuProcess->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(openAction);
        menuFile->addAction(clearAction);
        menuFile->addAction(saveAction);
        menuFile->addAction(saveBinaryAction);
        menuFile->addAction(exitAction);
        menuGenerate->addAction(cubeAction);
        menuGenerate->addAction(menuBasic_shapes->menuAction());
        menuBasic_shapes->addAction(sphereAction);
        menuBasic_shapes->addAction(cylinderAction);
        menuAbout->addAction(helpAction);
        menuAbout->addAction(aboutAction);
        menuOption->addAction(themeAction->menuAction());
        menuOption->addAction(langAction->menuAction());
        themeAction->addAction(windowsThemeAction);
        themeAction->addAction(darculaThemeAction);
        langAction->addAction(englishAction);
        langAction->addAction(chineseAction);
        menuView->addAction(pointcolorAction);
        menuView->addAction(bgcolorAction);
        menuView->addAction(menuAngle_view->menuAction());
        menuAngle_view->addAction(mainviewAction);
        menuAngle_view->addAction(leftviewAction);
        menuAngle_view->addAction(topviewAction);
        menuView_2->addAction(dataAction);
        menuView_2->addAction(propertyAction);
        menuView_2->addAction(consoleAction);
        menuView_2->addAction(RGBAction);
        menuProcess->addAction(meshsurfaceAction);
        menuProcess->addAction(wireframeAction);
        menuProcess->addAction(filterAction);
        menuProcess->addAction(voxelAction);
        mainToolBar->addAction(openAction);
        mainToolBar->addAction(clearAction);
        mainToolBar->addAction(saveAction);
        mainToolBar->addAction(saveBinaryAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(pointcolorAction);
        mainToolBar->addAction(bgcolorAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(mainviewAction);
        mainToolBar->addAction(leftviewAction);
        mainToolBar->addAction(topviewAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(cubeAction);
        mainToolBar->addAction(sphereAction);
        mainToolBar->addAction(cylinderAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(meshsurfaceAction);
        mainToolBar->addAction(wireframeAction);
        mainToolBar->addAction(filterAction);
        mainToolBar->addAction(voxelAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(helpAction);
        mainToolBar->addAction(aboutAction);

        retranslateUi(PointCloudToolsClass);

        QMetaObject::connectSlotsByName(PointCloudToolsClass);
    } // setupUi

    void retranslateUi(QMainWindow *PointCloudToolsClass)
    {
        PointCloudToolsClass->setWindowTitle(QApplication::translate("PointCloudToolsClass", "PointCloudTools", 0));
        openAction->setText(QApplication::translate("PointCloudToolsClass", "Open", 0));
#ifndef QT_NO_STATUSTIP
        openAction->setStatusTip(QApplication::translate("PointCloudToolsClass", "open a exsting file", 0));
#endif // QT_NO_STATUSTIP
        openAction->setShortcut(QApplication::translate("PointCloudToolsClass", "Ctrl+O", 0));
        saveAction->setText(QApplication::translate("PointCloudToolsClass", "Save", 0));
#ifndef QT_NO_STATUSTIP
        saveAction->setStatusTip(QApplication::translate("PointCloudToolsClass", "save the file", 0));
#endif // QT_NO_STATUSTIP
        saveAction->setShortcut(QApplication::translate("PointCloudToolsClass", "Ctrl+S", 0));
        saveasAction->setText(QApplication::translate("PointCloudToolsClass", "Save as...", 0));
        cubeAction->setText(QApplication::translate("PointCloudToolsClass", "Generate cube", 0));
#ifndef QT_NO_STATUSTIP
        cubeAction->setStatusTip(QApplication::translate("PointCloudToolsClass", "generate a cube point cloud", 0));
#endif // QT_NO_STATUSTIP
        helpAction->setText(QApplication::translate("PointCloudToolsClass", "Help", 0));
#ifndef QT_NO_STATUSTIP
        helpAction->setStatusTip(QApplication::translate("PointCloudToolsClass", "show help information", 0));
#endif // QT_NO_STATUSTIP
        aboutAction->setText(QApplication::translate("PointCloudToolsClass", "About", 0));
#ifndef QT_NO_STATUSTIP
        aboutAction->setStatusTip(QApplication::translate("PointCloudToolsClass", "show some information of the software", 0));
#endif // QT_NO_STATUSTIP
        exitAction->setText(QApplication::translate("PointCloudToolsClass", "Exit", 0));
        exitAction->setShortcut(QApplication::translate("PointCloudToolsClass", "Ctrl+Q", 0));
        pointcolorAction->setText(QApplication::translate("PointCloudToolsClass", "Point cloud color", 0));
        bgcolorAction->setText(QApplication::translate("PointCloudToolsClass", "Background color", 0));
        mainviewAction->setText(QApplication::translate("PointCloudToolsClass", "Main view", 0));
        leftviewAction->setText(QApplication::translate("PointCloudToolsClass", "Left view", 0));
        topviewAction->setText(QApplication::translate("PointCloudToolsClass", "Top view", 0));
        dataAction->setText(QApplication::translate("PointCloudToolsClass", "Data Manager", 0));
        propertyAction->setText(QApplication::translate("PointCloudToolsClass", "Property Manager", 0));
        consoleAction->setText(QApplication::translate("PointCloudToolsClass", "Console", 0));
        RGBAction->setText(QApplication::translate("PointCloudToolsClass", "RGB Manager", 0));
        clearAction->setText(QApplication::translate("PointCloudToolsClass", "Clear", 0));
        sphereAction->setText(QApplication::translate("PointCloudToolsClass", "Sphere", 0));
        cylinderAction->setText(QApplication::translate("PointCloudToolsClass", "Cylinder", 0));
        meshsurfaceAction->setText(QApplication::translate("PointCloudToolsClass", "Surface", 0));
        wireframeAction->setText(QApplication::translate("PointCloudToolsClass", "Wireframe", 0));
        windowsThemeAction->setText(QApplication::translate("PointCloudToolsClass", "Windows", 0));
        darculaThemeAction->setText(QApplication::translate("PointCloudToolsClass", "Darcula", 0));
        englishAction->setText(QApplication::translate("PointCloudToolsClass", "English", 0));
        chineseAction->setText(QApplication::translate("PointCloudToolsClass", "Chinese", 0));
        saveBinaryAction->setText(QApplication::translate("PointCloudToolsClass", "Save as binary", 0));
#ifndef QT_NO_STATUSTIP
        saveBinaryAction->setStatusTip(QApplication::translate("PointCloudToolsClass", "Save point cloud as binary file", 0));
#endif // QT_NO_STATUSTIP
        filterAction->setText(QApplication::translate("PointCloudToolsClass", "Filter", 0));
#ifndef QT_NO_TOOLTIP
        filterAction->setToolTip(QApplication::translate("PointCloudToolsClass", "Filter pointcloud", 0));
#endif // QT_NO_TOOLTIP
        voxelAction->setText(QApplication::translate("PointCloudToolsClass", "Voxel", 0));
#ifndef QT_NO_TOOLTIP
        voxelAction->setToolTip(QApplication::translate("PointCloudToolsClass", "VoxelGrid filter", 0));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("PointCloudToolsClass", "File", 0));
        menuGenerate->setTitle(QApplication::translate("PointCloudToolsClass", "Generate", 0));
        menuBasic_shapes->setTitle(QApplication::translate("PointCloudToolsClass", "Basic shapes", 0));
        menuAbout->setTitle(QApplication::translate("PointCloudToolsClass", "About", 0));
        menuOption->setTitle(QApplication::translate("PointCloudToolsClass", "Option", 0));
        themeAction->setTitle(QApplication::translate("PointCloudToolsClass", "Theme", 0));
        langAction->setTitle(QApplication::translate("PointCloudToolsClass", "Language", 0));
        menuView->setTitle(QApplication::translate("PointCloudToolsClass", "Display", 0));
        menuAngle_view->setTitle(QApplication::translate("PointCloudToolsClass", "Angle view", 0));
        menuView_2->setTitle(QApplication::translate("PointCloudToolsClass", "View", 0));
        menuProcess->setTitle(QApplication::translate("PointCloudToolsClass", "Process", 0));
        imageDock->setWindowTitle(QApplication::translate("PointCloudToolsClass", "Image", 0));
        imageDepth->setText(QApplication::translate("PointCloudToolsClass", "Depth Image", 0));
        colormapBtn->setText(QApplication::translate("PointCloudToolsClass", "Colormap", 0));
        imageColor->setText(QApplication::translate("PointCloudToolsClass", "Colormap Image", 0));
        convertBtn->setText(QApplication::translate("PointCloudToolsClass", "Convert", 0));
        dataDock->setWindowTitle(QApplication::translate("PointCloudToolsClass", "PointCloud", 0));
        QTreeWidgetItem *___qtreewidgetitem = dataTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("PointCloudToolsClass", "Point Cloud File", 0));
        propertyDock->setWindowTitle(QApplication::translate("PointCloudToolsClass", "Properties", 0));
        label_2->setText(QApplication::translate("PointCloudToolsClass", "k1", 0));
        fyLineedit->setText(QApplication::translate("PointCloudToolsClass", "1", 0));
        k2Lineedit->setText(QApplication::translate("PointCloudToolsClass", "0", 0));
        label_4->setText(QApplication::translate("PointCloudToolsClass", "k2", 0));
        label_6->setText(QApplication::translate("PointCloudToolsClass", "cx", 0));
        cxLineedit->setText(QApplication::translate("PointCloudToolsClass", "160", 0));
        p1Lineedit->setText(QApplication::translate("PointCloudToolsClass", "0", 0));
        label_8->setText(QApplication::translate("PointCloudToolsClass", "cy", 0));
        label_7->setText(QApplication::translate("PointCloudToolsClass", "p1", 0));
        label_9->setText(QApplication::translate("PointCloudToolsClass", "p2", 0));
        cyLineedit->setText(QApplication::translate("PointCloudToolsClass", "120", 0));
        p2Lineedit->setText(QApplication::translate("PointCloudToolsClass", "0", 0));
        label_3->setText(QApplication::translate("PointCloudToolsClass", "fy", 0));
        fxLineedit->setText(QApplication::translate("PointCloudToolsClass", "1", 0));
        k1Lineedit->setText(QApplication::translate("PointCloudToolsClass", "0", 0));
        label->setText(QApplication::translate("PointCloudToolsClass", "fx", 0));
        label_10->setText(QApplication::translate("PointCloudToolsClass", "\316\261", 0));
        aLineedit->setText(QApplication::translate("PointCloudToolsClass", "1", 0));
        label_11->setText(QApplication::translate("PointCloudToolsClass", "k3", 0));
        k3Lineedit->setText(QApplication::translate("PointCloudToolsClass", "0", 0));
        consoleDock->setWindowTitle(QApplication::translate("PointCloudToolsClass", "Console", 0));
        QTableWidgetItem *___qtablewidgetitem = consoleTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PointCloudToolsClass", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem1 = consoleTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PointCloudToolsClass", "Operation", 0));
        QTableWidgetItem *___qtablewidgetitem2 = consoleTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PointCloudToolsClass", "Operation obeject", 0));
        QTableWidgetItem *___qtablewidgetitem3 = consoleTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PointCloudToolsClass", "Details", 0));
        QTableWidgetItem *___qtablewidgetitem4 = consoleTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("PointCloudToolsClass", "Note", 0));
        RGBDock->setWindowTitle(QApplication::translate("PointCloudToolsClass", "RGB", 0));
        label_14->setText(QApplication::translate("PointCloudToolsClass", "Point Size", 0));
        label_5->setText(QApplication::translate("PointCloudToolsClass", "Color Map", 0));
        colormap_x->setText(QApplication::translate("PointCloudToolsClass", "X", 0));
        colormap_y->setText(QApplication::translate("PointCloudToolsClass", "Y", 0));
        colormap_z->setText(QApplication::translate("PointCloudToolsClass", "Z", 0));
        colorMapLeft->setText(QApplication::translate("PointCloudToolsClass", "0", 0));
        colorMapRight->setText(QApplication::translate("PointCloudToolsClass", "30000", 0));
        colorBtn->setText(QApplication::translate("PointCloudToolsClass", "Color", 0));
        cooCbx->setText(QApplication::translate("PointCloudToolsClass", "Coordinate", 0));
    } // retranslateUi

};

namespace Ui {
    class PointCloudToolsClass: public Ui_PointCloudToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTCLOUDTOOLS_H
