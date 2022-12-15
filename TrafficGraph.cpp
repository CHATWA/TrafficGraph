// TrafficGraph.cpp
#include "TrafficGraph.h"
#include <iostream>
using namespace std;

///////////////////////////////////ͼ����///////////////////////////////////
// ��ͨͼ���캯��
TrafficGraph::TrafficGraph(VertexType V[], GraphInfo GI[], int n, int e)
{
	// ����������
	VexNum = n;
	ArcNum = e;
	// ��̬�����ʼ��
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
	// ��������ı���Ϣ
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
// �༭���б�
void TrafficGraph::EidtEdge(int start, int end, int flag, int weight)
{
	switch (flag)
	{
	case 1:
		Edge[start][end].distance = weight;
		return;
	case 2:
		Edge[start][end].time = weight;
		return;
	case 3:
		Edge[start][end].cost = weight;
		return;
	case 4:
		Edge[start][end].len = weight;
		return;
	}
}
// �����±�
void TrafficGraph::AddEdge(int start, int end, EdgeType e)
{
	Edge[start][end] = e;
}
// ��ӡ����յ����
void TrafficGraph::PrintCity(int v1, int v2)
{
	cout << Vex[v1] << " -> " << Vex[v2];
}
// ��ӡ�ڽӾ���flagѡ����ʲôΪȨֵ��1���룬2ʱ�䣬3���ѣ�4��ת��
void TrafficGraph::PrintGraphMat(int flag)
{
	cout << "\n\t\t\tGraphMat" << endl;
	switch (flag)
	{
	case 1:
		cout << "\t\t\tdistance" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
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
	case 2:
		cout << "\t\t\ttime" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
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
	case 3:
		cout << "\t\t\tcost" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
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
	case 4:
		cout << "\t\t\t������ת" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Edge[i][k].len == INFINITY)
					cout << "��\t";
				else
					cout << Edge[i][k].len << "\t";
			}
			cout << endl;
		}
		return;
	}
}
// ��ӡDist����flagѡ����ʲôΪȨֵ��1���룬2ʱ�䣬3���ѣ�4��ת��
void TrafficGraph::PrintDistMat(int flag)
{
	cout << "\n\t\t\tDistMat" << endl;
	switch (flag)
	{
	case 1:
		cout << "\t\t\tdistance" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Dist[i][k].distance == INFINITY)
					cout << "��\t";
				else
					cout << Dist[i][k].distance << "\t";
			}
			cout << endl;
		}
		return;
	case 2:
		cout << "\t\t\ttime" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Dist[i][k].time == INFINITY)
					cout << "��\t";
				else
					cout << Dist[i][k].time << "\t";
			}
			cout << endl;
		}
		return;
	case 3:
		cout << "\t\t\tcost" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Dist[i][k].cost == INFINITY)
					cout << "��\t";
				else
					cout << Dist[i][k].cost << "\t";
			}
			cout << endl;
		}
		return;
	case 4:
		cout << "\t\t\t������ת" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Dist[i][k].len == INFINITY)
					cout << "��\t";
				else
					cout << Dist[i][k].len << "\t";
			}
			cout << endl;
		}
		return;
	}
}
// ��ӡPath����flagѡ����ʲôΪȨֵ��1���룬2ʱ�䣬3���ѣ�4��ת��
void TrafficGraph::PrintPathMat(int flag)
{
	cout << "\n\t\t\tPathMat" << endl;
	switch (flag)
	{
	case 1:
		cout << "\t\t\tdistance" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Path[i][k].distance == INFINITY)
					cout << "��\t";
				else
					cout << Path[i][k].distance << "\t";
			}
			cout << endl;
		}
		return;
	case 2:
		cout << "\t\t\ttime" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Path[i][k].time == INFINITY)
					cout << "��\t";
				else
					cout << Path[i][k].time << "\t";
			}
			cout << endl;
		}
		return;
	case 3:
		cout << "\t\t\tcost" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Path[i][k].cost == INFINITY)
					cout << "��\t";
				else
					cout << Path[i][k].cost << "\t";
			}
			cout << endl;
		}
		return;
	case 4:
		cout << "\t\t\t������ת" << endl;
		for (int i = 0; i < VexNum; i++)
		{
			cout << "\t\t\t";
			for (int k = 0; k < VexNum; k++)
			{
				if (Path[i][k].len == INFINITY)
					cout << "��\t";
				else
					cout << Path[i][k].len << "\t";
			}
			cout << endl;
		}
		return;
	}
}
// ��ӡ��Ȩ·����
void TrafficGraph::PrintInfo(int start, int end, int flag)
{
	switch (flag)
	{
	case 1:
		cout << " �����Ϊ " << Dist[start][end].distance << " ����" << endl;
		break;
	case 2:
		cout << " ���ѽ�Ϊ " << Dist[start][end].cost << " Ԫ" << endl;
		break;
	case 3:
		cout << " ��ʱ��Ϊ " << Dist[start][end].time << " Сʱ" << endl;
		break;
	case 4:
		cout << " ��ת�������� " << Dist[start][end].len - 1 << " ��" << endl;
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
			Path[i][j].len = -1;
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
				if (Dist[j][k].distance > Dist[j][i].distance + Dist[i][k].distance)
				{
					// ����Dist[][]~
					Dist[j][k].distance = Dist[j][i].distance + Dist[i][k].distance;
					// ��path��˵����ͨ��˭��ת��
					Path[j][k].distance = i;
				}
				if (Dist[j][k].cost > Dist[j][i].cost + Dist[i][k].cost)
				{
					Dist[j][k].cost = Dist[j][i].cost + Dist[i][k].cost;
					Path[j][k].cost = i;
				}
				if (Dist[j][k].time > Dist[j][i].time + Dist[i][k].time)
				{
					Dist[j][k].time = Dist[j][i].time + Dist[i][k].time;
					Path[j][k].time = i;
				}
				if (Dist[j][k].len > Dist[j][i].len + Dist[i][k].len)
				{
					Dist[j][k].len = Edge[j][i].len + Edge[i][k].len;
					Path[j][k].len = i;
				}
			}
		}
	}
}

