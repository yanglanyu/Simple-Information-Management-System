#include"maneger.h"


//Maneger�R���X�g���N�^
Maneger::Maneger(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}
//show�l���
void Maneger:: showInfo()
{
	cout << "�ԍ��F�@" << this->m_Id << endl;
	cout << "���O�F�@" << this->m_Name << endl;
	cout << "��E�F�@" << this->getDeptName() << endl;
	cout << "�ӔC" << endl;
}
//��E�̎擾
string Maneger::getDeptName()
{
	return string("����");
}