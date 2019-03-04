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
	QObject::connect(ui.filterAction, &QAction::triggered, this, &PointCloudTools::convertFilter);
	QObject::connect(ui.voxelAction, &QAction::triggered, this, &PointCloudTools::convertVoxel);
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
	connect(ui.colorBtn, SIGNAL(clicked()), this, SLOT(pColormap()));
	// Change size of cloud (connect)
	connect(ui.pSlider, SIGNAL(valueChanged(int)), this, SLOT(pSliderChanged(int)));
	connect(ui.pSlider, SIGNAL(sliderReleased()), this, SLOT(pSliderReleased()));
	// Change colormap properties (connect)
	connect(ui.colorMapRight, SIGNAL(editingFinished()), this, SLOT(pColormap()));
	connect(ui.colorMapLeft, SIGNAL(editingFinished()), this, SLOT(pColormap()));
	connect(ui.colormap_x, SIGNAL(clicked()), this, SLOT(pColormap()));
	connect(ui.colormap_y, SIGNAL(clicked()), this, SLOT(pColormap()));
	connect(ui.colormap_z, SIGNAL(clicked()), this, SLOT(pColormap()));
	// Checkbox for coordinate and background color (connect)
	connect(ui.cooCbx, SIGNAL(stateChanged(int)), this, SLOT(cooCbxChecked(int)));

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
		std::string dirname = getFileDir(file_name);

		//更新状态栏
		ui.statusBar->showMessage(QString::fromUtf8(subname.c_str()) + " : " + QString::number(i) + "/" + QString::number(filenames.size()) + " image or pointcloud open");

		int status = -1;
		if (filename.endsWith(".png", Qt::CaseInsensitive) || filename.endsWith(".bmp",Qt::CaseInsensitive))
		{
			mypicture = new MyPicture();

			// 图片打开
			cv::Mat img = cv::imread(file_name, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
			mypicture->fullname = file_name;
			mypicture->filename = subname;
			mypicture->filetype = filetype;
			mypicture->dirname = dirname;
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
			img.convertTo(zip, CV_8U, -1.0 / 256, 0);
			cv::resize(img, img, cv::Size(320, 240));
			QImage qimg = QImage((const unsigned char*)(zip.data), zip.cols, zip.rows, QImage::Format_Indexed8);
			ui.imageDepth->setPixmap(QPixmap::fromImage(qimg));
			//伪彩色图像清空
			ui.imageColor->clear();
			//更新标题
			ui.imageDock->setWindowTitle(QString::fromLocal8Bit(mypicture->filename.c_str()));

			status = 0;

			//更新资源管理树
			QTreeWidgetItem *picName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(subname.c_str()));
			picName->setIcon(0, QIcon(":/Resources/images/pic.png"));
			ui.dataTree->addTopLevelItem(picName);

			//结果显示
			QString time_cost = timeOff();
			consoleLog("Open", QString::fromLocal8Bit(subname.c_str()), QString::fromLocal8Bit(file_name.c_str()), "Time cost: " + time_cost + " s");
		}
		else
		{
			//TODO 点云文件读取
			//TODO 点云名字重复处理方法

			mycloud = new MyCloud();
			mycloud->fullname = file_name;
			mycloud->filename = subname;
			mycloud->filetype = filetype;
			mycloud->dirname = dirname;
			mycloud->cloud.reset(new PointCloudT);

			//点云打开
			if (filename.endsWith(".pcd", Qt::CaseInsensitive))
			{
				status = pcl::io::loadPCDFile(file_name, *(mycloud->cloud));
				if (mycloud->cloud->points[0].r == 0 && mycloud->cloud->points[0].g == 0 && mycloud->cloud->points[0].b == 0)
				{
					setCloudColor(255, 255, 255);
				}
			}
			else if (filename.endsWith(".ply", Qt::CaseInsensitive))
			{
				status = pcl::io::loadPLYFile(file_name, *(mycloud->cloud));
				if (mycloud->cloud->points[0].r == 0 && mycloud->cloud->points[0].g == 0 && mycloud->cloud->points[0].b == 0)
				{
					setCloudColor(255, 255, 255);
				}
			}
			else
			{
				//文件格式不能处理
				QMessageBox::information(this, tr("File format error"), tr("Can not open files excpet .png .pcd .ply"));
				return;
			}

			if (status != 0)
			{
				QMessageBox::critical(this, tr("Reading file error"), tr("We can not open the file"));
				return;
			}
			setA(255);

			mycloud_vec.push_back(mycloud);

			//更新资源管理树
			QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(subname.c_str()));
			cloudName->setIcon(0, QIcon(":/Resources/images/point.png"));
			ui.dataTree->addTopLevelItem(cloudName);

			//结果输出
			QString time_cost = timeOff();
			consoleLog("Open", QString::fromLocal8Bit(subname.c_str()), QString::fromLocal8Bit(file_name.c_str()), "Time cost: " + time_cost + " s; Load points:" + QString::number(mycloud->cloud->size()));
		}

		

	}

	showPointcloudAdd();

	ui.statusBar->showMessage("");
	
}

