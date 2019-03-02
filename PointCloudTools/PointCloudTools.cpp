#include "PointCloudTools.h"

PointCloudTools::PointCloudTools(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	/******************* Slots connection of QMenuBar and QToolBar ************************/
	// File (connect)
	QObject::connect(ui.openAction, &QAction::triggered, this, &PointCloudTools::open);
	QObject::connect(ui.clearAction, &QAction::triggered, this, &PointCloudTools::clear);
	QObject::connect(ui.saveAction, &QAction::triggered, this, &PointCloudTools::save);
	QObject::connect(ui.saveBinaryAction, &QAction::triggered, this, &PointCloudTools::saveBinary);
	QObject::connect(ui.exitAction, &QAction::triggered, this, &PointCloudTools::exit);
	//Display (connect)
	QObject::connect(ui.pointcolorAction, &QAction::triggered, this, &PointCloudTools::pointcolorChanged);
	QObject::connect(ui.bgcolorAction, &QAction::triggered, this, &PointCloudTools::bgcolorChanged);
	QObject::connect(ui.mainviewAction, &QAction::triggered, this, &PointCloudTools::mainview);
	QObject::connect(ui.leftviewAction, &QAction::triggered, this, &PointCloudTools::leftview);
	QObject::connect(ui.topviewAction, &QAction::triggered, this, &PointCloudTools::topview);
	// View (connect)
	QObject::connect(ui.dataAction, &QAction::triggered, this, &PointCloudTools::data);
	QObject::connect(ui.propertyAction, &QAction::triggered, this, &PointCloudTools::properties);
	QObject::connect(ui.consoleAction, &QAction::triggered, this, &PointCloudTools::console);
	QObject::connect(ui.RGBAction, &QAction::triggered, this, &PointCloudTools::rgbDock);
	// Generate (connect)
	QObject::connect(ui.cubeAction, &QAction::triggered, this, &PointCloudTools::cube);
	QObject::connect(ui.sphereAction, &QAction::triggered, this, &PointCloudTools::createSphere);
	QObject::connect(ui.cylinderAction, &QAction::triggered, this, &PointCloudTools::createCylinder);
	// Process (connect)
	QObject::connect(ui.meshsurfaceAction, &QAction::triggered, this, &PointCloudTools::convertSurface);
	QObject::connect(ui.wireframeAction, &QAction::triggered, this, &PointCloudTools::convertWireframe);
	// Option (connect)
	QObject::connect(ui.windowsThemeAction, &QAction::triggered, this, &PointCloudTools::windowsTheme);
	QObject::connect(ui.darculaThemeAction, &QAction::triggered, this, &PointCloudTools::darculaTheme);
	QObject::connect(ui.englishAction, &QAction::triggered, this, &PointCloudTools::langEnglish);
	QObject::connect(ui.chineseAction, &QAction::triggered, this, &PointCloudTools::langChinese);
	// About (connect)
	QObject::connect(ui.aboutAction, &QAction::triggered, this, &PointCloudTools::about);
	QObject::connect(ui.helpAction, &QAction::triggered, this, &PointCloudTools::help);

	/***** Slots connection of image widget *****/
	connect(ui.colormapBtn, SIGNAL(clicked()), this, SLOT(colormapBtnPressed()));
	connect(ui.convertBtn, SIGNAL(clicked()), this, SLOT(convertBtnPressed()));

	/***** Slots connection of RGB widget *****/
	// Random color (connect)
	connect(ui.colorBtn, SIGNAL(clicked()), this, SLOT(colorBtnPressed()));
	// Change size of cloud (connect)
	connect(ui.pSlider, SIGNAL(valueChanged(int)), this, SLOT(pSliderChanged(int)));
	connect(ui.pSlider, SIGNAL(sliderReleased()), this, SLOT(psliderReleased()));
	// Change colormap properties (connect)
	connect(ui.colorMapRight, SIGNAL(editingFinished()), this, SLOT(colormap()));
	connect(ui.colorMapLeft, SIGNAL(editingFinished()), this, SLOT(colormap()));
	connect(ui.colormap_x, SIGNAL(clicked()), this, SLOT(colormap()));
	connect(ui.colormap_y, SIGNAL(clicked()), this, SLOT(colormap()));
	connect(ui.colormap_z, SIGNAL(clicked()), this, SLOT(colormap()));

	/***** Slots connection of dataTree(QTreeWidget) widget *****/
	// Item in dataTree is left-clicked (connect)
	connect(ui.dataTree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemSelected(QTreeWidgetItem*, int)));
	// Item in dataTree is right-clicked
	connect(ui.dataTree, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenu(const QPoint&)));

	connect(ui.consoleTable, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenuInConsole(const QPoint&)));
	// Initialization
	initial();
}

