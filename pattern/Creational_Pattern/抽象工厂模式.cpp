#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractApple {
public:
	virtual void ShowName() = 0;
};

class ChinaApple :public AbstractApple {
public:
	virtual void ShowName() { cout << "中国苹果！" << endl; }
};

class UsaApple :public AbstractApple {
public:
	virtual void ShowName() { cout << "美国苹果！" << endl; }
};

class JanpanApple :public AbstractApple {
public:
	virtual void ShowName() { cout << "日本苹果" << endl; }
};

class AbstractBanana {
public:
	virtual void ShowName() = 0;
};

class ChinaBanana :public AbstractBanana {
public:
	virtual void ShowName() { cout << "中国香蕉！" << endl; }
};

class UsaBanana :public AbstractBanana {
public:
	virtual void ShowName() { cout << "美国香蕉！" << endl; }
};

class JanpanBanana :public AbstractBanana {
public:
	virtual void ShowName() { cout << "日本香蕉！" << endl; }
};

class AbstractPear {
public:
	virtual void ShowName() = 0;
};

class ChinaPear :public AbstractPear {
public:
	virtual void ShowName() { cout << "中国鸭梨！" << endl; }
};

class UsaPear :public AbstractPear {
public:
	virtual void ShowName() { cout << "美国鸭梨！" << endl; }
};

class JanpanPear :public AbstractPear {
public:
	virtual void ShowName() { cout << "日本鸭梨！" << endl; }
};

class AbstractFactory {
public:
	virtual AbstractApple* CreateFruitApple() = 0;
	virtual AbstractBanana* CreateFruitBanana() = 0;
	virtual AbstractPear* CreateFruitPear() = 0;
};

class ChinaFactory :public AbstractFactory {
public:
	virtual AbstractApple* CreateFruitApple() { return new ChinaApple; }
	virtual AbstractBanana* CreateFruitBanana() { return new ChinaBanana; }
	virtual AbstractPear* CreateFruitPear() { return new ChinaPear; }
};

class UsaFactory :public AbstractFactory {
public:
	virtual AbstractApple* CreateFruitApple() { return new UsaApple; }
	virtual AbstractBanana* CreateFruitBanana() { return new UsaBanana; }
	virtual AbstractPear* CreateFruitPear() { return new UsaPear; }
};

class JanpanFactory :public AbstractFactory {
public:
	virtual AbstractApple* CreateFruitApple() { return new JanpanApple; }
	virtual AbstractBanana* CreateFruitBanana() { return new JanpanBanana; }
	virtual AbstractPear* CreateFruitPear() { return new JanpanPear; }
};

void test1() {
	AbstractApple* apple = nullptr;
	AbstractBanana* banana = nullptr;
	AbstractPear* pear = nullptr;
	AbstractFactory* factory = nullptr;
//
	factory = new ChinaFactory;
	apple = factory->CreateFruitApple();
	apple->ShowName();
	banana = factory->CreateFruitBanana();
	banana->ShowName();
	pear = factory->CreateFruitPear();
	pear->ShowName();

	delete factory;
	delete apple;
	delete banana;
	delete pear;

	factory = nullptr;
	apple = nullptr;
	banana = nullptr;
	pear = nullptr;
}
int main() {
	test1();
	return 0;
}