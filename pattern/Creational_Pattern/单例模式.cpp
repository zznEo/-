#include <iostream>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

#if 0
class Singleton_lazy {
private:
	Singleton_lazy() {
		cout << "Singleton_lazy() 构造函数被调用！" << endl;
	}

public:
	using Ptr = shared_ptr<Singleton_lazy>;

	static Ptr getInstance() {
		if (pSingleton == nullptr) {
			lock_guard<mutex> lk(m_mutex);
			if (pSingleton == nullptr) {
				pSingleton = shared_ptr<Singleton_lazy>(new Singleton_lazy);
			}
		}

		return pSingleton;
	}
private:
	static Ptr pSingleton;
	static mutex m_mutex;
};
Singleton_lazy::Ptr Singleton_lazy::pSingleton = nullptr;
mutex Singleton_lazy::m_mutex;


#endif
class Singleton_lazy {
private:
	Singleton_lazy() {
		cout << "Singleton_lazy() 构造函数被调用！" << endl;
	}
public:
	static Singleton_lazy& getInstance() {
		static Singleton_lazy pSingleton;
		return pSingleton;
	}
	~Singleton_lazy() {
		cout << "Singleton_lazy() 析构函数被调用！" << endl;
	}
private:
};

void test1() {
	Singleton_lazy& s1 = Singleton_lazy::getInstance();
	Singleton_lazy& s2 = Singleton_lazy::getInstance();
}
#if 0
class Singleton_hungry {
private:
	Singleton_hungry() {}
	static Singleton_hungry* getInstance() { return pSingleton; }
private:
	static Singleton_hungry* pSingleton;
};
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;
#endif



int main() {
	test1();
	return 0;
}

