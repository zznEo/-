#include <iostream>
#include <vector>
#include <string>
using namespace std;
class AbstractFruit {
public:
	virtual void ShowName() = 0;
};

class Apple :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "I'am Apple" << endl;
	}
};

class Banana :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "I'am Banana" << endl;
	}
};

class Pear :public AbstractFruit {
public:
	virtual void ShowName() {
		cout << "I'am Pear" << endl;
	}
};

class AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

class AppleFactory :public AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() { return new Apple; }
};

class BananaFactory :public AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() { return new Banana; }
};

class PearFactory :public AbstractFactory {
public:
	virtual AbstractFruit* CreateFruit() { return new Pear; }
};

void test1() {
	AbstractFactory* factory = new AppleFactory;
	AbstractFruit* fruit = factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;

	factory = new BananaFactory;
	fruit =  factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;

	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete factory;
	delete fruit;
	factory = nullptr;
	fruit = nullptr;
}

int main() {
	test1();
	return 0;
}