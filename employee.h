#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int dId);
	//showŒÂlî•ñ
	virtual void showInfo();
	//–ğE‚Ìæ“¾
	virtual string getDeptName();
};