void PointCloudTools::clear()
{
	mycloud_vec.clear();			//点云容器中移除所有点
	mypicture_vec.clear();			//从图像容器中移除所有内容
	viewer->removeAllPointClouds();	//从viewer中移除所有点云
	viewer->removeAllShapes();
	ui.dataTree->clear();

	mypicture = new MyPicture();

	consoleLog("Clear", "All point clouds and picture", "", "");

	//显示更新
	ui.imageDepth->clear();
	ui.imageColor->clear();
	showPointcloudAdd();
}

void PointCloudTools::save()
{
	QString save_filename = QFileDialog::getSaveFileName(this, tr("Save point cloud"), QString::fromLocal8Bit(mycloud->dirname.c_str()), tr("Point Cloud data(*.pcd *.ply);;All File(*.*)"));
	std::string file_name = save_filename.toStdString();
	std::string subname = getFileName(file_name);

	//文件名为空直接返回
	if (save_filename.isEmpty())
		return;

	//保存操作
	int status = saveFile(false, save_filename);
	if (status != 0)
		return;

	//输出窗口
	consoleLog("Save", QString::fromLocal8Bit(subname.c_str()), save_filename, "PointCloud save");
}

void PointCloudTools::saveBinary()
{
	QString save_filename = QFileDialog::getSaveFileName(this, tr("Save point cloud"), QString::fromLocal8Bit(mycloud->dirname.c_str()), tr("Point Cloud data(*.pcd *.ply);;All File(*.*)"));
	std::string file_name = save_filename.toStdString();
	std::string subname = getFileName(file_name);

	//文件名为空直接返回
	if (save_filename.isEmpty())
		return;

	//保存操作
	int status = saveFile(true, save_filename);
	if (status != 0)
		return;

	//输出窗口
	consoleLog("Save Binary", QString::fromLocal8Bit(subname.c_str()), save_filename, "PointCloud save");
}

int PointCloudTools::saveFile(bool save_as_binary,QString save_filename)
{
	std::string file_name = save_filename.toStdString();
	std::string subname = getFileName(file_name);

	PointCloudT::Ptr multi_cloud;
	multi_cloud.reset(new PointCloudT);
	multi_cloud->height = 1;
	int sum = 0;
	for (auto c : mycloud_vec)
	{
		//显示的点云放入缓冲区
		if (c->visible)
			sum += c->cloud->points.size();
	}

	//检查是否为空
	if (sum == 0)
	{
		QMessageBox::information(this, "Save Error", "No point cloud data.", QMessageBox::Yes);
		return -1;
	}

	multi_cloud->width = sum;
	multi_cloud->resize(multi_cloud->height * multi_cloud->width);
	int k = 0;
	for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
	{
		for (int i = 0; i != (*it)->cloud->size(); i++)
		{
			multi_cloud->points[k].x = (*it)->cloud->points[i].x;
			multi_cloud->points[k].y = (*it)->cloud->points[i].y;
			multi_cloud->points[k].z = (*it)->cloud->points[i].z;
			multi_cloud->points[k].r = (*it)->cloud->points[i].r;
			multi_cloud->points[k].g = (*it)->cloud->points[i].g;
			multi_cloud->points[k].b = (*it)->cloud->points[i].b;
			k++;
		}
	}
	//保存
	int status = -1;
	if (save_filename.endsWith(".pcd", Qt::CaseInsensitive))
	{
		if (save_as_binary)
		{
			status = pcl::io::savePCDFileBinary(save_filename.toStdString(), *multi_cloud);
		}
		else
		{
			status = pcl::io::savePCDFile(save_filename.toStdString(), *multi_cloud);
		}
	}
	else if (save_filename.endsWith(".ply", Qt::CaseInsensitive))
	{
		if (save_as_binary)
		{
			status = pcl::io::savePLYFileBinary(save_filename.toStdString(), *multi_cloud);
		}
		else
		{
			status = pcl::io::savePLYFile(save_filename.toStdString(), *multi_cloud);
		}
	}
	else
	{
		//无法保存除.ply .pcd外文件
		QMessageBox::information(this, tr("File format error"), tr("Can not save file except .ply .pcd"),QMessageBox::Yes);
		return -1;
	}

	//提示：后缀没问题，但是无法保存
	if (status != 0)
	{
		QMessageBox::critical(this, tr("Saving file error"), tr("We can not save the file"));
		return -1;
	}

	return 0;
}