void PointCloudTools::open()
{
	QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Open image file"), QString::fromUtf8(mypicture->fullname.c_str()), tr("Depth Image(*.png);;PointCloud File(*.pcd *.ply);;All file(*.*)"));
	if (filenames.isEmpty())
		return;

	for (int i = 0; i != filenames.size(); i++)
	{
		timeStart();
		QString filename = filenames[i];
		std::string file_name = string(filename.toLocal8Bit());
		std::string subname = getFileName(file_name);
		std::string filetype = getFileType(file_name);

		//更新状态栏
		ui.statusBar->showMessage(QString::fromUtf8(subname.c_str()) + " : " + QString::number(i) + "/" + QString::number(filenames.size()) + " image open");

		int status = -1;
		if (filename.endsWith(".png", Qt::CaseInsensitive) || filename.endsWith(".bmp",Qt::CaseInsensitive))
		{
			mypicture = new MyPicture();

			// 图片打开
			cv::Mat img = cv::imread(file_name, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
			mypicture->fullname = file_name;
			mypicture->filename = subname;
			mypicture->filetype = filetype;
			mypicture->depthMat = img.clone();
			mypicture_vec.push_back(mypicture);

			//检查图像深度、通道
			if (img.type() != CV_16U)
			{
				int type = img.type();
				QString type_str = QString::number(type / 8 + 1) + "C";
				switch (type % 8)
				{
				case 0: type_str += "8U"; break;
				case 1: type_str += "8S"; break;
				case 2: type_str += "16U"; break;
				case 3: type_str += "16S"; break;
				case 4: type_str += "32S"; break;
				case 5: type_str += "32F"; break;
				case 6: type_str += "64F"; break;
				default: type_str += "Unknow";
					break;
				}
				consoleLog("Open", QString::fromLocal8Bit(subname.c_str()), "Image type:" + type_str, "Should open 16bits depth image.");
			}

			//深度图像显示
			cv::Mat zip;
			img.convertTo(zip, CV_8U, 1.0 / 256, 0);
			cv::resize(img, img, cv::Size(320, 240));
			QImage qimg = QImage((const unsigned char*)(zip.data), zip.cols, zip.rows, QImage::Format_Indexed8);
			ui.imageDepth->setPixmap(QPixmap::fromImage(qimg));
			//伪彩色图像清空
			ui.imageColor->clear();

			status = 0;

			//更新资源管理树
			QTreeWidgetItem *picName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(subname.c_str()));
			picName->setIcon(0, QIcon(":/Resources/images/pic.png"));
			ui.dataTree->addTopLevelItem(picName);
		}
		else
		{
			//点云打开
			if (filename.endsWith(".pcd", Qt::CaseInsensitive))
			{

			}
			else if (filename.endsWith(".ply", Qt::CaseInsensitive))
			{

			}
			else
			{

			}
		}

		QString time_cost = timeOff();
		consoleLog("Open", QString::fromLocal8Bit(subname.c_str()), QString::fromLocal8Bit(file_name.c_str()), "Time cost: " + time_cost + " s");

	}

	ui.statusBar->showMessage("");
	
}

void PointCloudTools::clear()
{

}

void PointCloudTools::save()
{

}

