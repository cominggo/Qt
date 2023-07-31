#pragma once
#pragma execution_character_set("utf-8")
#include<QObject>
#include<Qvector>
//生成随机数
class Generate : public QObject
{
	Q_OBJECT
public:
	explicit Generate(QObject *parent = nullptr);

	void working(int num);
signals:
	void sendArray(QVector<int> list);

};

//冒泡排序
class BubbleSort : public QObject
{
	Q_OBJECT
public:
	explicit BubbleSort(QObject *parent = nullptr);

	void working(QVector<int> list);
signals:
	void finish(QVector<int> num);

};
//快速排序
class QuickSort : public QObject
{
	Q_OBJECT
public:
	explicit QuickSort(QObject *parent = nullptr);

	void working(QVector<int> list);
signals:
	void finish(QVector<int> num);

};