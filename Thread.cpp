#include "Thread.h"
#include"MyThread.h"
#include"qthread.h"
Thread::Thread(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//1、创建类对象
	Generate *gen = new Generate;//不能指定父对象，不然会报错
	BubbleSort *bubble = new BubbleSort;
	QuickSort *quick = new QuickSort;
	//2、创建线程类
	QThread *t1 = new QThread;
	QThread *t2 = new QThread;
	QThread *t3 = new QThread;
	//3、把项目类移动到子线程类中
	gen->moveToThread(t1);
	bubble->moveToThread(t2);
	quick->moveToThread(t3);

	connect(this, &Thread::starting, gen, &Generate::working);//设置子线程随机数的个数，通过信号与槽

	connect(ui.start, &QPushButton::clicked, this, [=]()
		{
			emit starting(10000);//设置数量
			t1->start();//开启子线程

		});

	connect(gen, &Generate::sendArray, bubble, &BubbleSort::working);
	connect(gen, &Generate::sendArray, quick, &QuickSort::working);


	//3、接受子线程的随机数
	connect(gen, &Generate::sendArray, this, [=](QVector<int> list)
		{
			t2->start();
			t3->start();
			for (int i = 0; i < list.size(); i++)
			{
				ui.randList->addItem(QString::number(list.at(i)));//窗口显示
			}

		});

	connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.bubbleList->addItem(QString::number(list.at(i)));//窗口显示
			}

		});

	connect(quick, &QuickSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.quickList->addItem(QString::number(list.at(i)));//窗口显示
			}

		});
}

Thread::~Thread()
{}