void PointCloudTools::exit()
{
	this->close();
}

void PointCloudTools::pointcolorChanged()
{
	QColor color = QColorDialog::getColor(Qt::white, this, "Select color for point cloud");

	if (color.isValid()) //判断所选的颜色是否有效
	{
		//QAction* action = dynamic_cast<QAction*>(sender());
		//if (action != ui.pointcolorAction) //改变颜色的信号来自于 dataTree
		QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
		int selected_item_count = ui.dataTree->selectedItems().size();
		if (selected_item_count == 0){
			//改变所有点颜色
			for (int i = 0; i != mycloud_vec.size(); i++){
				for (int j = 0; j != mycloud_vec[i]->cloud->points.size(); j++){
					mycloud_vec[i]->cloud->points[j].r = color.red();
					mycloud_vec[i]->cloud->points[j].g = color.green();
					mycloud_vec[i]->cloud->points[j].b = color.blue();
				}
			}
			// 输出窗口
			consoleLog("Change cloud color", "All point clouds", QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
		}
		else{
			for (int i = 0; i != selected_item_count; i++){
				QString name = itemList[i]->text(0);
				//遍历mycloud_vec
				for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
				{
					//找到同名点云数据
					if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
					{
						for (int j = 0; j != (*it)->cloud->size(); j++)
						{
							(*it)->cloud->points[j].r = color.red();
							(*it)->cloud->points[j].g = color.green();
							(*it)->cloud->points[j].b = color.blue();
						}

						break;
					}
				}
			}
			// 输出窗口
			consoleLog("Change cloud color", "Point clouds selected", QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
		}

		showPointcloudAdd();
	}
}

void PointCloudTools::bgcolorChanged()
{
	QColor color = QColorDialog::getColor(Qt::white, this,
		"Select color for point cloud");
	if (color.isValid())
	{
		viewer->setBackgroundColor(color.red() / 255.0,
			color.green() / 255.0, color.blue() / 255.0);
		// 输出窗口
		consoleLog("Change bg color", "Background", QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
		showPointcloudAdd();
	}
}

void PointCloudTools::mainview()
{
	viewer->setCameraPosition(0, -1, 0, 0.5, 0.5, 0.5, 0, 0, 1);
	ui.screen->update();
}

void PointCloudTools::leftview()
{
	viewer->setCameraPosition(-1, 0, 0, 0, 0, 0, 0, 0, 1);
	ui.screen->update();
}

void PointCloudTools::topview()
{
	viewer->setCameraPosition(0, 0, 1, 0, 0, 0, 0, 1, 0);
	ui.screen->update();
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
	clear();
	
	mycloud = new MyCloud();
	mycloud->filename = "cube.pcd";
	mycloud->filetype = "pcd";
	mycloud->fullname = QDir::currentPath().toStdString() + mycloud->filename;
	mycloud->dirname = QDir::currentPath().toStdString();
	//点云数据
	mycloud->cloud.reset(new PointCloudT);
	mycloud->cloud->width = 50000;			//点云宽
	mycloud->cloud->height = 1;				//点云高，1为无组织点云
	mycloud->cloud->is_dense = false;
	mycloud->cloud->resize(mycloud->cloud->width * mycloud->cloud->height);		//重置点云大小
	for (size_t i = 0; i != mycloud->cloud->size(); i++)
	{
		mycloud->cloud->points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud->cloud->points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud->cloud->points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud->cloud->points[i].r = 255;
		mycloud->cloud->points[i].g = 255;
		mycloud->cloud->points[i].b = 255;
	}

	mycloud_vec.push_back(mycloud);

	//设置资源管理
	QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(mycloud->filename.c_str()));
	cloudName->setIcon(0, QIcon(":/Resources/images/point.png"));
	ui.dataTree->addTopLevelItem(cloudName);

	//输出窗口
	consoleLog("Generate cube",QString::fromLocal8Bit(mycloud->filename.c_str()), "cube", "");

	showPointcloudAdd();
}

void PointCloudTools::createSphere()
{
	clear();

	mycloud = new MyCloud();
	mycloud->filename = "sphere.pcd";
	mycloud->filetype = "pcd";
	mycloud->fullname = QDir::currentPath().toStdString() + mycloud->filename;
	mycloud->dirname = QDir::currentPath().toStdString();
	//点云数据
	mycloud->cloud.reset(new PointCloudT);
	mycloud->cloud->width = 50000;			//点云宽
	mycloud->cloud->height = 1;				//点云高，1为无组织点云
	mycloud->cloud->is_dense = false;
	mycloud->cloud->resize(mycloud->cloud->width * mycloud->cloud->height);		//重置点云大小
	for (size_t i = 0; i != mycloud->cloud->size(); i++)
	{
		double sphere_r = 1024 * rand() / (RAND_MAX + 1.0f);		//半径
		double sphere_a = 6.2831852 * rand() / (RAND_MAX + 1.0f);	//旋转角度
		double sphere_t = 6.2831852 * rand() / (RAND_MAX + 1.0f);	//上下角度
		mycloud->cloud->points[i].x = sphere_r * sin(sphere_a) * sin(sphere_t);
		mycloud->cloud->points[i].y = sphere_r * sin(sphere_a) * cos(sphere_t);
		mycloud->cloud->points[i].z = sphere_r * cos(sphere_a);
		mycloud->cloud->points[i].r = 255;
		mycloud->cloud->points[i].g = 255;
		mycloud->cloud->points[i].b = 255;
	}

	mycloud_vec.push_back(mycloud);

	//设置资源管理
	QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(mycloud->filename.c_str()));
	cloudName->setIcon(0, QIcon(":/Resources/images/point.png"));
	ui.dataTree->addTopLevelItem(cloudName);

	//输出窗口
	consoleLog("Generate sphere", QString::fromLocal8Bit(mycloud->filename.c_str()), "sphere", "");

	showPointcloudAdd();
}

void PointCloudTools::createCylinder()
{
	clear();

	mycloud = new MyCloud();
	mycloud->filename = "cylinder.pcd";
	mycloud->filetype = "pcd";
	mycloud->fullname = QDir::currentPath().toStdString() + mycloud->filename;
	mycloud->dirname = QDir::currentPath().toStdString();
	//点云数据
	mycloud->cloud.reset(new PointCloudT);
	mycloud->cloud->width = 50000;			//点云宽
	mycloud->cloud->height = 1;				//点云高，1为无组织点云
	mycloud->cloud->is_dense = false;
	mycloud->cloud->resize(mycloud->cloud->width * mycloud->cloud->height);		//重置点云大小
	for (size_t i = 0; i != mycloud->cloud->size(); i++)
	{
		double sphere_r = 512 * rand() / (RAND_MAX + 1.0f);		//半径
		double sphere_t = 6.2831852 * rand() / (RAND_MAX + 1.0f);	//旋转角度
		mycloud->cloud->points[i].x = sphere_r * sin(sphere_t);
		mycloud->cloud->points[i].y = sphere_r *  cos(sphere_t);
		mycloud->cloud->points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
		mycloud->cloud->points[i].r = 255;
		mycloud->cloud->points[i].g = 255;
		mycloud->cloud->points[i].b = 255;
	}

	mycloud_vec.push_back(mycloud);

	//设置资源管理
	QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(mycloud->filename.c_str()));
	cloudName->setIcon(0, QIcon(":/Resources/images/point.png"));
	ui.dataTree->addTopLevelItem(cloudName);

	//输出窗口
	consoleLog("Generate cylinder", QString::fromLocal8Bit(mycloud->filename.c_str()), "cylinder", "");

	showPointcloudAdd();
}

