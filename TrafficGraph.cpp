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
	for (int i = 0; i < VexNum; i++)
	{
		Edge[i] = new EdgeType[VexNum];
		Path[i] = new EdgeType[VexNum];
	}

	for (int i = 0; i < ArcNum; i++)
	{
		if (i < VexNum)
			Vex[i] = V[i];
		Edge[GI[i].Vex1 - 1][GI[i].Vex2 - 1] = GI[i].Weight;
		Edge[GI[i].Vex2 - 1][GI[i].Vex1 - 1] = GI[i].Weight;
	}
}
// ��ͨͼ��������
TrafficGraph::~TrafficGraph()
{
	VexNum = 0;
	ArcNum = 0;
	delete[]Vex;
	for (int i = 0; i < VexNum; i++)
		delete[]Edge[i];
	delete[]Edge;
	delete[]Path;
}
// ��ӡ�ڽӾ���flagѡ����ʲôΪȨֵ��0���룬1ʱ�䣬2���ѣ�
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

void TrafficGraph::Floyed()
{
	EdgeType** A = new EdgeType * [VexNum];
	for (int i = 0; i < VexNum; i++)
		A[i] = new EdgeType[VexNum];

	for (int i = 0; i < VexNum; i++)
	{
		for (int j = 0; j < VexNum; j++)
		{
			A[i][j] = Edge[i][j];
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
				// ��A���ֵ�Ѿ��������·��ʱ
				// ����Ϊͨ����ת��Vi��·����
				// �������������ֵ��ǵ�����˼�� 
				// A���ֵ��Զ�������ţ��������С���������㷨�ǳ���
				if (A[j][k] > Edge[j][i] + Edge[i][k])
				{
					// ����A[][]~
					A[j][k] = Edge[j][i] + Edge[i][k];
					// ��path��˵����ͨ��˭��ת��
					path[j][k] = i;
				}
			}
		}
	}

}