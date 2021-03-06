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
	//链表的最后一个节点的指针
	LNode* EndP;

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

		this->EndP = L;
	}

	//按位序查找
	LNode* GetElem(int i)
	{
		if (i < 1 || i>this->linkSize)return nullptr;
		
		LNode* p = L->next;
		//p指向位序1的节点
		for (int j = 1; j <= i; j++,p=p->next)
		{
			if (p == nullptr)
			{
				std::cout << "此节点不存在,返回最后一个节点" << std::endl;
				return this->EndP;
			}
			if (j == i)
			{
				return p;
			}
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
				//进行插入
				newElem->next = p->next;
				newElem->elem = e;
				p->next = newElem;
				this->linkSize++;

				//判断插入位置是否为最后一个，并更新最后一个元素指针的位置
				if (i == this->linkSize)this->EndP = newElem;

				return true;
			}
			p = p->next;
		}

		return false;
	}

	//指定节点的后插法
	bool InsertNextNode(LNode* n, int e)
	{
		LNode* p = new(LNode);
		p->elem = e;
		p->next = n->next;
		n->next = p;

		if (n == this->EndP)
		{
			this->EndP = p;
		}

		this->linkSize++;

		return true;
	}

	//指定节点的前插法
	bool InsertPriorNode(LNode* n, int e)
	{
		//先使用后插法插入
		this->InsertNextNode(n, e);
		//交换两个元素的位置
		n->elem = n->elem + n->next->elem;
		n->next->elem = n->elem - n->next->elem;
		n->elem = n->elem - n->next->elem;

		return true;
	}

	//按位序删除
	bool LiseDelete(int i, int& e)
	{
		if (i<1 || i>this->linkSize)return false;

		e = this->GetElem(i)->elem;

		//当删除的是最后一个元素时，更新最后一个元素的节点
		if (i == this->linkSize)this->EndP = this->GetElem(i - 1);
		
		LNode* p = GetElem(i - 1)->next;//记录要删除的节点
		this->GetElem(i - 1)->next = this->GetElem(i)->next;//逻辑上删除这个节点
		this->linkSize--;

		//释放要删除的空间（物理上删除这个节点）
		delete(p);
		

		return true;
	}

	//指定节点的删除
	bool DeleteNode(LNode* n)
	{
		if (n == nullptr)return false;
	
		/// 删除指定节点
		if (n->next == nullptr)//此节点为最后一个节点时的删除方法
		{
			delete(n);
			this->EndP = this->GetElem(this->linkSize - 1);
			this->EndP->next = nullptr;
			this->linkSize--;
			return true;
		}
		LNode* p = n->next;//记录要删除的节点，此节点物理上是要删除节点的下一个。
		n->elem = n->next->elem;//从逻辑上删除节点
		n->next = p->next;
		this->linkSize--;
		//物理上删除
		delete(p);
		return true;

	}

	//头插法建立单链表
	bool PushHead()
	{
		int select = 0;
		while (true)
		{
			std::cin >> select;
			//输入-10086的时候退出建立
			if (select == -10086) return true;
			else
			{
				this->InsertNextNode(this->L, select);
			}

		}

		return false;

	}

	//尾插法建立单链表
	bool PushBack()
	{
		int select = 0;
		while (true)
		{
			std::cin >> select;
			//输入-10086的时候退出建立
			if (select == -10086) return true;
			else
			{
				this->InsertNextNode(this->EndP, select);
			}

		}
	
		return false;
	}


	//链表倒置——请务必输入链表头
	bool ListInverse(LinkList n)
	{
		if (n->next == nullptr || n->next->next == nullptr)return false;

		LNode* prenod = n;
		n = n->next;
		LNode* nexnod = n->next;

		while (n->next != nullptr)
		{
			if (prenod != this->L)
			{
				n->next = prenod;
				prenod = n;
				n = nexnod;
				nexnod = n->next;
			}
			else 
			{
				n->next = nullptr;
				prenod = n;
				n = nexnod;
				nexnod = n->next;
			}
			
		}
		n->next = prenod;//将最后一个元素逆转

		this->L->next = n;//链表头指向第一个元素

		return true;
	}

	//获取链表属性的接口
	LNode* GetEndNode()
	{
		return this->EndP;
	}

	LNode* GetHeadNode()
	{
		return this->L;
	}

	LNode* GetL()
	{
		return this->L;
	}



};



#endif//单向链表