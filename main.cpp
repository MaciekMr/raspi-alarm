#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>
#include "gpio.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    CThread t1, t2, t3, t4, t5;

    t1.addNewThread(NULL);
    t2.addNewThread(NULL);
    t3.addNewThread(NULL);
    t4.addNewThread(NULL);
    t5.addNewThread(NULL);

	CGPIO gpio;
    /*QApplication::setSetuidAllowed(true);
	QApplication a(argc, argv);
    MainWindow w;
    w.show();*/
    int i=100000;
    while(i){
        sleep(10);
        printf("%d\n",i);
        i--;
    }
    //return a.exec();
    return 0;
}
