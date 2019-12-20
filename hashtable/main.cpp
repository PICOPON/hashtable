// hashtable.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "hashtable.h"

int main()
{
	hashtable a;
	a.addItem("zhou", "dsaddssds");
	a.addItem("wu", "eeeeeeefff");
	a.addItem("li", "uncertain");
	a.addItem("ss", "dsfs");
	a.addItem("rt", "dffggg");
	a.addItem("yy", "dffggg");
	a.addItem("uuuuu", "dffggg");
	std::cout << a.findItem("zhou");
	std::cout << a.findItem("ss");
}
