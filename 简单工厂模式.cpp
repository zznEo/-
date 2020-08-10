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

class FruitFactory {
public:
	static AbstractFruit* CreateFruit(string op) {
		if (op == "apple")
			return new Apple;
		else if (op == "banana")
			return new Banana;
		else
			return new Pear;
	}
};

void test1() {
	FruitFactory* factory = new FruitFactory;
	AbstractFruit *fruit = factory->CreateFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = factory->CreateFruit("pear");
	fruit->ShowName();
	delete fruit;
	fruit = nullptr;

	delete factory;
	factory = nullptr;
}

int main() {
	test1();
	return 0;
}