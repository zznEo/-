#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractCar {
public:
	virtual void run() = 0;
};

class Dazhong :public AbstractCar {
public:
	virtual void run() { cout << "大众启动..." << endl; }
};

class Tuolaji :public AbstractCar {
public:
	virtual void run() { cout << "拖拉机启动..." << endl; }
};

#if 0
class Person :public Dazhong {
public:
	void Doufeng() {
		run();
	}
};

class PersonB :public Tuolaji {
public:
	void Doufeng() {
		run();
	}
};
#endif

class Person {
public:
	void SetCar(AbstractCar* car) { this->car = car; }
	void Doufeng() { 
		car->run();
		delete car;
		car = nullptr;
	}
private:
	AbstractCar* car = nullptr;
};

void test1() {
	Person* p1 = new Person;
	p1->SetCar(new Dazhong);
	p1->Doufeng();

	p1->SetCar(new Tuolaji);
	p1->Doufeng();
	delete p1;
}

int main() {
	test1();
	return 0;
}#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractCar {
public:
	virtual void run() = 0;
};

class Dazhong :public AbstractCar {
public:
	virtual void run() { cout << "大众启动..." << endl; }
};

class Tuolaji :public AbstractCar {
public:
	virtual void run() { cout << "拖拉机启动..." << endl; }
};

#if 0
class Person :public Dazhong {
public:
	void Doufeng() {
		run();
	}
};

class PersonB :public Tuolaji {
public:
	void Doufeng() {
		run();
	}
};
#endif

class Person {
public:
	void SetCar(AbstractCar* car) { this->car = car; }
	void Doufeng() { 
		car->run();
		delete car;
		car = nullptr;
	}
private:
	AbstractCar* car = nullptr;
};

void test1() {
	Person* p1 = new Person;
	p1->SetCar(new Dazhong);
	p1->Doufeng();

	p1->SetCar(new Tuolaji);
	p1->Doufeng();
	delete p1;
}

int main() {
	test1();
	return 0;
}