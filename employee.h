#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int dId);
	//show�l���
	virtual void showInfo();
	//��E�̎擾
	virtual string getDeptName();
};