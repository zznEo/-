#include <iostream>
using namespace std;

class AbstractHero {
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mAr;
};

class Hero :public AbstractHero {
public:
	Hero() {
		mHp = 0;
		mMp = 0;
		mAt = 0;
		mAr = 0;
	}
	virtual void ShowStatus() {
		cout << "血量：" << mHp << endl;
		cout << "蓝量：" << mMp << endl;
		cout << "攻击力：" << mAt << endl;
		cout << "护甲：" << mAr << endl;
	}
};
//英雄穿上了某件装备，还是一个英雄
class AbstractEquipment :public AbstractHero {
public:
	AbstractEquipment(AbstractHero* hero) { this->pHero = hero; }
	virtual void ShowStatus() {}
protected:
	AbstractHero* pHero;
};

class KuangtuEquipment :public AbstractEquipment {
public:
	KuangtuEquipment(AbstractHero* hero) :AbstractEquipment(hero) {}
	void AddKuangtu() {
		this->mHp = this->pHero->mHp + 1000;
		this->mMp = this->pHero->mMp;
		this->mAr = this->pHero->mAr;
		this->mAt = this->pHero->mAt;
	}
	virtual void ShowStatus() {
		AddKuangtu();
		cout << "血量：" << this->mHp << endl;
		cout << "蓝量：" << this->mMp << endl;
		cout << "攻击力：" << this->mAt << endl;
		cout << "护甲：" << this->mAr << endl;

		delete this->pHero;
	}
};

class WujinEquipment :public AbstractEquipment {
public:
	WujinEquipment(AbstractHero* hero) :AbstractEquipment(hero) {}
	void AddWujin() {
		this->mHp = pHero->mHp;
		this->mMp = pHero->mMp;
		this->mAr = pHero->mAr;
		this->mAt = pHero->mAt + 80;
	}

	virtual void ShowStatus() {
		AddWujin();
		cout << "血量：" << this->mHp << endl;
		cout << "蓝量：" << this->mMp << endl;
		cout << "攻击力：" << this->mAt << endl;
		cout << "护甲：" << this->mAr << endl;
		delete this->pHero;
	}
};

void test1() {
	AbstractHero* hero = new Hero;
	cout << "初始英雄，没有装备" << endl;
	hero->ShowStatus();

	cout << "英雄穿上狂徒之后" << endl;
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();

	cout << "英雄穿上无尽之后" << endl;
	hero = new WujinEquipment(hero);
	hero->ShowStatus();

	delete hero;
}

int main() {
	test1();
	return 0;
}