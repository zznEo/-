#include <iostream>
using namespace std;

class DrinkTemplate {
protected:
	virtual void BuildWater() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void AddSonmething() = 0;
public:
	void Make() {
		BuildWater();
		Brew();
		PourInCup();
		AddSonmething();
	}
};

class Coffee :public DrinkTemplate {
private:
	virtual void BuildWater() { cout << "烧水..." << endl; }
	virtual void Brew() { cout << "煮咖啡..." << endl; }
	virtual void PourInCup() { cout << "倒入杯中..." << endl; }
	virtual void AddSonmething() { cout << "加糖加牛奶..." << endl; }
};

class Tea :public DrinkTemplate {
private:
	virtual void BuildWater() { cout << "烧水..." << endl; }
	virtual void Brew() { cout << "泡茶..." << endl; }
	virtual void PourInCup() { cout << "倒入杯中..." << endl; }
	virtual void AddSonmething() { cout << "什么也不加..." << endl; }
};

int main() {
	DrinkTemplate* drink = new Coffee;
	drink->Make();
	delete drink;

	drink = new Tea;
	drink->Make();
	drink = nullptr;
	return 0;
}