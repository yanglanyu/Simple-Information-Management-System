#pragma once		//ヘッダが重複に含まれるのを防止するため
#include<iostream>	//入力・出力
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
	//コンストラクタ
	WorkerManeger();

	//メニュー
	void Show_Menu();

	//終了
	void Exit_System();

	//人数を記録
	int m_EmpNum;

	//数列のポインタ
	Worker** m_EmpArray;

	//追加
	void Add_Emp();

	//ファイルに保存
	void save();

	//ファイルが空かどうかを判断する
	bool m_FileIsEmpty;

	//記録されている人数
	int get_EmpNum();

	//従業員を初期化
	void init_Emp();

	//情報を表示する
	void Show_Emp();

	//情報を削除
	void Del_Emp();

	//存在するかを判断する / yes:所在の数列の位置に戻る　/ no:return -1
	int IsExist(int id);

	//情報を変更する
	void Mod_Emp();

	//情報を検索
	void Find_Emp();

	//並べ替え
	void Sort_Emp();

	//全てクリア
	void Clean_File();

	//デストラクタ
	~WorkerManeger();
};