#include"maneger.h"


//Manegerコンストラクタ
Maneger::Maneger(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}
//show個人情報
void Maneger:: showInfo()
{
	cout << "番号：　" << this->m_Id << endl;
	cout << "名前：　" << this->m_Name << endl;
	cout << "役職：　" << this->getDeptName() << endl;
	cout << "責任" << endl;
}
//役職の取得
string Maneger::getDeptName()
{
	return string("部長");
}