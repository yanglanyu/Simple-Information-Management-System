#include<iostream>
using namespace std;
#include "workerManeger.h"

//#include"worker.h"
//#include"employee.h"
//#include"leader.h"
//#include"maneger.h"

int main()
{
	////test
	//Worker* worker = NULL;
	//worker = new Employee(1, "�k", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Leader(2, "��", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Maneger(3, "�F", 3);
	//worker->showInfo();
	//delete worker;

	WorkerManeger wm;

	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "�I��ł�������" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�I��
			wm.Exit_System();
			break;

		case 1://�ǉ�
			wm.Add_Emp();
			break;

		case 2://�\��
			wm.Show_Emp();
			break;

		//�폜
		case 3:
			//�폜
		//{	//test
		//	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "���݂��Ă���" << endl;
		//	}
		//	else
		//	{
		//		cout << "���݂��Ȃ�" << endl;
		//	}
		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4://�ύX
			wm.Mod_Emp();
			break;

		case 5://����
			wm.Find_Emp();
			break;

		case 6://���בւ�
			wm.Sort_Emp();
			break;

		case 7://�N���A
			wm.Clean_File();
			break;

		default:
			system("cls");
			break;
		}
	}


	system("pause");

	return 0;
}