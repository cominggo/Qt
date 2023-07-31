#pragma once
#pragma execution_character_set("utf-8")
#include<QObject>
#include<Qvector>
//���������
class Generate : public QObject
{
	Q_OBJECT
public:
	explicit Generate(QObject *parent = nullptr);

	void working(int num);
signals:
	void sendArray(QVector<int> list);

};

//ð������
class BubbleSort : public QObject
{
	Q_OBJECT
public:
	explicit BubbleSort(QObject *parent = nullptr);

	void working(QVector<int> list);
signals:
	void finish(QVector<int> num);

};
//��������
class QuickSort : public QObject
{
	Q_OBJECT
public:
	explicit QuickSort(QObject *parent = nullptr);

	void working(QVector<int> list);
signals:
	void finish(QVector<int> num);

};