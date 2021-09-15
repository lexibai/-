#include "LinkList.hpp"

void text()
{
	//测试LinkList
	LinkListClass LList;

	//测试按位插入
	for (int i = 1; i < 12; i++)
	{
		LList.ListInsert(i, i * 2);
	}

	//测试按位查找
	std::cout << "第" << 3 << "位元素为：" << LList.GetElem(3)->elem << std::endl;
	//测试按值查找
	std::cout << "值为8的元素的地址为：" << LList.LocateElem(8) << std::endl;

	//测试获取链表长度
	std::cout << "链表长度为：" << LList.Length() << std::endl;

	//测试按位序删除元素
	int e = 0;
	if (LList.LiseDelete(3, e))
		std::cout << "删除了位序为3的元素：" << e;
	std::cout << "链表长度为：" << LList.Length() << std::endl;

	//测试删除对应节点
	if (LList.DeleteNode(LList.GetElem(3)))
	{
		std::cout << "链表长度为：" << LList.Length() << std::endl;
	}
	else
	{
		std::cout << "删除失败" << std::endl;
	}
	
	std::cout << "链表长度为：" << LList.Length() << std::endl;
	//测试最后一个元素的指针
	if (LList.LiseDelete(9, e))
		std::cout << "删除了位序为9的元素：" << e;

	//测试指定节点的后插法
	LList.InsertNextNode(LList.GetEndNode(), 522);
	LList.InsertNextNode(LList.GetHeadNode(), 314);

	//测试后插法建立链表
	LList.PushBack();

	//测试头插法
	LList.PushHead();


}

int main(void)
{
	text();

}