#pragma once
#include<iostream>
using namespace std;
#include<string>

//workerÛNX
class Worker
{
public:
	//showÂlîñ
	virtual void showInfo() = 0;
	//ðEÌæ¾
	virtual string getDeptName() = 0;

	//IDÔ
	int m_Id;
	//¼O
	string m_Name;
	//®Ô
	int m_DeptID;
};