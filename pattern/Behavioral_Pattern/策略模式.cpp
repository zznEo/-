#include  <iostream>
using namespace std;

class WeaponStrategy {
public:
	virtual void UseWeapon() = 0;
};

class Knife :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "ʹ��С����" << endl;
	}
};

class Pistol :public WeaponStrategy {
public:
	virtual void UseWeapon() {
		cout << "ʹ����ǹ��" << endl;
	}
};

class Person {
public:
	void setWeapon(WeaponStrategy* weapon) {
		this->pWeapon = weapon;
	}
	void Go() {
		this->pWeapon->UseWeapon();
	}
	~Person() {
		delete pWeapon;
		pWeapon = nullptr;
	}
private:
	WeaponStrategy* pWeapon;
};

int main() {
	Person *p1 = new Person;
	p1->setWeapon(new Knife);
	p1->Go();
	delete p1;
	p1 = nullptr;
	return 0;
}