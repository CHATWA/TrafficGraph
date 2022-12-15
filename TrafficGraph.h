#pragma once
#include <string>
using namespace std;
#define INFINITY 888880	// ����
typedef string VertexType;	// �������������

///////////////////////////////////ͼ�ṹ����///////////////////////////////////

// ��Ȩͼ��Ȩֵ����������
struct EdgeType
{
	int distance = INFINITY;		// ·�ߵľ���
	double time = INFINITY;		// ·������Ҫ��ʱ��
	int cost = INFINITY;				// ·�ߵĻ���
	int len = INFINITY;				// ·����
};

// Ϊ�˱��ʹ�ã�����һ���ṹ��������ͼ
struct GraphInfo
{
	int Vex1;					// ���
	int Vex2;					// �յ�
	EdgeType Weight;	// Ȩֵ
};

//  �ڽӾ��󴢴潻ͨͼ 
class TrafficGraph
{
public:
	TrafficGraph(VertexType V[], GraphInfo GI[], int n, int e);
	~TrafficGraph();
	void EidtEdge(int start, int end, int flag, int weight);	// �༭���б�
	void AddEdge(int start, int end, EdgeType e);			// �����±�
	void PrintGraphMat(int flag);										// ��ӡ�ڽӾ���
	void PrintDistMat(int flag);								// ��ӡDist����
	void PrintPathMat(int flag);								// ��ӡPath����
	void PrintInfo(int start, int end, int flag);			// ��ӡ��Ȩ·����
	void PrintCity(int v1, int v2);							// ��ӡ����յ����
	void Floyed();													// Floyed�㷨�����Դ���·�� 
	void FindPath(int start, int end, int flag);		// ��ӡ������·��
	//void Min_Max(GraphInfo GI[]);

private:
	VertexType* Vex;			// �����
	EdgeType** Edge;		// �ڽӾ��󣬱߱�
	EdgeType** Dist;			// Floyed�㷨�������飬��¼��Ȩ·������
	EdgeType** Path;		// Floyed�㷨·�����飬��¼�㷨������·������ת�㣩
	int VexNum;					// ��ǰ������ 
	int ArcNum;					// ��ǰ����
};

///////////////////////////////////��ʾ�˵�///////////////////////////////////
void ShowGraph();		// ��ʾ��ͨͼ�˵�
void LowcostMenu();	// ��ʾѡ��Ȩ�ز˵�
void MainMenu();		// ���˵�
void AdminMenu();		// ����Ա�˵