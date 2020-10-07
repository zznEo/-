#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Ŀ��ӿ��࣬�ͻ���Ҫ�Ľӿ�
class Target {
public:
	virtual void Request() {//�����׼�ӿ�
		cout << "Target::Request()" << endl;
	}
};

// ��Ҫ�������
class Adaptee {
public:
	void SpecificRequest() {
		cout << "Adaptee::SpecificRequest()" << endl;
	}
};

//��ģʽ���������࣬ͨ��public�̳л�ýӿڼ̳е�Ч����ͨ��private�̳л��ʵ�ּ̳е�Ч��
class Adapter :public Target, private Adaptee {  //ͨ�������������ͻ�����Ҫ���Ѿ������Ľӿڽ������䡣
public:
	virtual void Request() {	//ʵ��Target�����Request�ӿ�
		cout << "Adapter::Request()" << endl;
		this->SpecificRequest();
		cout << "----------------------------" << endl;
	}
};

void test1() {
	Target* target = new Adapter;
	target->Request();
}

//����ģʽ���������࣬�̳�Target�࣬������ϵķ�ʽʵ��Adaptee�ĸ���

class Adapter1 :public Target {
public:
	Adapter1() { this->adapte = new Adaptee; }
	Adapter1(Adaptee* adapte) { this->adapte = adapte; }

	virtual void Request() {	//ʵ��Target�����Request�ӿ�
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