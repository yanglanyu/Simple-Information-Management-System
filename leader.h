#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Leader :public Worker
{
public:
	//leader�R���X�g���N�^
	Leader(int id, string name, int dId);
	//show�l���
	virtual void showInfo();
	//��E�̎擾
	virtual string getDeptName();
};