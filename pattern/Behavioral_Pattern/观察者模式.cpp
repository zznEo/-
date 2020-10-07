#include <iostream>
#include <list>
using namespace std;

class AbstractHero {
public:
	virtual void Update() = 0;
};

class HeroA :public AbstractHero {
public:
	HeroA() { cout << "Ó¢ÐÛAÕýÔÚ´òBoss!" << endl; }
	virtual void Update() { cout << "Ó¢ÐÛAÍ£Ö¹´òBoss!" << endl; }
};

class HeroB :public AbstractHero {
public:
	HeroB() { cout << "Ó¢ÐÛBÕýÔÚ´òBoss!" << endl; }
	virtual void Update() { cout << "Ó¢ÐÛBÍ£Ö¹´òBoss!" << endl; }
};

class HeroC :public AbstractHero {
public:
	HeroC() { cout << "Ó¢ÐÛCÕýÔÚ´òBoss!" << endl; }
	virtual void Update() { cout << "Ó¢ÐÛCÍ£Ö¹´òBoss!" << endl; }
};

class HeroD :public AbstractHero {
public:
	HeroD() { cout << "Ó¢ÐÛDÕýÔÚ´òBoss!" << endl; }
	virtual void Update() { cout << "Ó¢ÐÛDÍ£Ö¹´òBoss!" << endl; }
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

	cout << "Ó¢ÐÛA ÕóÍö!" << endl;
	bossA->DelHero(heroA);
	cout << "BossËÀÍö£¡" << endl;
	bossA->Modify();
}

int main() {
	test1();
	return 0;
}
