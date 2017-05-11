#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>
#include "gpio.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    CThread t1, t2, t3, t4, t5;

    t1.addNewThread();
    t2.addNewThread();
    t3.addNewThread();
    t4.addNewThread();
    t5.addNewThread();

	CGPIO gpio;
    QApplication::setSetuidAllowed(true);
	QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int i=10;
    while(i){
        usleep(1000);
        printf("%d\n",i);
        i--;
    }
    return a.exec();
}