// ��¼����һ��ʼ���յ㣨���������
int destination = -1;
// ��¼��һ������Ľڵ��ţ���ֹ�ظ����
int out = -1;
// ��ʼ������·��
void TrafficGraph::InitFind(int end)
{
	destination = end;
	out = -1;
}
// ��ӡ������·����flagΪ����ʲô���أ�
void TrafficGraph::FindPath(int start, int end, int flag)
{
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
	case 4:
		mid = Path[start][end].len;
		break;
	default:
		cout << "\t\t\t�������" << endl;
		return;
	}
	// �������յ�û���м���ˣ���������
	if (mid == -1)
	{
		// Ҫ��������ǲ����Ѿ�����ˣ��ǾͲ������
		if (out != start)
			cout << Vex[start] << " -> ";
	}
	// �����м��͵ݹ�
	else
	{
		FindPath(start, mid, flag);
		FindPath(mid, end, flag);
	}
	// Ҫ�����յ��ǲ����Ѿ�����ˣ��ǾͲ������
	if (out != end)
	{
		cout << Vex[end];
		// ��û�е��������յ�ʱ��ӡ->
		if (destination != end)
			cout << " -> ";
		out = end;
	}
}

///////////////////////////////////��ʾ�˵�///////////////////////////////////
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
	cout << "\t\t\t*---------------------������ĵ���----------------------*\n";
	cout << "\t\t\t*   1) ������                                         *\n";
	cout << "\t\t\t*   2) ��ͻ���                                         *\n";
	cout << "\t\t\t*   3) ���ʱ��                                         *\n";
	cout << "\t\t\t*   4) ������ת                                         *\n";
	//cout << "\t\t\t*   5) �ۺϿ���                                         *\n";
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
// ����Ա�˵�
void AdminMenu()
{
	cout << endl;
	cout << "\t\t\t*------------------����һ����ֵĲ˵�-------------------*\n";
	cout << "\t\t\t*   1) ��ӡ                                             *\n";
	cout << "\t\t\t*   2) �޸ı�                                           *\n";
	cout << "\t\t\t*   3) ��ӱ�                                           *\n";
	cout << "\t\t\t*   0) �˳�                                             *\n";
	cout << "\t\t\t*-------------------------------------------------------*\n";
	cout << "\t\t\t������-^_^-��";
}

//void TrafficGraph::Min_Max(GraphInfo GI[])
//{
//	// 0��С��1���
//	double dis[2] = { 99999,-1 };
//	double cost[2] = { 99999,-1 };
//	double time[2] = { 99999, -1 };
//	for (int i = 0; i < VexNum; i++)
//	{
//		if (dis[0] > GI[i].Weight.distance)
//			dis[0] = GI[i].Weight.distance;
//		if (dis[1] < GI[i].Weight.distance)
//			dis[1] = GI[i].Weight.distance;
//		if (time[0] > GI[i].Weight.time)
//			time[0] = GI[i].Weight.time;
//		if (time[1] < GI[i].Weight.time)
//			time[1] = GI[i].Weight.time;
//		if (cost[0] > GI[i].Weight.cost)
//			cost[0] = GI[i].Weight.cost;
//		if (cost[1] < GI[i].Weight.cost)
//			cost[1] = GI[i].Weight.cost;
//	}
//
//	double* _dis = new double[VexNum];
//	double* _time = new double[VexNum];
//	double* _cost = new double[VexNum];
//	for (int i = 0; i < VexNum; i++)
//	{
//		_dis[i] = ((double)GI[i].Weight.distance - dis[0]) / (dis[1] - dis[0]);
//		_time[i] = ((double)GI[i].Weight.time - time[0]) / (time[1] - time[0]);
//		_cost[i] = ((double)GI[i].Weight.cost - cost[0]) / (cost[1] - cost[0]);
//	}
//	for (int i = 0; i < VexNum; i++)
//		GI[i].Weight.best = _dis[i] + _time[i] + _cost[i];
//	delete[]_dis;
//	delete[]_time;
//	delete[]_cost;
//}