#include <iostream>
#include "TrafficGraph.h"
using namespace std;

int main()
{
	// 
	int val1 = 1, val2 = 1, val3 = 1;
	int start = -1, end = -1;
	// ������ͨͼ
	int arc = 10, vex = 7;
	GraphInfo Traffic[10] =
	{	{1,2,{2553,8,885}},
		{1,4,{704,2.5,225}},
		{1,3,{696,2.3,202}},
		{2,3,{511,1.5,148}},
		{3,4,{349,1.2,112}},
		{2,5,{812,3,283}},
		{4,7,{651,2,162}},
		{5,6,{2368,7,684}},
		{6,7,{1385,4,386}},
		{3,6,{1579,5,495}} };
	VertexType V[7] = { "����","����","֣��","����","�ɶ�","����","�Ϻ�" };
	TrafficGraph TG(V, Traffic, vex, arc);
	while (val1)
	{
		ShowGraph();
		MainMenu();
		cin >> val1;
		switch (val1)
		{
		case 0:	// �˳�
			cout << "\n\t\t\t\t\t�����˳�����ӭ�´�ʹ�ã�\n";
			break;
		case 1:	// ��ͨ��ѯ
			cout << "\n\t\t\t--------------------\n";
			cout << "\t\t\t����������ʼ���ر�ţ�";
			cin >> start;
			cout << "\t\t\t����������Ŀ�ĵر�ţ�";
			cin >> end;
			LowcostMenu();
			cin >> val2;
			TG.Floyed();
			cout << "\n\t\t\t-----------------------------\n";
			cout << "\t\t\t��Ϊ��ѡ��";
			TG.PrintCity(start - 1, end - 1);
			cout << "���·��\n\n\t\t\t";
			TG.FindPath(start - 1, end - 1, val2);
			TG.PrintInfo(start - 1, end - 1, val2);
			system("pause");
			system("cls");
			break;
		case 2:	// ����Աģʽ
			cin >> val2;
			switch (val2)
			{
			default:
				TG.PrintGraphMat(2);
				break;
			}
			break;
		default:
			break;
		}
	}
	
	return 0;
}