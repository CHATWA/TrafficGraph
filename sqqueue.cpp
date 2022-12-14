#include "sqqueue.h"

// ��ʼ������
Status InitQueue(SqQueue& Q)
{
	Q.base = new ElemType[MaxSize]; // ���䶯̬�ռ�
	// ���baseָ��ΪNULL������ռ����ʧ��
	if (!Q.base)
	{
		cout << "���г�ʼ��ʧ�ܣ�" << endl;
		return OVERFLOW;
	}
	Q.front = Q.rear = 0;	// �ռ����ɹ�����ʼ����ͷ���βָ��
	return OK;
}
// ���ٶ���
Status DestroyQueue(SqQueue& Q)
{
	delete Q.base;		// �ͷŶ�̬����Ŀռ�
	Q.base = NULL;	// ����ָ���ÿ�
	Q.front = Q.rear = 0; // ͷβ��0�����п�
	return OK;
}
// �����п�
Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
// ���
Status EnQueue(SqQueue& Q, ElemType e)
{
	// �ж϶��Ƿ����������򷵻ش���
	if ((Q.rear + 1) % MaxSize == Q.front)
	{
		cout << "����������" << endl;
		return ERROR;
	}
	Q.base[Q.rear] = e;		// Ԫ��e���β
	Q.rear = (Q.rear + 1) % MaxSize;	// ����ѭ�������߼���ʹβָ���߼�����
	return OK;
}
// ����
Status DeQueue(SqQueue& Q, ElemType& e)
{
	// �ж϶��Ƿ��ѿգ����򷵻ش���
	if (Q.front == Q.rear)
	{
		cout << "�ӿգ�����" << endl;
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MaxSize;	// ����ѭ�������߼���ʹͷָ���߼�����
	return OK;
}