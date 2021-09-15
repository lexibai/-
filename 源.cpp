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

}

int main(void)
{
	text();

}