void PointCloudTools::saveBinary()
{

}

void PointCloudTools::exit()
{
	this->close();
}

void PointCloudTools::pointcolorChanged()
{

}

void PointCloudTools::bgcolorChanged()
{

}

void PointCloudTools::mainview()
{

}

void PointCloudTools::leftview()
{

}

void PointCloudTools::topview()
{

}

void PointCloudTools::data()
{

}

void PointCloudTools::properties()
{

}

void PointCloudTools::console()
{

}

void PointCloudTools::rgbDock()
{

}

void PointCloudTools::cube()
{

}

void PointCloudTools::createSphere()
{

}

void PointCloudTools::createCylinder()
{

}

int PointCloudTools::convertSurface()
{
	return 0;
}

int PointCloudTools::convertWireframe()
{
	return 0;
}

void PointCloudTools::windowsTheme()
{

}

void PointCloudTools::darculaTheme()
{

}

void PointCloudTools::langEnglish()
{

}

void PointCloudTools::langChinese()
{

}

void PointCloudTools::about()
{
	AboutWin *aboutwin = new AboutWin(this);
	aboutwin->setModal(true);
	aboutwin->show();

	consoleLog("About", "", "", "");
}

void PointCloudTools::help()
{

}

void PointCloudTools::colormapBtnPressed()
{
	ColormapWin *win = new ColormapWin();
	connect(win, SIGNAL(infoSend(ColormapClass)), this, SLOT(colormap(ColormapClass)));
	win->setModal(true);
	win->show();
}

