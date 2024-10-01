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
	//worker = new Employee(1, "楊", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Leader(2, "嵐", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Maneger(3, "宇", 3);
	//worker->showInfo();
	//delete worker;

	WorkerManeger wm;

	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "選んでください" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://終了
			wm.Exit_System();
			break;

		case 1://追加
			wm.Add_Emp();
			break;

		case 2://表示
			wm.Show_Emp();
			break;

		//削除
		case 3:
			//削除
		//{	//test
		//	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "存在している" << endl;
		//	}
		//	else
		//	{
		//		cout << "存在しない" << endl;
		//	}
		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4://変更
			wm.Mod_Emp();
			break;

		case 5://検索
			wm.Find_Emp();
			break;

		case 6://並べ替え
			wm.Sort_Emp();
			break;

		case 7://クリア
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