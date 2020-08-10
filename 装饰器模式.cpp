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
		cout << "Ѫ����" << mHp << endl;
		cout << "������" << mMp << endl;
		cout << "��������" << mAt << endl;
		cout << "���ף�" << mAr << endl;
	}
};
//Ӣ�۴�����ĳ��װ��������һ��Ӣ��
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
		cout << "Ѫ����" << this->mHp << endl;
		cout << "������" << this->mMp << endl;
		cout << "��������" << this->mAt << endl;
		cout << "���ף�" << this->mAr << endl;

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
		cout << "Ѫ����" << this->mHp << endl;
		cout << "������" << this->mMp << endl;
		cout << "��������" << this->mAt << endl;
		cout << "���ף�" << this->mAr << endl;
		delete this->pHero;
	}
};

void test1() {
	AbstractHero* hero = new Hero;
	cout << "��ʼӢ�ۣ�û��װ��" << endl;
	hero->ShowStatus();

	cout << "Ӣ�۴��Ͽ�ͽ֮��" << endl;
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();

	cout << "Ӣ�۴����޾�֮��" << endl;
	hero = new WujinEquipment(hero);
	hero->ShowStatus();

	delete hero;
}

int main() {
	test1();
	return 0;
}