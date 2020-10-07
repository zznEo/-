#include <iostream>
using namespace std;

class AbstractCalculator {
public:
	virtual int GetResult() = 0;
	virtual void SetOperatorNumber(int x, int y) = 0;
};

class PlusCalculator:public AbstractCalculator {
public:
	PlusCalculator() = default;
	PlusCalculator(int x, int y):a(x), b(y){}
	virtual int GetResult () {
		return a + b;
	}
	virtual void SetOperatorNumber(int x, int y) {
		a = x;
		b = y;
	}
private:
	int a;
	int b;
};

class MinuteCalculator :public AbstractCalculator {
public:
	MinuteCalculator() = default;
	MinuteCalculator(int x, int y) :a(x), b(y) {}
	virtual void SetOperatorNumber(int x, int y){
		a = x;
		b = y;
	}
	virtual int GetResult() {
		return a - b;
	}
private:
	int a;
	int b;
};

class MultCalculator :public AbstractCalculator {
public:
	virtual void SetOperatorNumber(int x, int y) {
		a = x;
		b = y;
	}
	virtual int GetResult() {
		return a * b;
	}
private:
	int a;
	int b;
};

void test01() {
	AbstractCalculator *caculator = new PlusCalculator;
	caculator->SetOperatorNumber(10, 20);
	cout << caculator->GetResult() << endl;
}

int main() {
	test01();
	return 0;
}