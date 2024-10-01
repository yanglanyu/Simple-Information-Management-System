#include "workerManeger.h"

WorkerManeger::WorkerManeger()
{
	//1,�t�@�C���͑��݂��Ȃ�
	
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//�t�@�C����ǂݍ���

	if (!ifs.is_open())
	{
		cout << "�t�@�C���͑��݂��Ȃ�" << endl;
		//������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}
	//2,�t�@�C���͑��݂��邯�ǁA�L�^����Ă��Ȃ�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�t�@�C���ɂ͉����L�^����Ă��Ȃ�" << endl;
		//������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3,�t�@�C���͑��݂��A�L�^����Ă���
	int num = this->get_EmpNum();
	cout << "�l����" << num << endl;

	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	//test
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ID�ԍ�" << this->m_EmpArray[i]->m_Id; 
		cout << "ID�ԍ�" << this->m_EmpArray[i]->m_Id;
			cout << "��E" << this->m_EmpArray[i]->m_DeptID << endl;
	}*/

}

//���j���[
void WorkerManeger::Show_Menu()
{
	cout << "�����������y�Ǘ��V�X�e���z����������������" << endl;
	cout << "������������������������������������������" << endl;
	cout << "�����@���O�V�X�e�����I������@�@�@�@�@����" << endl;
	cout << "�����@���P����ǉ�����@�@�@�@�@�@�@����" << endl;
	cout << "�����@���Q����\������@�@�@�@�@�@�@����" << endl;
	cout << "�����@���R�����폜����@�@�@�@�@�@�@����" << endl;
	cout << "�����@���S����ύX����@�@�@�@�@�@�@����" << endl;
	cout << "�����@���T������������@�@�@�@�@�@�@����" << endl;
	cout << "�����@���U�ԍ����ɕ��בւ���@�@�@�@�@����" << endl;
	cout << "�����@���V���ׂĂ̏����N���A����@�@����" << endl;
	cout << "������������������������������������������" << endl;
	cout << endl;
}

//�I��
void WorkerManeger::Exit_System()
{
	cout << "�V�X�e���͏I������" << endl;
	system("pause");
	exit(0);
}

//�ǉ�
void WorkerManeger::Add_Emp()
{
	cout << "�ǉ��̐l������͂��Ă�������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�ǉ�
		//��Ԃ��v�Z����
		int newSize = this->m_EmpNum + addNum;

		//�V������Ԃ��J����
		Worker** newSpace = new Worker * [newSize];

		//�����̃f�[�^��V��ԂɃR�s�[����
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�o�b�`�Œǉ�����
		for (int i = 0; i < addNum; i++)
		{
			int id;	
			string name;
			int dSelect;

			cout << "��" << i + 1 << "�l�ڂ�ID�ԍ�����͂��Ă�������" << endl;
			cin >> id;
			
			cout << "��" << i + 1 << "�l�ڂ̖��O����͂��Ă�������" << endl;
			cin >> name;

			cout << "��E��I�����Ă�������" << endl;
			cout << "�P�A���" << endl;
			cout << "�Q�A�ے�" << endl;
			cout << "�R�A����" << endl;
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

		//�X�y�[�X���������
		delete[] this->m_EmpArray;

		//�V������Ԃ̕�����ύX����
		this->m_EmpArray = newSpace;

		//�ǉ����ꂽ�l��
		this->m_EmpNum = newSize;

		//
		this->m_FileIsEmpty = false;

		cout <<addNum<< "���̏���ǉ����܂����B" <<endl;

		//�t�@�C���ɕۑ�
		this->save();
	}
	else
	{
		cout << "�Ԉ�����f�[�^�����͂���܂���" << endl;
	}
	system("pause");
	system("cls");
}

//�t�@�C���ɕۑ�
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

//�]�ƈ���������
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

//����\������
void WorkerManeger::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�t�@�C���͑��݂��Ȃ��i�L�^����Ă��Ȃ��j" << endl;
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
//�����폜
void WorkerManeger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�t�@�C���͑��݂��Ȃ��i�L�^����Ă��Ȃ��j" << endl;
	}
	else
	{
		//�폜������ID�����
		cout << "�폜����]�ƈ�ID����͂��Ă�������" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			//�f�[�^�ڍs
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();

			cout << "�폜���ꂽ" << endl;
		}
		else
		{
			cout << "�폜�Ɏ��s�����BID ��������Ȃ�����" << endl;
		}

	}
	system("pause");
	system("cls");
}
//���݂��邩�𔻒f���� / yes:���݂̐���̈ʒu�ɖ߂�@/ no:return -1
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

//����ύX����
void WorkerManeger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�t�@�C���͑��݂��Ȃ��i�L�^����Ă��Ȃ��j" << endl;
	}
	else
	{
		cout << "�ύX����]�ƈ�ID����͂��Ă�������" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << id << "�̂���������" << endl;
			cout << "�V����ID����͂��Ă�������" << endl;
			cin >> newId;

			cout << "�V�������O����͂��Ă�������" << endl;
			cin >> newName;

			cout << "�V������E��I��ł�������" << endl;
			cout << "�P�@���\n�Q�@�ے�\n�R�@����" << endl;
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
			//�f�[�^���X�V
			this->m_EmpArray[ret] = worker;

			cout << "�����X�V����" <<endl;

			//�t�@�C���ɕۑ�
			this->save();

		}
		else
		{
			cout << "����ID��������Ȃ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����@�\
void WorkerManeger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�t�@�C���͑��݂��Ȃ��i�L�^����Ă��Ȃ��j" << endl;
	}
	else
	{
		cout << "�������@��I�����Ă�������" << endl;
		cout << "�P�A�ԍ��Ō���" << endl;
		cout << "�Q�A���O�Ō���" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "�ԍ�����͂��Ă�������" << endl;
			cin >> id;

			int ret = IsExist(id);

			if (ret != -1)
			{
				cout << "��������" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "������Ȃ�����" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "���O����͂��Ă�������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "��������" << endl;
					
					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag = false)
			{
				cout << "������Ȃ�����" << endl;
			}
		}
		else
		{
			cout << "�Ԉ�����I�v�V����" << endl;
		}
	}
	system("pause");
	system("cls");
}

//���בւ����@
void WorkerManeger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�t�@�C���͑��݂��Ȃ��i�L�^����Ă��Ȃ��j" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���בւ����@��I�����Ă�������" << endl;
		cout << "�P�A����" << endl;
		cout << "�Q�A�~��" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int MinOrMax = i;

			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{	
					//����
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					//�~��
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
		cout << "���בւ��͊���" << endl;
		this->save();
		this->Show_Emp();
	}
}

//�S�ăN���A
void WorkerManeger::Clean_File()
{
	cout << "�N���A�̊m�F" << endl;
	cout << "�P�A�͂��A�N���A����" << endl;
	cout << "�Q�A�������A�߂�" << endl;

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
		cout << "�S�Ẵf�[�^���N���A����" << endl;
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
