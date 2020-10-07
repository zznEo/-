#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//目标接口类，客户需要的接口
class Target {
public:
	virtual void Request() {//定义标准接口
		cout << "Target::Request()" << endl;
	}
};

// 需要适配的类
class Adaptee {
public:
	void SpecificRequest() {
		cout << "Adaptee::SpecificRequest()" << endl;
	}
};

//类模式，适配器类，通过public继承获得接口继承的效果，通过private继承获得实现继承的效果
class Adapter :public Target, private Adaptee {  //通过适配器，将客户的需要和已经产生的接口进行适配。
public:
	virtual void Request() {	//实现Target定义的Request接口
		cout << "Adapter::Request()" << endl;
		this->SpecificRequest();
		cout << "----------------------------" << endl;
	}
};

void test1() {
	Target* target = new Adapter;
	target->Request();
}

//对象模式，适配器类，继承Target类，采用组合的方式实现Adaptee的复用

class Adapter1 :public Target {
public:
	Adapter1() { this->adapte = new Adaptee; }
	Adapter1(Adaptee* adapte) { this->adapte = adapte; }

	virtual void Request() {	//实现Target定义的Request接口
		cout << "Adapter1::Request()" << endl;
		adapte->SpecificRequest();
		cout << "----------------------------" << endl;
	}

	~Adapter1() {
		delete this->adapte;
		adapte = nullptr;
	}
private:
	Adaptee* adapte;
};

void test2() {
	Target* target = new Adapter1();
	target->Request();
	delete target;
}

#if 0
class MyBind {
public:
	void operator()(int v1, int v2) {
		cout << v1 + v2 << endl;
	}
};

class Adapter {
public:
	Adapter(int v) :pargram(v) {}
	void operator()(int v) {
		target(v, pargram);
	}
	MyBind target;
	int pargram;
};

Adapter MyBind2(int v) {
	return Adapter(v);
}

void test3() {
	vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);

	for_each(v.begin(), v.end(), MyBind2(20));
}
#endif


int main() {

	return 0;
}