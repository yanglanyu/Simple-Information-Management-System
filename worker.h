#pragma once
#include<iostream>
using namespace std;
#include<string>

//worker抽象クラス
class Worker
{
public:
	//show個人情報
	virtual void showInfo() = 0;
	//役職の取得
	virtual string getDeptName() = 0;

	//ID番号
	int m_Id;
	//名前
	string m_Name;
	//所属番号
	int m_DeptID;
};