int PointCloudTools::convertSurface()
{
	pcl::PointXYZ point;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>);
	for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
	{
		//遍历所有显示的点
		if ((*it)->visible)
		{
			for (int i = 0; i < (*it)->cloud->size(); i++)
			{
				point.x = (*it)->cloud->points[i].x;
				point.y = (*it)->cloud->points[i].y;
				point.z = (*it)->cloud->points[i].z;
				cloud_xyz->push_back(point);
			}
		}
	}
	//检查点云数据
	if (cloud_xyz->size() == 0)
	{
		QMessageBox::critical(this, "Error", "No point cloud data.", QMessageBox::Yes);
		return -1;
	}

	//法向估计
	ui.statusBar->showMessage("Convert surface: Normal estimation.");
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;									//构建法线估计对象n
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);			//构建法向数据指针
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);	//创建kdtree用于法向计算
	tree->setInputCloud(cloud_xyz);			//为kdtree输入点云
	n.setInputCloud(cloud_xyz);				//法向估计输入点云
	n.setSearchMethod(tree);				//设置法向估计搜索方法	
	n.setKSearch(20);						//设置k邻近搜索点数			//TODO 改可变参数
	n.compute(*normals);					//法向估计

	QMessageBox::information(this, "information", "Normal estimation finished");

	//点云数据与法向数据拼接
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);		//创建同时包含点和法线的数据结构的指针
	pcl::concatenateFields(*cloud_xyz, *normals, *cloud_with_normals);										//将已获得的点数据和法向数据拼接
	pcl::search::KdTree<pcl::PointNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointNormal>);			//创建另一个kdtree用于重建
	tree2->setInputCloud(cloud_with_normals);																//为kdtree输入点云数据，该点云数据类型为点和法向

	//曲面重构
	ui.statusBar->showMessage("Convert surface: Greedy projection triangulation");
	pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;		//创建贪婪三角形投影重建对象
	pcl::PolygonMesh triangles;										//创建多边形网格对象，用来存储重建结果
	//设置参数
	//TODO 参数化
	gp3.setSearchRadius(25);				//设置连接点之间最大距离，用于确定k近邻的球半径	
	gp3.setMu(2.5);							//设置最近邻距离的乘子，以得到每个点的最终搜索半径
	gp3.setMaximumNearestNeighbors(100);	//设置搜索的最近邻点的最大数量
	gp3.setMaximumSurfaceAngle(M_PI / 2);	//45度 最大平面角
	gp3.setMinimumAngle(M_PI / 18);			//10度 每个三角的最大角度？
	gp3.setMaximumAngle(2 * M_PI / 3);		//120度
	gp3.setNormalConsistency(false);		//若法向量一致，设为true
	//设置点云数据和搜索方式
	gp3.setInputCloud(cloud_with_normals);
	gp3.setSearchMethod(tree2);
	// 开始重建
	gp3.reconstruct(triangles);
	QMessageBox::information(this, "informaiton", "Reconstruction finished");

	//重建完成，显示
	ui.statusBar->showMessage("");
	viewer->addPolygonMesh(triangles, "my"); //设置要显示的网格对象
	//设置网格模型显示模式
	viewer->setRepresentationToSurfaceForAllActors();		//网格模型以面片形式显示		//TODO 参数选择
	//viewer->setRepresentationToPointsForAllActors();		//网格模型以点形式显示
	//viewer->setRepresentationToWireframeForAllActors();	//网格模型以线框图模式显示

	// 输出窗口
	consoleLog("Convert surface", "", "", "");

	viewer->removeAllShapes();


	return 0;
}

