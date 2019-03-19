#include "Tools.h"

QTime time;

Tools::Tools()
{
}

Tools::~Tools()
{
}

//提取全路径中的文件名（带后缀）
std::string getFileName(std::string file_name)
{
	std::string subname;
	for (auto i = file_name.end() - 1; *i != '/'; i--)
	{
		subname.insert(subname.begin(), *i);
	}
	return subname;
}

//提取全路径中的文件后缀）
std::string getFileType(std::string file_name)
{
	std::string subname;
	for (auto i = file_name.end() - 1; *i != '.'; i--)
	{
		subname.insert(subname.begin(), *i);
	}
	
	return subname;
}

//提取路径中文件夹路径
std::string getFileDir(std::string file_name)
{
	std::string subname = getFileName(file_name);
	std::string dirname = file_name.substr(0, file_name.size() - subname.size());

	return dirname;
}

//计时开始
void timeStart()
{
	time.start();
}

//计时结束
QString timeOff()
{
	int timediff = time.elapsed();   //返回从上次start()或restart()开始以来的时间差，单位ms
	float f = timediff / 1000.0;
	QString tr_timediff = QString("%1").arg(f);  //float->QString
	return tr_timediff;
}
