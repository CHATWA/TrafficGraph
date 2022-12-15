// main.cpp
#include <iostream>
#include "TrafficGraph.h"
using namespace std;

int main()
{
	EdgeType e;
	// val~Ϊ�˵�ѡ��
	int val1 = 1, val2 = 1, val3 = 1;
	// ����յ���б��
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
	TG.Floyed();
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
			query:
			cout << "\n\t\t\t--------------------\n";
			cout << "\t\t\t����������ʼ���ر�ţ�";
			cin >> start;
			cout << "\t\t\t����������Ŀ�ĵر�ţ�";
			cin >> end;
			// �������
			if (start == end || start < 0 || start>7 || end < 0 || end>7)
			{
				cout << "\t\t\t������󣡣���" << endl;
				goto query;
			}
			LowcostMenu();
			cin >> val2;
			// val2==0����
			if (!val2)
				goto query;
			cout << "\n\t\t\t-----------------------------\n";
			cout << "\t\t\t��Ϊ��ѡ��";
			TG.PrintCity(start - 1, end - 1);
			cout << "���·��\n\n\t\t\t";
			TG.InitFind(end - 1);
			TG.FindPath(start - 1, end - 1, val2);
			TG.PrintInfo(start - 1, end - 1, val2);
			system("pause");
			system("cls");
			break;
		case 2:	// ����Աģʽ
			admin:
			system("cls");
			AdminMenu();
			cin >> val2;
			switch (val2)
			{
			case 1:
				cout << "\n\t\t\t1���룬2ʱ�䣬3���ѣ�4��ת" << endl;
				cout << "\t\t\t��ѡ���ӡ��Ȩֵ��";
				cin >> val3;
				TG.PrintGraphMat(val3);
				TG.PrintPathMat(val3);
				TG.PrintDistMat(val3);
				system("pause");
				system("cls");
				break;
			// �޸ı�
			case 2:
				int temp;
				cout << "\n\t\t\t�޸�ģʽ��\n" << endl;
				cout << "\t\t\t��������㣺";
				cin >> start;
				cout << "\t\t\t�������յ㣺";
				cin >> end;
				cout << "\n\t\t\t1���룬2ʱ�䣬3���ѣ�4��ת\n";
				cout << "\t\t\t��Ҫ�޸�ʲô��";
				cin >> val3;
				cout << "\t\t\t�޸�Ϊ��";
				cin >> temp;
				TG.EidtEdge(start, end, val3, temp);
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "\n\t\t\t���ģʽ��\n" << endl;
				cout << "\t\t\t��������㣺";
				cin >> start;
				cout << "\t\t\t�������յ㣺";
				cin >> end;
				cout << "\t\t\t��������룬ʱ�䣬���ѣ�";
				cin >> e.distance >> e.time >> e.cost;
				TG.AddEdge(start, end, e);
				system("pause");
				system("cls");
				break;
			case 0:
				system("cls");
				break;
			default:
				goto admin;
			}
			break;
		default:
			break;
		}
	}

	return 0;
}