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
	//���԰�ֵ����
	std::cout << "ֵΪ8��Ԫ�صĵ�ַΪ��" << LList.LocateElem(8) << std::endl;

	//���Ի�ȡ������
	std::cout << "������Ϊ��" << LList.Length() << std::endl;

	//���԰�λ��ɾ��Ԫ��
	int e = 0;
	if (LList.LiseDelete(3, e))
		std::cout << "ɾ����λ��Ϊ3��Ԫ�أ�" << e;
}

int main(void)
{
	text();

}