int PointCloudTools::convertWireframe()
{
	pcl::PointXYZ point;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>);
	for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
	{
		//遍历所有显示的点
		if ((*it)->visible)
		{
			for (int i = 0; i < (*it)->cloud->size(); i++)
			{
				point.x = (*it)->cloud->points[i].x;
				point.y = (*it)->cloud->points[i].y;
				point.z = (*it)->cloud->points[i].z;
				cloud_xyz->push_back(point);
			}
		}
	}

	//检查点云数据
	if (cloud_xyz->size() == 0)
	{
		QMessageBox::critical(this, "Error", "No point cloud data.", QMessageBox::Yes);
		return -1;
	}

	//法向估计
	ui.statusBar->showMessage("Convert wireframe: Normal estimation.");
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;									//创建法线估计对象 n
	pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);			//创建法向数据指针 normals
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);	//创建 kdtree 用于法向计算时近邻搜索
	tree->setInputCloud(cloud_xyz); //为 kdtree 输入点云
	n.setInputCloud(cloud_xyz); //为法向估计对象输入点云
	n.setSearchMethod(tree);  //设置法向估计时所采取的搜索方式为kdtree
	n.setKSearch(20); //设置法向估计时，k近邻搜索的点数
	n.compute(*normals); //进行法向估计

	QMessageBox::information(this, "information", "Normal estimation finished");

	// 点云数据与法向数据拼接 
	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);	//创建同时包含点和法线的数据结构的指针
	pcl::concatenateFields(*cloud_xyz, *normals, *cloud_with_normals);									//将已获得的点数据和法向数据拼接
	pcl::search::KdTree<pcl::PointNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointNormal>);		//创建另一个kdtree用于重建
	tree2->setInputCloud(cloud_with_normals);				//为kdtree输入点云数据，该点云数据类型为点和法向



	// 曲面重建模块
	ui.statusBar->showMessage("Convert wireframe: Greedy projection triangulation.");
	pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;	//创建贪婪三角形投影重建对象
	pcl::PolygonMesh triangles;									//创建多边形网格对象，用来存储重建结果
	//设置参数
	gp3.setSearchRadius(25);				//设置连接点之间最大距离，用于确定k近邻的球半径
	gp3.setMu(2.5);							//设置最近邻距离的乘子，以得到每个点的最终搜索半径
	gp3.setMaximumNearestNeighbors(100);	//设置搜索的最近邻点的最大数量
	gp3.setMaximumSurfaceAngle(M_PI / 2);	//45度 最大平面角
	gp3.setMinimumAngle(M_PI / 18);			//10度 每个三角的最大角度？
	gp3.setMaximumAngle(2 * M_PI / 3);		//120度
	gp3.setNormalConsistency(false);		//若法向量一致，设为true
	gp3.setInputCloud(cloud_with_normals);	//设置点云数据
	gp3.setSearchMethod(tree2);				//设置点云搜索方式
	gp3.reconstruct(triangles);				// 开始重建
	QMessageBox::information(this, "informaiton", "Reconstruction finished");

	//构建完成显示
	ui.statusBar->showMessage("");
	viewer->addPolygonMesh(triangles, "my"); //设置要显示的网格对象
	//设置网格模型显示模式
	//viewer->setRepresentationToSurfaceForAllActors(); //网格模型以面片形式显示
	//viewer->setRepresentationToPointsForAllActors();	//网格模型以点形式显示
	viewer->setRepresentationToWireframeForAllActors(); //网格模型以线框图模式显示

	// 输出窗口
	consoleLog("Convert surface", "", "", "");

	viewer->removeAllShapes();

	return 0;
}

