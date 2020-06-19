#include "stdafx.h"
#include <thread>
#include <mutex>
#include <atomic>

#include <fstream>

using namespace std;

// Also: atomic<T> t;
atomic_llong total(0);
atomic<int> t(0);
atomic_flag myLock = ATOMIC_FLAG_INIT;

ofstream outFile(DESKTOP_FILE_TXT,ios::out|ios::binary);

atomic<int> a{ 0 };
atomic<int> b{ 0 };
void SetValue(int)
{
	for (auto i = 0; i < 1000000000LL; ++i)
	{
		int t = 1;
		a.store(t, memory_order_relaxed);
		b.store(2, memory_order_relaxed);
	}	
}
void Observer(int)
{
	for (auto i = 0; i < 1000000000LL; ++i)
	{
		outFile << a << b << endl;
	}
}


void f()
{
	while (myLock.test_and_set(std::memory_order_acquire))// 有利于编译器释放并行的潜在性能
	{
		cout << "Thread1 Waiting from thread2... " << endl;
	}
	cout << "Thread1 starts working" << endl;
}

void g()
{
	cout << "Thread2 is going to start." << endl;
	myLock.clear();
	cout << "Thread2 starts working" << endl;
}

void threadHandle()
{
	for (auto i = 0; i < 100000000LL; ++i)
	{
		total += i;
	}
}
////////////////////////////////////////////////////////////////////
void testThread()
{
	//// 1.atomic
	//thread thread1(threadHandle);
	//thread thread2(threadHandle);
	//
	//thread1.join();
	//thread2.join();
	//cout << total << endl;

	//// 2.
	//myLock.test_and_set();
	//thread t1(f);
	//thread t2(g);

	//t1.join();
	//Sleep(1000);
	//t2.join();// 让线程t1等待线程t2结束

	//// 3.
	//thread T1(SetValue,0);
	//thread T2(Observer, 0);

	//T1.join();
	//T2.join();
	//outFile.close();
}

