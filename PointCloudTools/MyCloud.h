#pragma once

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include <string>

using namespace std;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

class MyCloud
{


public:
	MyCloud();
	~MyCloud();

	PointCloudT::Ptr cloud;			//点云指针
	string fullname;		//完整路径
	string filename;		//文件名
	string dirname;			//所在文件夹路径
	string filetype;		//文件类型
	bool visible = true;
};
