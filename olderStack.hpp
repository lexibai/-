#pragma once
#define MAX_SIZE 30
#include <malloc.h>

typedef struct stack
{
	int stack[MAX_SIZE];
	int size;
}Stack;

//栈的初始化
void InitStack(Stack* stack)
{
	//值为-1时表示无元素
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack->stack[i] = -1;
	}

	stack->size = -1;

}


//入栈操作
bool push(Stack* stack, int e)
{
	//将元素e入栈，如果入栈成功，返回true，否则返回false

	//判断栈是否满
	if (stack->size >= MAX_SIZE - 1) return false;

	//入栈
	stack->size++;
	stack->stack[stack->size] = e;

	return true;
}

//出栈操作
bool pop(Stack* stack, int* e)
{
	//将栈中栈顶的元素出栈，将此元素的值赋给e，并返回出栈结果，出栈成功返回true，否则返回false

	//判断栈中是否存在元素
	if (stack->size < 0)return false;

	int* p = (int*)malloc(sizeof(int));

	//出栈
	*p = stack->stack[stack->size];
	e = p;
	stack->stack[stack->size] = -1;
	stack->size--;

	return true;
}

//出栈操作重载
bool pop(Stack* stack)
{
	//将栈中栈顶的元素出栈，返回出栈结果，出栈成功返回true，否则返回false
		//判断栈中是否存在元素
	if (stack->size < 0)return false;

	//出栈
	stack->stack[stack->size] = -1;
	stack->size--;

	return true;
}

//查找栈顶元素，但不删除
int find(Stack stack)
{
	//返回栈顶元素
}

//判断栈是否为空
bool isEmpty(Stack stack)
{
	//如果栈中元素为空，返回true，否则返回false
}