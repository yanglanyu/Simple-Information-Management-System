#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptID = dId;

}
//showÂlîñ
void Employee::showInfo() 
{
	cout << "ÔF@" << this->m_Id << endl;
	cout << "¼OF@" << this->m_Name << endl;
	cout << "ðEF@" << this->getDeptName() << endl;
	cout << "ÓC" << endl;

}
//ðEÌæ¾
string Employee::getDeptName()
{
	return string("êÊ");
}