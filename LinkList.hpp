//��������
#ifndef LINKLIST_HPP
#define LINKLIST_HPP

#include <iostream>

//����һ����������Ľṹ��
typedef struct LNode {
	int elem;
	struct LNode* next;
}LNode,*LinkList;

//����������
class LinkListClass
{
	//����ͷ
	LinkList L;
	//������
	int linkSize;

public:
	//���캯��
	LinkListClass()
	{
		this->InitLinkList();
	}

	//��ʼ������
	void InitLinkList()
	{
		this->L = new(LNode);
		this->L->elem = 0;
		this->L->next = nullptr;

		this->linkSize = 0;
	}

	//��λ�����
	LNode* GetElem(int i)
	{
		if (i < 1 || i>this->linkSize)return nullptr;
		
		LNode* p = L->next;
		//pָ��λ��1�Ľڵ�
		for (int j = 1; j <= i; j++)
		{
			if (p == nullptr)
			{
				std::cout << "�˽ڵ㲻����" << std::endl;
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

	//��ֵ����
	LNode* LocateElem(int num)
	{

		LNode* p = L->next;
		//pָ��λ��1�Ľڵ�
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

	//��������
	int Length()
	{
		return this->linkSize;
	}

	 
	//��λ�����
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

	//ָ���ڵ�ĺ�巨
	bool InsertNextNode(LNode* n, int e)
	{

	}

	//ָ���ڵ��ǰ�巨
	bool InsertPriorNode(LNode* n, int e)
	{

	}

	//��λ��ɾ��
	bool LiseDelete(int i, int& e)
	{
		if (i<1 || i>this->linkSize)return false;

		e = this->GetElem(i)->elem;

		LNode* p = GetElem(i - 1)->next;//��¼Ҫɾ���Ľڵ�
		this->GetElem(i - 1)->next = this->GetElem(i)->next;//�߼���ɾ������ڵ�

		//�ͷ�Ҫɾ���Ŀռ䣨������ɾ������ڵ㣩
		delete(p);

		return true;
	}

	//ָ���ڵ��ɾ��
	bool DeleteNode(LNode* n)
	{

	}

	//ͷ�巨����������
	bool PushHead()
	{

	}

	//β�巨����������
	bool PushBack()
	{

	}

};



#endif//��������