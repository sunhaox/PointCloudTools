#include "PointCloudTools.h"
#include <QtWidgets/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTranslator translator;
	translator.load("pointcloudtools_zh.qm");
	a.installTranslator(&translator);


	PointCloudTools w;
	w.show();
	return a.exec();
}
