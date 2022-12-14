#pragma once
#include <string>
using namespace std;
#define INFINITY 888880	// ����
typedef string VertexType;

// �������������
// ��Ȩͼ��Ȩֵ����������
struct EdgeType
{
	int distance = INFINITY;		// ·�ߵľ���
	double time = INFINITY;		// ·������Ҫ��ʱ��
	int cost = INFINITY;				// ·�ߵĻ���
	short len = 9999;
	double composite = 0;
};

// Ϊ�˱��ʹ�ã�����һ���ṹ��������ͼ
struct GraphInfo
{
	int Vex1;					// ���
	int Vex2;					// �յ�
	EdgeType Weight = { INFINITY,INFINITY,INFINITY,1,0 };	// Ȩֵ
};

//  �ڽӾ��󴢴潻ͨͼ 
class TrafficGraph
{
public:
	TrafficGraph(VertexType V[], GraphInfo GI[], int n, int e);
	~TrafficGraph();
	void PrintGraphMat(int flag);
	void PrintInfo(int start, int end, int flag);
	void PrintCity(int v1, int v2);
	void Floyed();
	void FindPath(int start, int end, int flag);

private:
	VertexType* Vex;			// �����
	EdgeType** Edge;			// �ڽӾ��󣬱߱�
	EdgeType** Dist;
	EdgeType** Path;
	int VexNum;							// ��ǰ������ 
	int ArcNum;							// ��ǰ����
};

// ����
void ShowGraph();
void LowcostMenu();
void MainMenu();