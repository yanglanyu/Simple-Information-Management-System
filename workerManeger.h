#pragma once		//�w�b�_���d���Ɋ܂܂��̂�h�~���邽��
#include<iostream>	//���́E�o��
#include "worker.h"
using namespace std;//
#include"worker.h"
#include"employee.h"
#include"leader.h"
#include"maneger.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManeger
{
public:
	//�R���X�g���N�^
	WorkerManeger();

	//���j���[
	void Show_Menu();

	//�I��
	void Exit_System();

	//�l�����L�^
	int m_EmpNum;

	//����̃|�C���^
	Worker** m_EmpArray;

	//�ǉ�
	void Add_Emp();

	//�t�@�C���ɕۑ�
	void save();

	//�t�@�C�����󂩂ǂ����𔻒f����
	bool m_FileIsEmpty;

	//�L�^����Ă���l��
	int get_EmpNum();

	//�]�ƈ���������
	void init_Emp();

	//����\������
	void Show_Emp();

	//�����폜
	void Del_Emp();

	//���݂��邩�𔻒f���� / yes:���݂̐���̈ʒu�ɖ߂�@/ no:return -1
	int IsExist(int id);

	//����ύX����
	void Mod_Emp();

	//��������
	void Find_Emp();

	//���בւ�
	void Sort_Emp();

	//�S�ăN���A
	void Clean_File();

	//�f�X�g���N�^
	~WorkerManeger();
};