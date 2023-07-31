#include "MyThread.h"
#include"qelapsedtimer.h"//��¼����ʱ��
#include"qdebug.h"
#include <algorithm>
#include"qthread.h"
//���������
Generate::Generate(QObject *parent) :QObject(parent)
{

}


void Generate::working(int num)
{
	qDebug() << "������������̵߳��̵߳�ַ" << QThread::currentThread();
	QVector<int> List;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < num; i++)
	{
		List.push_back(qrand() % 100000);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "����" << num << "��������ܹ���ʱ" << ms.count() << "΢��";
	emit sendArray(List);
}

//ð���������߳�
BubbleSort::BubbleSort(QObject *parent) :QObject(parent)
{

}

void BubbleSort::working(QVector<int> list)
{
	qDebug() << "ð��������̵߳��̵߳�ַ" << QThread::currentThread();
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
	qDebug() << "ð����������ʱ" << ms.count() << "΢��";
	emit finish(list);
}

//�����������߳�

QuickSort::QuickSort(QObject *parent) :QObject(parent)
{

}

void QuickSort::working(QVector<int> list)
{
	qDebug() << "����������̵߳��̵߳�ַ" << QThread::currentThread();
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(list.begin(), list.end());
	auto end = std::chrono::high_resolution_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	qDebug() << "ð����������ʱ" << ms.count() << "΢��";
	emit finish(list);
}