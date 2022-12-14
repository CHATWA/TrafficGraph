//  sqqueue.hpp
//////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////����Ϊ����ʵ��//////////////////////////////////

#include "StatusCode.h"
#include <iostream>
using namespace std;

#define MaxSize 10		// ������󳤶�
#define ElemType int	// ����Ԫ�ص���������

// ѭ�����еĶ���
typedef struct
{
	ElemType* base;	// ��̬����ָ��
	int front;				// ͷָ�룬ָ���ͷ
	int rear;				// βָ�룬ָ���β
}SqQueue;

Status InitQueue(SqQueue& Q);							// ��ʼ������
Status DestroyQueue(SqQueue& Q);					// ���ٶ���
Status QueueEmpty(SqQueue Q);						// �����п�
Status EnQueue(SqQueue& Q, ElemType e);		// ���
Status DeQueue(SqQueue& Q, ElemType& e);	// ����