void PointCloudTools::convertBtnPressed()
{
	if (mypicture->depthMat.empty())
		return;

	timeStart();

	double fx = ui.fxLineedit->text().toDouble();
	double fy = ui.fyLineedit->text().toDouble();
	double cx = ui.cxLineedit->text().toDouble();
	double cy = ui.cyLineedit->text().toDouble();
	double a = ui.aLineedit->text().toDouble();
	double k1 = ui.k1Lineedit->text().toDouble();
	double k2 = ui.k2Lineedit->text().toDouble();
	double p1 = ui.p1Lineedit->text().toDouble();
	double p2 = ui.p2Lineedit->text().toDouble();
	double k3 = ui.k3Lineedit->text().toDouble();

	//畸变矫正
	cv::Mat img;

	//内参矩阵
	cv::Mat cameraMatrix = cv::Mat::eye(3, 3, CV_64F);		//3*3单位矩阵
	cameraMatrix.at<double>(0, 0) = fx;
	cameraMatrix.at<double>(0, 1) = 0;
	cameraMatrix.at<double>(0, 2) = cx;
	cameraMatrix.at<double>(1, 1) = fy;
	cameraMatrix.at<double>(1, 2) = cy;
	cameraMatrix.at<double>(2, 2) = 1;
	//畸变参数
	cv::Mat distCoeffs = cv::Mat::zeros(5, 1, CV_64F);		//5*1全0矩阵
	distCoeffs.at<double>(0, 0) = k1;
	distCoeffs.at<double>(1, 0) = k2;
	distCoeffs.at<double>(2, 0) = p1;
	distCoeffs.at<double>(3, 0) = p2;
	distCoeffs.at<double>(4, 0) = k3;

	cv::Size imageSize = mypicture->depthMat.size();
	cv::Mat map1, map2;

	//参数1：相机内参矩阵
	//参数2：畸变矩阵
	//参数3：可选输入，第一和第二相机坐标之间的旋转矩阵
	//参数4：校正后的3X3相机矩阵
	//参数5：无失真图像尺寸
	//参数6：map1数据类型，CV_32FC1或CV_16SC2
	//参数7、8：输出X/Y坐标重映射参数
	initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(), cameraMatrix, imageSize, CV_32FC1, map1, map2);	//计算畸变映射
	//参数1：畸变原始图像
	//参数2：输出图像
	//参数3、4：X\Y坐标重映射
	//参数5：图像的插值方式
	//参数6：边界填充方式
	remap(mypicture->depthMat, img, map1, map2, cv::INTER_LINEAR);																	//畸变矫正

	//点云变换
	int imgWidth = img.size().width;
	int imgHeight = img.size().height;
	PointCloudT::Ptr pointcloud(new PointCloudT);

	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			float picDist = sqrt((i - imgHeight / 2.0)*(i - imgHeight / 2.0) + (j - imgWidth / 2.0)*(j - imgWidth / 2.0));	//图像上点到中心的像素点个数
			float picAngle = atan2(i - imgHeight / 2.0, j - imgWidth / 2.0);												//图像上x,y和中心点角度关系
			float angle = atan(sqrt((j - imgWidth / 2.0)*(j - imgWidth / 2.0) / fx / fx + (i - imgHeight / 2.0)*(i - imgHeight / 2.0) / fy / fy));
			float dist = img.at<ushort>(i, j) / a;				//原始图像深度

			pcl::PointXYZRGBA p;
			p.z = dist*cos(angle);									//坐标变换后的深度
			p.x = dist*sin(angle)*cos(picAngle);
			p.y = dist*sin(angle)*sin(picAngle);

			p.r = 250;
			p.g = 250;
			p.b = 250;
			p.a = 255;

			pointcloud->points.push_back(p);
		}
	}

	if (mypicture->isConvert)
	{
		for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
		{
			if ((*it)->fullname == mypicture->fullname + ".pcd")
			{
				(*it)->cloud = pointcloud;
				(*it)->visible = true;
				mycloud = *it;
				break;
			}
		}
	}
	else
	{
		mycloud = new MyCloud();
		mypicture->isConvert = true;
		mycloud->cloud = pointcloud;
		mycloud->filename = mypicture->filename + ".pcd";
		mycloud->fullname = mypicture->fullname + ".pcd";
		mycloud->filetype = "pcd";
		mycloud->visible = true;
		mycloud_vec.push_back(mycloud);

		//更新资源树
		QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(mycloud->filename.c_str()));
		cloudName->setIcon(0, QIcon(":/Resources/images/point.png"));
		ui.dataTree->addTopLevelItem(cloudName);
	}
	//计时结束
	QString time_cost = timeOff();
	consoleLog("Convert", QString::fromLocal8Bit(mypicture->filename.c_str()), QString::fromLocal8Bit(mycloud->filename.c_str()), "Time cost: " + time_cost + " s, Points: " + QString::number(mycloud->cloud->points.size()));
	

	showPointcloudAdd();		//更新点云窗口
}

void PointCloudTools::colormap(ColormapClass cc)
{
	if (mypicture->depthMat.empty())
		return;

	int max = cc.max;
	int min = cc.min;
	int type = cc.type;
	if (max < min)
	{
		QMessageBox::warning(this, "Warrning", "The max number is smaller than the min number!", QMessageBox::Yes);
		return;
	}

	timeStart();

	float scal = 255.0 / (max - min);
	cv::Mat colorMat;
	mypicture->depthMat.convertTo(colorMat, CV_8U, scal, -min*scal);		//转8位灰度
	cv::applyColorMap(colorMat, colorMat, type);						//转彩色图
	mypicture->colorMat = colorMat.clone();

	cv::cvtColor(colorMat, colorMat, CV_BGR2RGB);						//Opencv默认BGR存储，Qt需要RGB
	QImage qimg = QImage((const unsigned char*)(colorMat.data), colorMat.cols, colorMat.rows, QImage::Format_RGB888);
	ui.imageColor->setPixmap(QPixmap::fromImage(qimg));

	QString time_cost = timeOff();
	//信息显示
	QString type_str;
	switch (type)
	{
	case 0: type_str = "AUTUMN"; break;
	case 1: type_str = "BONE"; break;
	case 2: type_str = "JET"; break;
	case 4: type_str = "RAINBOW"; break;
	case 9: type_str = "HSV"; break;
	case 11: type_str = "HOT"; break;
	default:
		type_str = "";
		break;
	}
	consoleLog("Colormap", QString::fromLocal8Bit(mypicture->filename.c_str()), "Max: " + QString::number(max) + " Min: " + QString::number(min) + " Type:" + type_str, "Time cost: " + time_cost + " s");
}

