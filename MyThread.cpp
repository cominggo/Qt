#include "MyThread.h"
#include"qelapsedtimer.h"//记录运行时间
#include"qdebug.h"
#include <algorithm>
#include"qthread.h"
//生成随机数
Generate::Generate(QObject *parent) :QObject(parent)
{

}


void Generate::working(int num)
{
	qDebug() << "生成随机数的线程的线程地址" << QThread::currentThread();
	QVector<int> List;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < num; i++)
	{
		List.push_back(qrand() % 100000);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "生成" << num << "个随机数总共用时" << ms.count() << "微秒";
	emit sendArray(List);
}

//冒泡排序子线程
BubbleSort::BubbleSort(QObject *parent) :QObject(parent)
{

}

void BubbleSort::working(QVector<int> list)
{
	qDebug() << "冒泡排序的线程的线程地址" << QThread::currentThread();
	auto start = std::chrono::high_resolution_clock::now();
	int temp;
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < list.size() - 1 - i; j++)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "冒泡排序总用时" << ms.count() << "微秒";
	emit finish(list);
}

//快速排序子线程

QuickSort::QuickSort(QObject *parent) :QObject(parent)
{

}

void QuickSort::working(QVector<int> list)
{
	qDebug() << "快速排序的线程的线程地址" << QThread::currentThread();
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(list.begin(), list.end());
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "冒泡排序总用时" << ms.count() << "微秒";
	emit finish(list);
}