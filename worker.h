#pragma once
#include<iostream>
using namespace std;
#include<string>

//worker���ۃN���X
class Worker
{
public:
	//show�l���
	virtual void showInfo() = 0;
	//��E�̎擾
	virtual string getDeptName() = 0;

	//ID�ԍ�
	int m_Id;
	//���O
	string m_Name;
	//�����ԍ�
	int m_DeptID;
};