#include "mainwindow.h"
#include <QApplication>
#include "gpio.h"

int main(int argc, char *argv[])
{
	CGPIO gpio;
	QApplication::setSetuidAllowed(true);
	QApplication a(argc, argv);
	MainWindow w;
    w.show();

    return a.exec();
}
