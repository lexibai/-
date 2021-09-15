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
	//��������һ���ڵ��ָ��
	LNode* EndP;

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

		this->EndP = L;
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
				//���в���
				newElem->next = p->next;
				newElem->elem = e;
				p->next = newElem;
				this->linkSize++;

				//�жϲ���λ���Ƿ�Ϊ���һ�������������һ��Ԫ��ָ���λ��
				if (i == this->linkSize)this->EndP = newElem;

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

		//��ɾ���������һ��Ԫ��ʱ���������һ��Ԫ�صĽڵ�
		if (i == this->linkSize)this->EndP = this->GetElem(i - 1);

		e = this->GetElem(i)->elem;

		LNode* p = GetElem(i - 1)->next;//��¼Ҫɾ���Ľڵ�
		this->GetElem(i - 1)->next = this->GetElem(i)->next;//�߼���ɾ������ڵ�
		this->linkSize--;

		//�ͷ�Ҫɾ���Ŀռ䣨������ɾ������ڵ㣩
		delete(p);
		

		return true;
	}

	//ָ���ڵ��ɾ��
	bool DeleteNode(LNode* n)
	{
		if (n == nullptr)return false;
	
		/// ɾ��ָ���ڵ�
		if (n->next == nullptr)//�˽ڵ�Ϊ���һ���ڵ�ʱ��ɾ������
		{
			delete(n);
			this->GetElem(this->linkSize - 1)->next = nullptr;
			this->linkSize--;
			return true;
		}
		LNode* p = n->next;//��¼Ҫɾ���Ľڵ㣬�˽ڵ���������Ҫɾ���ڵ����һ����
		n->elem = n->next->elem;//���߼���ɾ���ڵ�
		n->next = nullptr;
		this->linkSize--;
		//������ɾ��
		delete(p);
		return true;

	}

	//ͷ�巨����������
	bool PushHead(int e)
	{

	}

	//β�巨����������
	bool PushBack(int e)
	{

	}

};



#endif//��������