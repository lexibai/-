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
}

int main(void)
{
	text();

}