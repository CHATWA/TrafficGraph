#pragma once
#include <string>
using namespace std;
#define INFINITY 888880	// ����
typedef string VertexType;

// �������������
// ��Ȩͼ��Ȩֵ����������
class EdgeType
{
public:
	EdgeType();
	~EdgeType();

private:
	int distance;		// ·�ߵľ���
	double time;	// ·������Ҫ��ʱ��
	int cost;			// ·�ߵĻ���
};

EdgeType::EdgeType()
{

}

EdgeType::~EdgeType()
{

}
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
	void PrintGraphMat(int flag);
	void Floyed(int start,int );
private:
	VertexType* Vex;			// �����
	EdgeType** Edge;			// �ڽӾ��󣬱߱�
	EdgeType** Path;
	//bool Visited[MaxVertex];				// ���ʱ������
	int VexNum;							// ��ǰ������ 
	int ArcNum;							// ��ǰ����
};

// ����
void ShowGraph();
void LowcostMenu();
void MainMenu();