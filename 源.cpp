#include "LinkList.hpp"

void text()
{
	//����LinkList
	LinkListClass LList;
	
	//���԰�λ����
	for (int i = 1; i < 12; i++)
	{
		LList.ListInsert(i, i * 2);
	}

	//���԰�λ����
	std::cout << "��" << 3 << "λԪ��Ϊ��" << LList.GetElem(3)->elem << std::endl;

}

int main(void)
{
	text();

}