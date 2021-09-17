#pragma once
#define MAX_SIZE 30
#include <malloc.h>

typedef struct stack
{
	int stack[MAX_SIZE];
	int size;
}Stack;

//ջ�ĳ�ʼ��
void InitStack(Stack* stack)
{
	//ֵΪ-1ʱ��ʾ��Ԫ��
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->stack[i] = -1;
	}

	stack->size = -1;

}


//��ջ����
bool push(Stack* stack, int e)
{
	//��Ԫ��e��ջ�������ջ�ɹ�������true�����򷵻�false

	//�ж�ջ�Ƿ���
	if (stack->size >= MAX_SIZE - 1) return false;

	//��ջ
	stack->size++;
	stack->stack[stack->size] = e;

	return true;
}

//��ջ����
bool pop(Stack* stack, int* e)
{
	//��ջ��ջ����Ԫ�س�ջ������Ԫ�ص�ֵ����e�������س�ջ�������ջ�ɹ�����true�����򷵻�false

	//�ж�ջ���Ƿ����Ԫ��
	if (stack->size < 0)return false;

	int* p = (int*)malloc(sizeof(int));

	//��ջ
	*p = stack->stack[stack->size];
	e = p;
	stack->stack[stack->size] = -1;
	stack->size--;

	return true;
}

//��ջ��������
bool pop(Stack* stack)
{
	//��ջ��ջ����Ԫ�س�ջ�����س�ջ�������ջ�ɹ�����true�����򷵻�false
		//�ж�ջ���Ƿ����Ԫ��
	if (stack->size < 0)return false;

	//��ջ
	stack->stack[stack->size] = -1;
	stack->size--;

	return true;
}

//����ջ��Ԫ�أ�����ɾ��
int find(Stack stack)
{
	//����ջ��Ԫ��
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack stack)
{
	//���ջ��Ԫ��Ϊ�գ�����true�����򷵻�false
}