int PointCloudTools::convertFilter()
{
	pcl::PointXYZ point;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>);
	for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
	{
		//遍历所有显示的点
		if ((*it)->visible)
		{
			for (int i = 0; i < (*it)->cloud->size(); i++)
			{
				point.x = (*it)->cloud->points[i].x;
				point.y = (*it)->cloud->points[i].y;
				point.z = (*it)->cloud->points[i].z;
				cloud_xyz->push_back(point);
			}
		}
	}

	//检查点云数据
	if (cloud_xyz->size() == 0)
	{
		QMessageBox::critical(this, "Error", "No point cloud data.", QMessageBox::Yes);
		return -1;
	}

	ui.statusBar->showMessage("Filting");
	//滤波
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
	sor.setInputCloud(cloud_xyz);
	sor.setMeanK(50);					//设置邻居数				//TODO 参数选择
	sor.setStddevMulThresh(1.0);		//设置标准差放大系数
	sor.filter(*cloud_filtered);

	//检查文件数
	//TODO 检查重名

	//全隐藏
	for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
	{
		(*it)->visible = false;
	}
	//点云设置
	mycloud = new MyCloud();
	mycloud->dirname = QDir::currentPath().toStdString();
	mycloud->filename = "filter.pcd";
	mycloud->filetype = "pcd";
	mycloud->fullname = QDir::currentPath().toStdString() + "filter.pcd";
	mycloud->cloud.reset(new PointCloudT);
	pcl::copyPointCloud(*cloud_filtered, *(mycloud->cloud));
	mycloud_vec.push_back(mycloud);

	//设置资源管理
	QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList() << QString::fromLocal8Bit(mycloud->filename.c_str()));
	cloudName->setIcon(0, QIcon(":/Resources/images/point.png"));
	ui.dataTree->addTopLevelItem(cloudName);

	showPointcloudAdd();

	//状态输出
	ui.statusBar->showMessage("");
	consoleLog("Filter", "", "", "");
	return 0;
}

int PointCloudTools::convertVoxel()
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
			//TODO 点云文件重名处理
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
		mycloud->dirname = mypicture->dirname;
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
	consoleLog("Colormap", QString::fromLocal8Bit(mypicture->filename.c_str()), "Min: " + QString::number(min) + " Max: " + QString::number(max) + " Type:" + type_str, "Time cost: " + time_cost + " s");
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
	unsigned int p = ui.pSlider->value();
	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();
	if (selected_item_count == 0)
	{
		//没有选择文件，所有显示点大小都改变
		for (int i = 0; i != mycloud_vec.size(); i++)
		{
			viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, p, "cloud" + mycloud_vec[i]->filename);
		}

		//输出
		consoleLog("Change cloud size", "All point clouds", "Size: " + QString::number(p), "");

	}
	else
	{
		//遍历选择的点云文件
		for (int i = 0; i != selected_item_count; i++)
		{
			//TODO 根据选择点云名字直接变换点大小
			viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, p, "cloud" + itemList[i]->text(0).toStdString());
		}
		//输出
		consoleLog("Change cloud size", "Point clouds selected", "Size: " + QString::number(p), "");
	}

	ui.screen->update();
}

