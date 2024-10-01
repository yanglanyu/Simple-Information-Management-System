#include "workerManeger.h"

WorkerManeger::WorkerManeger()
{
	//1,ファイルは存在しない
	
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//ファイルを読み込む

	if (!ifs.is_open())
	{
		cout << "ファイルは存在しない" << endl;
		//初期化
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}
	//2,ファイルは存在するけど、記録されていない
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "ファイルには何も記録されていない" << endl;
		//初期化
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3,ファイルは存在し、記録されている
	int num = this->get_EmpNum();
	cout << "人数は" << num << endl;

	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	//test
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ID番号" << this->m_EmpArray[i]->m_Id; 
		cout << "ID番号" << this->m_EmpArray[i]->m_Id;
			cout << "役職" << this->m_EmpArray[i]->m_DeptID << endl;
	}*/

}

//メニュー
void WorkerManeger::Show_Menu()
{
	cout << "＊＊＊＊＊【管理システム】＊＊＊＊＊＊＊＊" << endl;
	cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
	cout << "＊＊　＞０システムを終了する　　　　　＊＊" << endl;
	cout << "＊＊　＞１情報を追加する　　　　　　　＊＊" << endl;
	cout << "＊＊　＞２情報を表示する　　　　　　　＊＊" << endl;
	cout << "＊＊　＞３情報を削除する　　　　　　　＊＊" << endl;
	cout << "＊＊　＞４情報を変更する　　　　　　　＊＊" << endl;
	cout << "＊＊　＞５情報を検索する　　　　　　　＊＊" << endl;
	cout << "＊＊　＞６番号順に並べ替える　　　　　＊＊" << endl;
	cout << "＊＊　＞７すべての情報をクリアする　　＊＊" << endl;
	cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
	cout << endl;
}

//終了
void WorkerManeger::Exit_System()
{
	cout << "システムは終了した" << endl;
	system("pause");
	exit(0);
}

//追加
void WorkerManeger::Add_Emp()
{
	cout << "追加の人数を入力してください" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//追加
		//空間を計算する
		int newSize = this->m_EmpNum + addNum;

		//新しい空間を開ける
		Worker** newSpace = new Worker * [newSize];

		//既存のデータを新空間にコピーする
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//バッチで追加する
		for (int i = 0; i < addNum; i++)
		{
			int id;	
			string name;
			int dSelect;

			cout << "第" << i + 1 << "人目のID番号を入力してください" << endl;
			cin >> id;
			
			cout << "第" << i + 1 << "人目の名前を入力してください" << endl;
			cin >> name;

			cout << "役職を選択してください" << endl;
			cout << "１、一般" << endl;
			cout << "２、課長" << endl;
			cout << "３、部長" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Leader(id, name, 2);
				break;
			case 3:
				worker = new Maneger(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;

		}

		//スペースを解放する
		delete[] this->m_EmpArray;

		//新しい空間の方向を変更する
		this->m_EmpArray = newSpace;

		//追加された人数
		this->m_EmpNum = newSize;

		//
		this->m_FileIsEmpty = false;

		cout <<addNum<< "名の情報を追加しました。" <<endl;

		//ファイルに保存
		this->save();
	}
	else
	{
		cout << "間違ったデータが入力されました" << endl;
	}
	system("pause");
	system("cls");
}

//ファイルに保存
void WorkerManeger::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

int WorkerManeger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

//従業員を初期化
void WorkerManeger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Leader(id, name, dId);
		}
		else
		{
			worker = new Maneger(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//情報を表示する
void WorkerManeger::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ファイルは存在しない（記録されていない）" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	//
	system("pause");
	system("cls");
}
//情報を削除
void WorkerManeger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ファイルは存在しない（記録されていない）" << endl;
	}
	else
	{
		//削除したいIDを入力
		cout << "削除する従業員IDを入力してください" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			//データ移行
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();

			cout << "削除された" << endl;
		}
		else
		{
			cout << "削除に失敗した。ID が見つからなかった" << endl;
		}

	}
	system("pause");
	system("cls");
}
//存在するかを判断する / yes:所在の数列の位置に戻る　/ no:return -1
int WorkerManeger::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;

			break;
		}
	}
	return index;
}

//情報を変更する
void WorkerManeger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ファイルは存在しない（記録されていない）" << endl;
	}
	else
	{
		cout << "変更する従業員IDを入力してください" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << id << "のが見つかった" << endl;
			cout << "新しいIDを入力してください" << endl;
			cin >> newId;

			cout << "新しい名前を入力してください" << endl;
			cin >> newName;

			cout << "新しい役職を選んでください" << endl;
			cout << "１　一般\n２　課長\n３　部長" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Leader(newId, newName, dSelect);
				break;
			case 3:
				worker = new Maneger(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//データを更新
			this->m_EmpArray[ret] = worker;

			cout << "情報を更新した" <<endl;

			//ファイルに保存
			this->save();

		}
		else
		{
			cout << "このIDが見つからなかった" << endl;
		}
	}
	system("pause");
	system("cls");
}

//検索機能
void WorkerManeger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ファイルは存在しない（記録されていない）" << endl;
	}
	else
	{
		cout << "検索方法を選択してください" << endl;
		cout << "１、番号で検索" << endl;
		cout << "２、名前で検索" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "番号を入力してください" << endl;
			cin >> id;

			int ret = IsExist(id);

			if (ret != -1)
			{
				cout << "見つかった" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "見つからなかった" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "名前を入力してください" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "見つかった" << endl;
					
					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag = false)
			{
				cout << "見つからなかった" << endl;
			}
		}
		else
		{
			cout << "間違ったオプション" << endl;
		}
	}
	system("pause");
	system("cls");
}

//並べ替え方法
void WorkerManeger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "ファイルは存在しない（記録されていない）" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "並べ替え方法を選択してください" << endl;
		cout << "１、昇順" << endl;
		cout << "２、降順" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int MinOrMax = i;

			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{	
					//昇順
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					//降順
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
			}
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "並べ替えは完了" << endl;
		this->save();
		this->Show_Emp();
	}
}

//全てクリア
void WorkerManeger::Clean_File()
{
	cout << "クリアの確認" << endl;
	cout << "１、はい、クリアする" << endl;
	cout << "２、いいえ、戻る" << endl;

	int select = 0;
	cin >> select;
	
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "全てのデータをクリアした" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManeger::~WorkerManeger()
{
	if (this->m_EmpNum != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
