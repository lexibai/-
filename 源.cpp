#include "LinkList.hpp"
#include "olderStack.hpp"

void text()
{
	//测试LinkList
	LinkListClass LList;

	//测试按位插入
	for (int i = 1; i < 20000000; i++)
	{
		LList.InsertNextNode(LList.GetL(), i);
		std::cout << "还活着，这是第" << i << "元素了" << std::endl;
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
	//LList.PushBack();

	//测试头插法
	//LList.PushHead();

	
	//测试倒序
	LList.ListInverse(LList.GetL());

}

//测试栈
void text1()
{
	//创建了一个栈
	Stack s;

	//初始化栈
	InitStack(&s);

	//判断栈是否为空
	if (isEmpty(&s))
	{
		std::cout << "空的，别看了，赶紧插几个元素进来。" << std::endl;
	}
	else
	{
		std::cout << "有元素了，要被塞满了" << std::endl;
	}

	//向栈中插入13个值
	for (int i = 0; i < 13; i++)
	{
		push(&s, i * 2);
	}

	//进行三次出栈操作，并输出出栈的元素
	for (int i = 0; i < 3; i++)
	{
		int p;
		pop(&s, p);
		std::cout << "第" << i << "次出栈： " << p << std::endl;
	}

	//进行三次出栈操作
	for (int i = 0; i < 3; i++)
	{
		pop(&s);
	}

	//查看当前栈顶元素
	int p;
	pop(&s, p);
	std::cout << "出栈： " << p << std::endl;

	//判断栈是否为空
	if (isEmpty(&s))
	{
		std::cout << "空的，别看了，赶紧插几个元素进来。" << std::endl;
	}
	else
	{
		std::cout << "有元素了，要被塞满了" << std::endl;
	}


}

int main(void)
{
	text1();

	return 0;
}