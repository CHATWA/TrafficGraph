#include "TrafficGraph.h"
#include <iostream>
using namespace std;

// ��ʾ��ͨͼ�˵�
void ShowGraph()
{
	cout << "\t\t\t*********************************************************" << endl;
	cout << "\t\t\t*\t\t  ��ӭʹ�ý�ͨ��ѯϵͳ!                 *" << endl;
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*\t\t\t����(1)                         *" << endl;
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*\t����(2)\t\t\t\t����(4)         *" << endl;
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*\t\t\t֣��(3)                         *" << endl;
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*\t�ɶ�(5)\t\t\t\t�Ϻ�(7)         *" << endl;
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*\t\t\t����(6)                         *" << endl;
	cout << "\t\t\t*********************************************************" << endl;
}
// ��ʾѡ��Ȩ�ز˵�
void LowcostMenu()
{
	cout << endl;
	cout << "\t\t\t*--------------------������ĵ��ǣ�---------------------*\n";
	cout << "\t\t\t*   1) ������                                         *\n";
	cout << "\t\t\t*   2) ��ͻ���                                         *\n";
	cout << "\t\t\t*   3) ���ʱ��                                         *\n";
	cout << "\t\t\t*   4) ������ת                                         *\n";
	cout << "\t\t\t*   5) �ۺϿ���                                         *\n";
	cout << "\t\t\t*                                                       *\n";
	cout << "\t\t\t*   0) ����                                             *\n";
	cout << "\t\t\t*-------------------------------------------------------*\n";
	cout << "\t\t\t�����룺";
}
// ���˵�
void MainMenu()
{
	cout << endl;
	cout << "\t\t\t*------------------------���˵�-------------------------*\n";
	cout << "\t\t\t*   1) ��ͨ��ѯ                                         *\n";
	cout << "\t\t\t*   2) ����Աģʽ                                       *\n";
	cout << "\t\t\t*   0) �˳�                                             *\n";
	cout << "\t\t\t*-------------------------------------------------------*\n";
	cout << "\t\t\t�����룺";
}

