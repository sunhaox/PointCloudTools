#include "PointCloudTools.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PointCloudTools w;
	w.show();
	return a.exec();
}