void PointCloudTools::convert()
{

}

void PointCloudTools::pSliderChanged(int value)
{
	int p = value;
	ui.sizeLCD->display(p);
}

void PointCloudTools::pSliderReleased()
{
	
}

void PointCloudTools::colorBtnPressed()
{
	
}

void PointCloudTools::pColormap()
{

}

void PointCloudTools::itemSelected(QTreeWidgetItem*, int)
{

}

void PointCloudTools::popMenu(const QPoint&)
{
	QTreeWidgetItem* curItem = ui.dataTree->currentItem(); //获取当前被点击的节点
	if (curItem == NULL)return;           //这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
	QString name = curItem->text(0);
	int id = ui.dataTree->indexOfTopLevelItem(curItem);

	QAction hideItemAction("Hide", this);
	QAction showItemAction("Show", this);
	QAction deleteItemAction("Delete", this);
	QAction changeColorAction("Change color", this);

	connect(&hideItemAction, &QAction::triggered, this, &PointCloudTools::hideItem);
	connect(&showItemAction, &QAction::triggered, this, &PointCloudTools::showItem);
	connect(&deleteItemAction, &QAction::triggered, this, &PointCloudTools::deleteItem);
	connect(&changeColorAction, &QAction::triggered, this, &PointCloudTools::pointcolorChanged);

	QPoint pos;
	QMenu menu(ui.dataTree);
	menu.addAction(&hideItemAction);
	menu.addAction(&showItemAction);
	menu.addAction(&deleteItemAction);
	menu.addAction(&changeColorAction);
	
	if (getFileType(name.toStdString()) == "ply" || getFileType(name.toStdString()) == "pcd")
	{
		for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
		{
			if ((*it)->filename == name.toStdString())
			{
				if ((*it)->visible == true){
					menu.actions()[1]->setVisible(false);
					menu.actions()[0]->setVisible(true);
				}
				else{
					menu.actions()[1]->setVisible(true);
					menu.actions()[0]->setVisible(false);
				}
				break;
			}
		}
	}
	else
	{
		menu.actions()[0]->setVisible(false);
	}
		


	menu.exec(QCursor::pos()); //在当前鼠标位置显示
}

void PointCloudTools::hideItem()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	for (int i = 0; i != itemList.size(); i++)
	{
		//遍历选择的元素
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);
		if (getFileType(name.toStdString()) == "pcd" || getFileType(name.toStdString()) == "ply")
		{
			//只有点云文件有隐藏选项
			for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
			{
				if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
				{
					//匹配到点云
					(*it)->visible = false;
					consoleLog("Hide PointCloud", QString::fromLocal8Bit((*it)->filename.c_str()), QString::fromLocal8Bit((*it)->fullname.c_str()), "");

					break;
				}
			}
		}
	}

	showPointcloudAdd();

}

