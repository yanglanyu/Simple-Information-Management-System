#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Maneger :public Worker
{
public:
	//Maneger�R���X�g���N�^
	Maneger(int id, string name, int dId);
	//show�l���
	virtual void showInfo();
	//��E�̎擾
	virtual string getDeptName();
};