#include "stdafx.h"
#include "SmartPoint.h"

#include <memory>

#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

void TestSharedPtr();
void TestMySharedPtr();
void TestSharedPtrLeak();
void TestSharedPtrSample();
void TestSmartPointInit();




void TestSmartPoint20200811()
{
	TestSmartPointInit();

	TestSharedPtr();

	system("cls");
	TestMySharedPtr();

	system("cls");
	TestSharedPtrLeak();

	system("cls");
	TestSharedPtrSample();
}

void TestSharedPtr()
{
	shared_ptr<MyObject> p2;

	{
		shared_ptr<MyObject> p1 = std::make_shared<MyObject>();
		cout << "get:" << p1.get() << "	" << "use_count:" << p1.use_count() << endl;

		p2 = p1;
		cout << "get:" << p1.get() << "	" << "use_count:" << p1.use_count() << endl;
		cout << "get:" << p2.get() << "	" << "use_count:" << p2.use_count() << endl;
	}

	cout << "get:" << p2.get() << "	" << "use_count:" << p2.use_count() << endl;
}

void TestMySharedPtr()
{
	SharedPtr<MyObject> p2;

	{
		SharedPtr<MyObject> p1(new MyObject);
		cout << "get:" << p1.get() << "	" << "use_count:" << p1.use_count() << endl;

		(*p1).Show();

		p2 = p1;
		p2->Show();
		cout << "get:" << p1.get() << "	" << "use_count:" << p1.use_count() << endl;
		cout << "get:" << p2.get() << "	" << "use_count:" << p2.use_count() << endl;
	}

	cout << "get:" << p2.get() << "	" << "use_count:" << p2.use_count() << endl;
}


class BB;
class AA
{
public:
	~AA() { std::cout << "~AA()" << std::endl; }
	SharedPtr<BB> pb_;
};
class BB
{
public:
	~BB() { std::cout << "~BB()" << std::endl; }
	weak_ptr<AA> pa_;
};

void TestSharedPtrLeak()
{
	return;
	bool isTestRight = false;

	if(isTestRight)
	{
		shared_ptr<AA> pa(new AA());
		shared_ptr<BB> pb(new BB());
		pb->pa_ = pa;
		//pa->pb_ = pb;
		cout << pb.use_count() << endl;
		cout << pa.use_count() << endl;
	}
	else
	{
		SharedPtr<A> pa(new A());
		SharedPtr<B> pb(new B());
		pb->pa_ = pa;
		pa->pb_ = pb;
		cout << pb.use_count() << endl;
		cout << pa.use_count() << endl;

		cout << "memory leak" << endl;
	}
}






struct Base
{
	Base() { std::cout << "  Base::Base()\n"; }
	// Note: non-virtual destructor is OK here
	~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived : public Base
{
	Derived() { std::cout << "  Derived::Derived()\n"; }
	~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::shared_ptr<Base> lp = p; // thread-safe, even though the
								  // shared use_count is incremented
	{
		static std::mutex io_mutex;
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "\n>> local pointer in a thread:" << " lp.get()=" << lp.get() << ", lp.use_count()=" << lp.use_count() << "\n\n";
	}
}

void TestSharedPtrSample()
{
	std::shared_ptr<Base> p = std::make_shared<Derived>();

	std::cout << "\nCreated a shared Derived (as a pointer to Base)\n"
		<< "  p.get() = " << p.get()
		<< ", p.use_count() = " << p.use_count() << "\n\n";

	std::thread t1(thr, p), t2(thr, p), t3(thr, p);

	p.reset(); // release ownership from main

	std::cout << "Shared ownership between 3 threads and released\n"
		<< "ownership from main:\n"
		<< "  p.get() = " << p.get()
		<< ", p.use_count() = " << p.use_count() << "\n\n";

	t1.join(); t2.join(); t3.join();

	std::cout << "All threads completed, the last one deleted Derived\n";
}

void TestSmartPointInit()
{
	std::shared_ptr<MyObject> pointer;
	MyObject* p = pointer.get();
	cout << "pointer.get() = " << p << endl;

	pointer = std::make_shared<MyObject>();
}