void PointCloudTools::showItem()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	for (int i = 0; i != itemList.size(); i++)
	{
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);
		if (getFileType(name.toStdString()) == "png")
		{
			// 选择图片
			for (auto it = mypicture_vec.begin(); it != mypicture_vec.end(); it++)
			{
				if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
				{
					//深度图显示
					mypicture = *it;
					cv::Mat zip;
					(*it)->depthMat.convertTo(zip, CV_8U, 1.0 / 256.0);
					cv::resize(zip, zip, cv::Size(320, 240));
					QImage qimg = QImage((const unsigned char*)(zip.data), zip.cols, zip.rows, QImage::Format_Indexed8);
					ui.imageDepth->setPixmap(QPixmap::fromImage(qimg));

					//伪彩色图显示
					if (!(*it)->colorMat.empty())
					{
						//已经转换过，直接显示
						cv::cvtColor(mypicture->colorMat, zip, CV_BGR2RGB);
						qimg = QImage((const unsigned char*)(zip.data), zip.cols, zip.rows, QImage::Format_RGB888);
						ui.imageColor->setPixmap(QPixmap::fromImage(qimg));
					}
					else
					{
						//没有转换过，留白
						ui.imageColor->clear();
					}

					consoleLog("Show Picture", QString::fromLocal8Bit(mypicture->filename.c_str()), QString::fromLocal8Bit(mypicture->fullname.c_str()), "");
					break;
				}
			}
		}
		else
		{
			//选择点云
			for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
			{
				if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
				{
					//匹配到点云
					(*it)->visible = true;

					consoleLog("Show PointCloud", QString::fromLocal8Bit((*it)->filename.c_str()), QString::fromLocal8Bit((*it)->fullname.c_str()), "");

					break;
				}
			}
		}
	}

	showPointcloudAdd();
}

void PointCloudTools::deleteItem()
{
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();
	for (int i = 0; i != selected_item_count; i++)
	{
		QTreeWidgetItem* curItem = itemList[i];
		QString name = curItem->text(0);

		if (getFileType(name.toStdString()) == "png")
		{
			// 选择图片
			for (auto it = mypicture_vec.begin(); it != mypicture_vec.end(); it++)
			{
				if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
				{
					consoleLog("Delete", QString::fromLocal8Bit((*it)->filename.c_str()), QString::fromLocal8Bit((*it)->fullname.c_str()), "");

					//判断是否正在使用
					if (mypicture->filename == (*it)->filename)
					{
						//清空显示区域
						ui.imageColor->clear();
						ui.imageDepth->clear();
						mypicture = new MyPicture();
					}

					//内存中清空
					mypicture_vec.erase(it);

					break;
				}
			}
		}
		else
		{
			//选择点云
			for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
			{
				if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
				{
					//匹配到点云
					(*it)->visible = true;
					break;
				}
			}
		}

		//更新dataTree
		delete curItem;
	}

	showPointcloudAdd();

}

void PointCloudTools::popMenuInConsole(const QPoint&)
{

}

void PointCloudTools::clearConsole()
{

}

void PointCloudTools::enableConsole()
{

}

void PointCloudTools::disableConsole()
{

}

void PointCloudTools::initial()
{
	//界面初始化
	setWindowIcon(QIcon(tr(":Resources/images/logo.png")));
	setWindowTitle(tr("PointCloud Tools"));

	mypicture = new MyPicture();

	//点云初始化
	mycloud = new MyCloud();
	mycloud->cloud.reset(new PointCloudT);
	mycloud->cloud->resize(1);
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));

	//点云点击事件回调设置
	clicked_points.reset(new PointCloudT);
	viewer->registerPointPickingCallback(&PointCloudTools::pp_callback, *this, NULL);

	//点云ui界面元素绑定
	ui.screen->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.screen->GetInteractor(), ui.screen->GetRenderWindow());
	ui.screen->update();
	//设置背景颜色
	viewer->setBackgroundColor(30 / 255.0, 30 / 255.0, 30 / 255.0);

	ui.consoleTable->setSelectionMode(QAbstractItemView::NoSelection);		//禁止点击输出窗口的item
	ui.dataTree->setSelectionMode(QAbstractItemView::ExtendedSelection);	//允许dataTree多选

	setConsoleTable();

	//设置默认主题
	QString qss = windows_qss;
	qApp->setStyleSheet(qss);

	//读取config.ini，配置内参和畸变系数
	setConvertParameters();

	// 输出窗口
	consoleLog("Software start", "PointCloud Tools", "Welcome to use PointCloud Tools", "Haden");

}

