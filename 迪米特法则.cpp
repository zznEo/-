#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractBuiliding {
public:
	virtual void sale() = 0;
	virtual string& getQulity() = 0;
};

class BuildingA :public AbstractBuiliding {
public:
	BuildingA() { mQulity = "��Ʒ��"; }
	virtual void sale() { cout << "¥��A" << mQulity << "��������" << endl; }
	virtual string& getQulity() { return mQulity; }
protected:
	string mQulity;
};

class BuildingB :public AbstractBuiliding {
public:
	BuildingB() { mQulity = "��Ʒ��"; }
	virtual void sale() { cout << "¥��B" << mQulity << "��������" << endl; }
	virtual string& getQulity() { return mQulity; }
protected:
	string mQulity;
};

class Mediator {
public:
	Mediator() {
		AbstractBuiliding* building = new BuildingA;
		vBuilding.push_back(building);
		building = new BuildingB;
		vBuilding.push_back(building);
	}

	AbstractBuiliding* findBuilding(string quality) {
		for (auto it = vBuilding.begin(); it != vBuilding.end(); it++) {
			if ((*it)->getQulity() == quality) {
				return *it;
			}
		}
		return nullptr;
	}

	~Mediator() {
		for (auto it = vBuilding.begin(); it != vBuilding.end(); it++) {
			if (*it) {
				delete* it;
				*it = nullptr;
			}
		}
	}
protected:
	vector<AbstractBuiliding*> vBuilding;
};

void test01() {
	Mediator* mediator = new Mediator;
	AbstractBuiliding* building = mediator->findBuilding("��Ʒ��");
	if (building) {
		building->sale();
	}
	else {
		cout << "û�к��ʵ�¥��" << endl;
	}
}

int main() {
	test01();
	return 0;
}