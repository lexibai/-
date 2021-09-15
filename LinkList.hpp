//单向链表
#ifndef LINKLIST_HPP
#define LINKLIST_HPP

#include <iostream>

//定义一个单向链表的结构体
typedef struct LNode {
	int elem;
	struct LNode* next;
}LNode,*LinkList;

//单向链表类
class LinkListClass
{
	//链表头
	LinkList L;
	//链表长度
	int linkSize;

public:
	//构造函数
	LinkListClass()
	{
		this->InitLinkList();
	}

	//初始化链表
	void InitLinkList()
	{
		this->L = new(LNode);
		this->L->elem = 0;
		this->L->next = nullptr;

		this->linkSize = 0;
	}

	//按位序查找
	LNode* GetElem(int i)
	{
		if (i < 1 || i>this->linkSize)return nullptr;
		
		LNode* p = L->next;
		//p指向位序1的节点
		for (int j = 1; j <= i; j++)
		{
			if (p == nullptr)
			{
				std::cout << "此节点不存在" << std::endl;
				return nullptr;
			}
			if (j == i)
			{
				return p;
			}
			p = p->next;
		}

		return nullptr;
	}

	//按值查找
	LNode* LocateElem(int num)
	{

		LNode* p = L->next;
		//p指向位序1的节点
		while(p!=nullptr)
		{
			if (p->elem == num)
			{
				return p;
			}
			p = p->next;
		}

		return nullptr;

	}

	//求链表长度
	int Length()
	{
		return this->linkSize;
	}

	 
	//按位序插入
	bool ListInsert(int i, int e)
	{
		if (i < 1 || i>this->linkSize + 1)return false;

		LNode* newElem = new(LNode);
		LNode* p = L;
		for (int j = 1; j <= i; j++)
		{
			if (j == i)
			{
				newElem->next = p->next;
				newElem->elem = e;
				p->next = newElem;
				this->linkSize++;
				return true;
			}
			p = p->next;
		}

		return false;
	}

	//指定节点的后插法
	bool InsertNextNode(LNode* n, int e)
	{

	}

	//指定节点的前插法
	bool InsertPriorNode(LNode* n, int e)
	{

	}

	//按位序删除
	bool LiseDelete(int i, int& e)
	{
		if (i<1 || i>this->linkSize)return false;

		e = this->GetElem(i)->elem;

		LNode* p = GetElem(i - 1)->next;//记录要删除的节点
		this->GetElem(i - 1)->next = this->GetElem(i)->next;//逻辑上删除这个节点

		//释放要删除的空间（物理上删除这个节点）
		delete(p);

		return true;
	}

	//指定节点的删除
	bool DeleteNode(LNode* n)
	{

	}

	//头插法建立单链表
	bool PushHead()
	{

	}

	//尾插法建立单链表
	bool PushBack()
	{

	}

};



#endif//单向链表