#include "LinkList.hpp"
#include "olderStack.hpp"

void text()
{
	//����LinkList
	LinkListClass LList;

	//���԰�λ����
	for (int i = 1; i < 20000000; i++)
	{
		LList.InsertNextNode(LList.GetL(), i);
		std::cout << "�����ţ����ǵ�" << i << "Ԫ����" << std::endl;
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
	std::cout << "������Ϊ��" << LList.Length() << std::endl;

	//����ɾ����Ӧ�ڵ�
	if (LList.DeleteNode(LList.GetElem(3)))
	{
		std::cout << "������Ϊ��" << LList.Length() << std::endl;
	}
	else
	{
		std::cout << "ɾ��ʧ��" << std::endl;
	}
	
	std::cout << "������Ϊ��" << LList.Length() << std::endl;
	//�������һ��Ԫ�ص�ָ��
	if (LList.LiseDelete(9, e))
		std::cout << "ɾ����λ��Ϊ9��Ԫ�أ�" << e;

	//����ָ���ڵ�ĺ�巨
	LList.InsertNextNode(LList.GetEndNode(), 522);
	LList.InsertNextNode(LList.GetHeadNode(), 314);

	//���Ժ�巨��������
	//LList.PushBack();

	//����ͷ�巨
	//LList.PushHead();

	
	//���Ե���
	LList.ListInverse(LList.GetL());

}

//����ջ
void text1()
{
	//������һ��ջ
	Stack s;

	//��ʼ��ջ
	InitStack(&s);

	//�ж�ջ�Ƿ�Ϊ��
	if (isEmpty(&s))
	{
		std::cout << "�յģ����ˣ��Ͻ��弸��Ԫ�ؽ�����" << std::endl;
	}
	else
	{
		std::cout << "��Ԫ���ˣ�Ҫ��������" << std::endl;
	}

	//��ջ�в���13��ֵ
	for (int i = 0; i < 13; i++)
	{
		push(&s, i * 2);
	}

	//�������γ�ջ�������������ջ��Ԫ��
	for (int i = 0; i < 3; i++)
	{
		int p;
		pop(&s, p);
		std::cout << "��" << i << "�γ�ջ�� " << p << std::endl;
	}

	//�������γ�ջ����
	for (int i = 0; i < 3; i++)
	{
		pop(&s);
	}

	//�鿴��ǰջ��Ԫ��
	int p;
	pop(&s, p);
	std::cout << "��ջ�� " << p << std::endl;

	//�ж�ջ�Ƿ�Ϊ��
	if (isEmpty(&s))
	{
		std::cout << "�յģ����ˣ��Ͻ��弸��Ԫ�ؽ�����" << std::endl;
	}
	else
	{
		std::cout << "��Ԫ���ˣ�Ҫ��������" << std::endl;
	}


}

int main(void)
{
	text1();

	return 0;
}