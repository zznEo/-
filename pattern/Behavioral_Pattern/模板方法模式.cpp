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
	virtual void BuildWater() { cout << "��ˮ..." << endl; }
	virtual void Brew() { cout << "�󿧷�..." << endl; }
	virtual void PourInCup() { cout << "���뱭��..." << endl; }
	virtual void AddSonmething() { cout << "���Ǽ�ţ��..." << endl; }
};

class Tea :public DrinkTemplate {
private:
	virtual void BuildWater() { cout << "��ˮ..." << endl; }
	virtual void Brew() { cout << "�ݲ�..." << endl; }
	virtual void PourInCup() { cout << "���뱭��..." << endl; }
	virtual void AddSonmething() { cout << "ʲôҲ����..." << endl; }
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