void PointCloudTools::setConsoleTable(){
	// 设置输出窗口
	QStringList header2;
	header2 << "Time" << "Operation" << "Operation obeject" << "Details" << "Note";
	ui.consoleTable->setHorizontalHeaderLabels(header2);
	ui.consoleTable->setColumnWidth(0, 150);
	ui.consoleTable->setColumnWidth(1, 200);
	ui.consoleTable->setColumnWidth(2, 200);
	ui.consoleTable->setColumnWidth(3, 300);

	//ui.consoleTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
	ui.consoleTable->verticalHeader()->setDefaultSectionSize(22); //设置行距

	ui.consoleTable->setContextMenuPolicy(Qt::CustomContextMenu);

}

void PointCloudTools::setConvertParameters()
{
	QFile file("config.ini");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		int count = 0;
		while (!file.atEnd())
		{
			QByteArray line = file.readLine();
			if (line[0] == '\n') 
				break;

			if (line[0] != '#')
			{
				QString str(line);
				switch (count++)
				{
				case 0: ui.fxLineedit->setText(str); break;
				case 1: ui.fyLineedit->setText(str); break;
				case 2: ui.cxLineedit->setText(str); break;
				case 3: ui.cyLineedit->setText(str); break;
				case 4: ui.aLineedit->setText(str);  break;
				case 5: ui.k1Lineedit->setText(str); break;
				case 6: ui.k2Lineedit->setText(str); break;
				case 7: ui.p1Lineedit->setText(str); break;
				case 8: ui.p2Lineedit->setText(str); break;
				case 9: ui.k3Lineedit->setText(str); break;
				default:
					break;
				}
			}
		}
		file.close();
	}
}

void PointCloudTools::consoleLog(QString operation, QString object, QString details, QString note)
{
	if (enable_console == false)
		return;

	int rows = ui.consoleTable->rowCount();
	int new_rows = rows + 1;
	ui.consoleTable->setRowCount(new_rows);
	QDateTime time = QDateTime::currentDateTime();		//获取系统时间
	QString time_str = time.toString("MM-dd hh:mm:ss");	//标准化显示时间
	ui.consoleTable->setItem(rows, 0, new QTableWidgetItem(time_str));
	ui.consoleTable->setItem(rows, 1, new QTableWidgetItem(operation));
	ui.consoleTable->setItem(rows, 2, new QTableWidgetItem(object));
	ui.consoleTable->setItem(rows, 3, new QTableWidgetItem(details));
	ui.consoleTable->setItem(rows, 4, new QTableWidgetItem(note));

	ui.consoleTable->scrollToBottom();					//滑动到底部
}

void PointCloudTools::gray2rainbow(float value, int min, int max, uint8_t* r, uint8_t* g, uint8_t* b)
{

}

void PointCloudTools::pp_callback(const pcl::visualization::PointPickingEvent& event, void *args)
{
	if (event.getPointIndex() == -1)
		return;

	pcl::PointXYZRGBA current_point;
	event.getPoint(current_point.x, current_point.y, current_point.z);
	clicked_points->points.clear();
	clicked_points->points.push_back(current_point);

	// 红色点标出选择点
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGBA> red(clicked_points, 255, 0, 0);
	viewer->removePointCloud("clicked_points");
	viewer->addPointCloud(clicked_points, red, "clicked_points");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "clicked_points");

	QString details = QString("X:%1 Y:%2 Z:%3").arg((int)current_point.x, 5, 10, QLatin1Char(' ')).arg((int)current_point.y, 5, 10, QLatin1Char(' ')).arg((int)current_point.z, 5, 10, QLatin1Char(' '));
	consoleLog("Choose point", "", details, "");
}

//添加点云到viewer,并显示点云
void PointCloudTools::showPointcloudAdd()
{
	viewer->removeAllPointClouds();
	for (int i = 0; i != mycloud_vec.size(); i++)
	{
		if (mycloud_vec[i]->visible)
		{
			viewer->addPointCloud(mycloud_vec[i]->cloud, "cloud" + QString::number(i).toStdString());
			viewer->updatePointCloud(mycloud_vec[i]->cloud, "cloud" + QString::number(i).toStdString());
		}
	}
	viewer->resetCamera();
	ui.screen->update();
}