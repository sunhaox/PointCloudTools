#pragma once

#include <string>
#include <opencv2\opencv.hpp>

using namespace std;

class MyPicture 
{


public:
	MyPicture();
	~MyPicture();

	cv::Mat depthMat;
	cv::Mat colorMat;
	string dirname;			//文件目录
	string fullname;		//完整路径
	string filename;		//文件名（不带后缀）
	string filetype;		//文件类型
};