// ��ͨͼ���캯��
TrafficGraph::TrafficGraph(VertexType V[], GraphInfo GI[], int n, int e)
{
	VexNum = n;
	ArcNum = e;
	
	Vex = new VertexType[VexNum];
	Edge = new EdgeType * [VexNum];
	Path = new EdgeType * [VexNum];
	Dist = new EdgeType * [VexNum];
	for (int i = 0; i < VexNum; i++)
	{
		Edge[i] = new EdgeType[VexNum];
		Path[i] = new EdgeType[VexNum];
		Dist[i] = new EdgeType[VexNum];
	}
	for (int i = 0; i < ArcNum; i++)
	{
		if (i < VexNum)
			Vex[i] = V[i];
		GI[i].Weight.len = 1;
		Edge[GI[i].Vex1 - 1][GI[i].Vex2 - 1] = GI[i].Weight;
		Edge[GI[i].Vex2 - 1][GI[i].Vex1 - 1] = GI[i].Weight;
	}
}
// ��ͨͼ��������
TrafficGraph::~TrafficGraph()
{
	VexNum = 0;
	ArcNum = 0;
	for (int i = 0; i < VexNum; i++)
	{
		delete[]Edge[i];
		delete[]Dist[i];
	}
	delete[]Vex;
	delete[]Dist;
	delete[]Edge;
	delete[]Path;
}
// ��ӡ�ڽӾ���flagѡ����ʲôΪȨֵ��0���룬1ʱ�䣬2���ѣ�
void TrafficGraph::PrintCity(int v1, int v2)
{
	cout << Vex[v1] << " -> " << Vex[v2];
}
void TrafficGraph::PrintGraphMat(int flag)
{
	switch (flag)
	{
	case 0:
		for (int i = 0; i < VexNum; i++)
		{
			for (int k = 0; k < VexNum; k++)
			{
				if (Edge[i][k].distance == INFINITY)
					cout << "��\t";
				else
					cout << Edge[i][k].distance << "\t";
			}
			cout << endl;
		}
		return;
	case 1:
		for (int i = 0; i < VexNum; i++)
		{
			for (int k = 0; k < VexNum; k++)
			{
				if (Edge[i][k].time == INFINITY)
					cout << "��\t";
				else
					cout << Edge[i][k].time << "\t";
			}
			cout << endl;
		}
		return;
	case 2:
		for (int i = 0; i < VexNum; i++)
		{
			for (int k = 0; k < VexNum; k++)
			{
				if (Edge[i][k].cost == INFINITY)
					cout << "��\t";
				else
					cout << Edge[i][k].cost << "\t";
			}
			cout << endl;
		}
		return;
	}
}
void TrafficGraph::PrintInfo(int start, int end, int flag)
{
	switch (flag)
	{
	case 0:
		return;
	case 1:
		cout << " �����Ϊ " << Dist[start][end].distance << " ����" << endl;
		break;
	case 2:
		cout << " ��ʱ��Ϊ " << Dist[start][end].time << " Сʱ" << endl;
		break;
	case 3:
		cout << " ���ѽ�Ϊ " << Dist[start][end].cost << " Ԫ" << endl;
		break;
	case 4:
		cout << " ��ת�������� " << Dist[start][end].len << " ��" << endl;
		break;
	case 5:
		break;
	default:
		return;
	}
}
// floyed�㷨�����Դ���·��
void TrafficGraph::Floyed()
{
	for (int i = 0; i < VexNum; i++)
	{
		for (int j = 0; j < VexNum; j++)
		{
			Dist[i][j] = Edge[i][j];
			Path[i][j].cost = -1;
			Path[i][j].distance = -1;
			Path[i][j].time = -1;
		}
	}
	// ���ѭ����ʾ���һ������Vi��Ϊ��ת
	for (int i = 0; i < VexNum; i++)
	{
		// �ڲ�˫ѭ������������������
		for (int j = 0; j < VexNum; j++)
		{
			for (int k = 0; k < VexNum; k++)
			{
				// ��Dist���ֵ�Ѿ��������·��ʱ
				// ����Ϊͨ����ת��Vi��·����
				// �������������ֵ��ǵ�����˼�� 
				// Dist���ֵ��Զ�������ţ��������С���������㷨�ǳ���
				if (Dist[j][k].distance > Edge[j][i].distance + Edge[i][k].distance)
				{
					// ����Dist[][]~
					Dist[j][k].distance = Edge[j][i].distance + Edge[i][k].distance;
					// ��path��˵����ͨ��˭��ת��
					Path[j][k].distance = i;
				}
				if (Dist[j][k].cost > Edge[j][i].cost + Edge[i][k].cost)
				{
					// ����Dist[][]~
					Dist[j][k].cost = Edge[j][i].cost + Edge[i][k].cost;
					// ��path��˵����ͨ��˭��ת��
					Path[j][k].cost = i;
				}
				if (Dist[j][k].time > Edge[j][i].time + Edge[i][k].time)
				{
					// ����Dist[][]~
					Dist[j][k].time = Edge[j][i].time + Edge[i][k].time;
					// ��path��˵����ͨ��˭��ת��
					Path[j][k].time = i;
				}
			}
		}
	}
}
// ��ӡ������·����flagΪ����ʲô���أ�
void TrafficGraph::FindPath(int start, int end, int flag)
{
	static int destination = end;
	//
	static int out = -1;
	// ��ת��
	int mid = -1;
	switch (flag)
	{
	case 0:
		return;
	case 1:
		mid = Path[start][end].distance;
		break;
	case 2:
		mid = Path[start][end].cost;
		break;
	case 3:
		mid = Path[start][end].time;
		break;
	case 4:
		mid = Path[start][end].len;
		break;
	case 5:
		mid = Path[start][end].composite;
		break;
	default:
		cout << "\t\t\t�������" << endl;
		return;
	}
	if (mid == -1)
	{
		if (out != start)
			cout << Vex[start] << " -> ";
	}
	else
	{
		FindPath(start, mid, flag);
		FindPath(mid, end, flag);
	}
	if (out != end)
	{
		cout << Vex[end];
		if (destination != end)
			cout << " -> ";
		out = end;
	}
}