void PointCloudTools::colorBtnPressed()
{
	
}

void PointCloudTools::pColormap()
{
	//点云根据距离染色
	int minNum = ui.colorMapLeft->text().toFloat();
	int maxNum = ui.colorMapRight->text().toFloat();
	int axis = 0;		//默认z
	if (maxNum < minNum)
	{
		QMessageBox::warning(this, "Warning", "The colormap properties have problems.");
		return;
	}

	if (ui.colormap_x->isChecked())
		axis = 1;
	else if (ui.colormap_y->isChecked())
		axis = 2;
	else
		axis = 0;

	QList<QTreeWidgetItem*> itemList = ui.dataTree->selectedItems();
	int selected_item_count = ui.dataTree->selectedItems().size();

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	float value;

	// 如果未选中任何点云，则对视图窗口中的所有点云进行着色
	if (selected_item_count == 0){
		for (int i = 0; i != mycloud_vec.size(); i++){
			for (int j = 0; j != mycloud_vec[i]->cloud->points.size(); j++){
				switch (axis)
				{
				case 1: value = mycloud_vec[i]->cloud->points[j].x; break;
				case 2: value = mycloud_vec[i]->cloud->points[j].y; break;
				default:value = mycloud_vec[i]->cloud->points[j].z;
					break;
				}
				gray2rainbow(value, minNum, maxNum, &r, &g, &b);
				mycloud_vec[i]->cloud->points[j].r = r;
				mycloud_vec[i]->cloud->points[j].g = g;
				mycloud_vec[i]->cloud->points[j].b = b;
			}
		}

		// 输出窗口
		consoleLog("Colormap", "All point clous", "", "");

	}
	else
	{
		for (int i = 0; i != selected_item_count; i++){
			QString name = itemList[i]->text(0);
			//遍历mycloud_vec
			for (auto it = mycloud_vec.begin(); it != mycloud_vec.end(); it++)
			{
				//找到同名点云数据
				if (QString::fromLocal8Bit((*it)->filename.c_str()) == name)
				{
					for (int j = 0; j != (*it)->cloud->size(); j++)
					{
						switch (axis)
						{
						case 1: value = (*it)->cloud->points[j].x; break;
						case 2: value = (*it)->cloud->points[j].y; break;
						default: value = (*it)->cloud->points[j].z; break;
							break;
						}
						gray2rainbow(value, minNum, maxNum, &r, &g, &b);
						(*it)->cloud->points[j].r = r;
						(*it)->cloud->points[j].g = g;
						(*it)->cloud->points[j].b = b;
					}

					break;
				}
			}
		}

		// 输出窗口
		consoleLog("Colormap", "Point clouds selected", "Min:" + QString::number(minNum) + " Max:" + QString::number(maxNum), "");
	}

	showPointcloudAdd();
}

