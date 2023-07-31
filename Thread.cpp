#include "Thread.h"
#include"MyThread.h"
#include"qthread.h"
Thread::Thread(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//1�����������
	Generate *gen = new Generate;//����ָ�������󣬲�Ȼ�ᱨ��
	BubbleSort *bubble = new BubbleSort;
	QuickSort *quick = new QuickSort;
	//2�������߳���
	QThread *t1 = new QThread;
	QThread *t2 = new QThread;
	QThread *t3 = new QThread;
	//3������Ŀ���ƶ������߳�����
	gen->moveToThread(t1);
	bubble->moveToThread(t2);
	quick->moveToThread(t3);

	connect(this, &Thread::starting, gen, &Generate::working);//�������߳�������ĸ�����ͨ���ź����

	connect(ui.start, &QPushButton::clicked, this, [=]()
		{
			emit starting(10000);//��������
			t1->start();//�������߳�

		});

	connect(gen, &Generate::sendArray, bubble, &BubbleSort::working);
	connect(gen, &Generate::sendArray, quick, &QuickSort::working);


	//3���������̵߳������
	connect(gen, &Generate::sendArray, this, [=](QVector<int> list)
		{
			t2->start();
			t3->start();
			for (int i = 0; i < list.size(); i++)
			{
				ui.randList->addItem(QString::number(list.at(i)));//������ʾ
			}

		});

	connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.bubbleList->addItem(QString::number(list.at(i)));//������ʾ
			}

		});

	connect(quick, &QuickSort::finish, this, [=](QVector<int> list)
		{

			for (int i = 0; i < list.size(); i++)
			{
				ui.quickList->addItem(QString::number(list.at(i)));//������ʾ
			}

		});
}

Thread::~Thread()
{}
