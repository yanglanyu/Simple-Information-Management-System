#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Maneger :public Worker
{
public:
	//Manegerコンストラクタ
	Maneger(int id, string name, int dId);
	//show個人情報
	virtual void showInfo();
	//役職の取得
	virtual string getDeptName();
};