void PointCloudTools::cooCbxChecked(int value)
{
	switch (value)
	{
	case 0:
		viewer->removeCoordinateSystem();  //移除坐标系
		// 输出窗口
		consoleLog("Remove coordinate system", "Remove", "", "");
		break;
	case 2:
		viewer->addCoordinateSystem();  //添加坐标系
		// 输出窗口
		consoleLog("Add coordinate system", "Add", "", "");
		break;
	}
	ui.screen->update();
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
		QColor item_color = QColor(112, 122, 132, 255);		//设置icon图标半透明
		curItem->setTextColor(0, item_color);
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
		curItem->setTextColor(0, QColor(0, 0, 0, 255));		//设置icon半透明
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

					//标题修改
					ui.imageDock->setWindowTitle(QString::fromLocal8Bit(mypicture->filename.c_str()));

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
					consoleLog("Delete picture", QString::fromLocal8Bit((*it)->filename.c_str()), QString::fromLocal8Bit((*it)->fullname.c_str()), "");

					//判断是否正在使用
					if (mypicture->filename == (*it)->filename)
					{
						//清空显示区域
						ui.imageColor->clear();
						ui.imageDepth->clear();
						mypicture = NULL;
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

					consoleLog("Delete picture", QString::fromLocal8Bit((*it)->filename.c_str()), QString::fromLocal8Bit((*it)->fullname.c_str()), "");
					
					//遍历mypicture_vec，对应的转换标志变false
					for (int j = 0; j != mypicture_vec.size(); j++)
					{
						if (mypicture_vec[j]->filename+".pcd" == (*it)->filename)
						{
							mypicture_vec[j]->isConvert = false;
							break;
						}
					}
					mycloud = NULL;

					//内存清空
					mycloud_vec.erase(it);

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
	QAction clearConsoleAction("Clear console", this);
	QAction enableConsoleAction("Enable console", this);
	QAction disableConsoleAction("Disable console", this);

	connect(&clearConsoleAction, &QAction::triggered, this, &PointCloudTools::clearConsole);
	connect(&enableConsoleAction, &QAction::triggered, this, &PointCloudTools::enableConsole);
	connect(&disableConsoleAction, &QAction::triggered, this, &PointCloudTools::disableConsole);

	QPoint pos;
	QMenu menu(ui.dataTree);
	menu.addAction(&clearConsoleAction);
	menu.addAction(&enableConsoleAction);
	menu.addAction(&disableConsoleAction);

	if (enable_console == true){
		menu.actions()[1]->setVisible(false);
		menu.actions()[2]->setVisible(true);
	}
	else{
		menu.actions()[1]->setVisible(true);
		menu.actions()[2]->setVisible(false);
	}

	menu.exec(QCursor::pos()); //在当前鼠标位置显示
}

void PointCloudTools::clearConsole()
{
	ui.consoleTable->clearContents();
	ui.consoleTable->setRowCount(0);
}

void PointCloudTools::enableConsole()
{
	enable_console = true;
}

void PointCloudTools::disableConsole()
{
	enable_console = false;
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
	float grayValue;
	float tempvalue;

	float par = (float)255 / (max - min);

	grayValue = value;
	if (grayValue < min)        //可能会出现找到的min并不是真正的最小值
	{
		*b = 0;
		*g = 0;
		*r = 0;
		return;
	}
	else if (grayValue > max)                     //也可能会出现找到的max并不是真正的最大值
	{
		*b = 0;
		*g = 0;
		*r = 0;
		return;
	}
	else
	{
		tempvalue = (float)(grayValue - min);
	}
	tempvalue = tempvalue*par;          //为了把深度值规划到(0~255之间)
	/*
	* color    R   G   B   gray
	* red      255 0   0   255
	* orange   255 127 0   204
	* yellow   255 255 0   153
	* green    0   255 0   102
	* cyan     0   255 255 51
	* blue     0   0   255 0
	*/

	tempvalue = 256 - tempvalue;


	if (tempvalue <= 51)
	{
		*b = 255;
		*g = (unsigned char)(tempvalue * 5);
		*r = 0;
	}
	else if (tempvalue <= 102)
	{
		tempvalue -= 51;
		*b = 255 - (unsigned char)(tempvalue * 5);
		*g = 255;
		*r = 0;
	}
	else if (tempvalue <= 153)
	{
		tempvalue -= 102;
		*b = 0;
		*g = 255;
		*r = (unsigned char)(tempvalue * 5);
	}
	else if (tempvalue <= 204)
	{
		tempvalue -= 153;
		*b = 0;
		*g = 255 - static_cast<unsigned char>(tempvalue * 128.0 / 51 + 0.5);
		*r = 255;
	}
	else if (tempvalue < 255)
	{
		tempvalue -= 204;
		*b = 0;
		*g = 127 - static_cast<unsigned char>(tempvalue * 127.0 / 51 + 0.5);
		*r = 255;
	}
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
			viewer->addPointCloud(mycloud_vec[i]->cloud, "cloud" + mycloud_vec[i]->filename);
			viewer->updatePointCloud(mycloud_vec[i]->cloud, "cloud" + mycloud_vec[i]->filename);
		}
	}
	viewer->resetCamera();
	ui.screen->update();
}

void PointCloudTools::setCloudColor(unsigned int r, unsigned int g, unsigned int b)
{
	// Set the new color
	for (size_t i = 0; i < mycloud->cloud->size(); i++)
	{
		mycloud->cloud->points[i].r = r;
		mycloud->cloud->points[i].g = g;
		mycloud->cloud->points[i].b = b;
		mycloud->cloud->points[i].a = 255;
	}
}

void PointCloudTools::setA(unsigned int a)
{
	for (size_t i = 0; i < mycloud->cloud->size(); i++)
	{
		mycloud->cloud->points[i].a = a;
	}
}