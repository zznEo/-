#include <iostream>
#include <list>
using namespace std;

class AbstractHero {
public:
	virtual void Update() = 0;
};

class HeroA :public AbstractHero {
public:
	HeroA() { cout << "Ӣ��A���ڴ�Boss!" << endl; }
	virtual void Update() { cout << "Ӣ��Aֹͣ��Boss!" << endl; }
};

class HeroB :public AbstractHero {
public:
	HeroB() { cout << "Ӣ��B���ڴ�Boss!" << endl; }
	virtual void Update() { cout << "Ӣ��Bֹͣ��Boss!" << endl; }
};

class HeroC :public AbstractHero {
public:
	HeroC() { cout << "Ӣ��C���ڴ�Boss!" << endl; }
	virtual void Update() { cout << "Ӣ��Cֹͣ��Boss!" << endl; }
};

class HeroD :public AbstractHero {
public:
	HeroD() { cout << "Ӣ��D���ڴ�Boss!" << endl; }
	virtual void Update() { cout << "Ӣ��Dֹͣ��Boss!" << endl; }
};

class AbstractBoss {
public:
	virtual void AddHero(AbstractHero* hero) = 0;
	virtual void DelHero(AbstractHero* hero) = 0;
	virtual void Modify() = 0;
};

class BossA :public AbstractBoss {
public:
	virtual void AddHero(AbstractHero* hero) { mHero.push_back(hero); }
	virtual void DelHero(AbstractHero* hero) { mHero.remove(hero); }
	virtual void Modify() {
		for (auto it = mHero.begin(); it != mHero.end(); it++) {
			(*it)->Update();
		}
	}
	~BossA() {
		for (auto it = mHero.begin(); it != mHero.end(); it++) {
			delete (*it);
		}
	}
private:
	list<AbstractHero*> mHero;
};

void test1() {
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;

	AbstractBoss* bossA = new BossA;
	bossA->AddHero(heroA);
	bossA->AddHero(heroB);
	bossA->AddHero(heroC);
	bossA->AddHero(heroD);

	cout << "Ӣ��A ����!" << endl;
	bossA->DelHero(heroA);
	cout << "Boss������" << endl;
	bossA->Modify();
}

int main() {
	test1();
	return 0;
}
