/*#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Common.h"
#include"ConcurrentMalloc.h"
#include"ThreadCache.h"
#include<vector>

void UintThreadCache()//单元测试
{
	ThreadCache tc;
	std::vector<void*> v;
	for (size_t i = 0; i < 21; i++)
	{
		v.push_back(tc.Alloct(7));
	}

	for (size_t i = 0; i < 21; i++)
	{
		printf("[%d]->%p\n",i,v[i]);
	}

	for (auto ptr : v)
	{
		tc.Deallocte(ptr, 7);
	}
}

void TestRoundUp()
{
	cout << SizeClass::RoundUp(1) << endl;
	cout << SizeClass::RoundUp(127) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(129) << endl;
	cout << SizeClass::RoundUp(1023) << endl;
	cout << endl;

	cout << SizeClass::ListIndex(1) << endl;
	cout << SizeClass::ListIndex(128) << endl;
	cout << endl;


}

void UintTest()
{
	void* ptr = SystemAlloc(MAX_PAGES - 1);
	PAGE_ID id = (PAGE_ID)ptr >> PAGE_SHIFT;
	void*  ptrshift = (void*)(id << PAGE_SHIFT);

	char* boj1 = (char*)ptr;
	char* boj2 = (char*)ptr+8;
	char* boj3 = (char*)ptr + 16;

	PAGE_ID id1 = (PAGE_ID)boj2 >> PAGE_SHIFT;
	PAGE_ID id2 = (PAGE_ID)boj3 >> PAGE_SHIFT;
}
void UnitThreadCache1()
{
	ThreadCache tc;
	void* ptr1 = tc.Alloct(6);
	void* ptr2 = tc.Alloct(6);
	void* ptr3 = tc.Alloct(6);
}
void funcl(size_t n)
{
	for (size_t i = 0; i < n; ++i)
		cout << i << endl;
}*/
/*int main()
{
	//UintThreadCache();
	//TestRoundUp();
//	UintTest();


	//void* ptr1 = ConcurrentMalloc(1 << PAGE_SHIFT); //向thread cache申请 :::: 1页
	//void* ptr2 = ConcurrentMalloc(65 << PAGE_SHIFT);//向page cache申请  :::: 65页
	//void* ptr3 = ConcurrentMalloc(129 << PAGE_SHIFT);//向系统申请	:::: 129页

	//ConcurrentFree(ptr1);
	//ConcurrentFree(ptr2);
	//ConcurrentFree(ptr3);

	std::thread t1(funcl, 100);
	std::thread t2(funcl, 100);

	t1.join();
	t2.join();
	system("pause");
	return 0;
}*/
