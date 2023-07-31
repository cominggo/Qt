#include "Thread.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	qRegisterMetaType<QVector<int>>("QVector<int>");//注册信息，让程序可以使用QVector
    QApplication a(argc, argv);
    Thread w;
    w.show();
    return a.exec();
}
