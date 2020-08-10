#include <iostream>
#include <string>
using namespace std;


class AbstractConmmonInterface {
public:
	virtual void run() = 0;
};

class MySystem : public AbstractConmmonInterface {
public:
	virtual void run() {
		cout << "ϵͳ����" << endl;
	}
};

class MySystemProxy :public AbstractConmmonInterface {
public:
	MySystemProxy(string name, string password) {
		this->mUserName = name;
		this->mUserPassword = password;
		pSystem = new MySystem;
	}
	virtual void run() {
		if (CheckAuthority()) {
			cout << "�û�����������ȷ����֤ͨ��" << endl;
			pSystem->run();
		}
		else {
			cout << "�û��������������Ȩ�޲��㣡" << endl;
		}
	}
	~MySystemProxy() {
		if (pSystem != nullptr) {
			delete pSystem;
			pSystem = nullptr;
		}
	}
private:
	bool CheckAuthority() {
		if (mUserName == "admin" && mUserPassword == "admin")
			return true;
		return false;
	}


private:
	MySystem* pSystem;
	string mUserName;
	string mUserPassword;
};

void test1() {
	MySystemProxy* proxy = new MySystemProxy("root", "admin");
	proxy->run();
	delete proxy;

	proxy = new MySystem9Proxy("admin", "admin");
	proxy->run();
	delete proxy;
	proxy = nullptr;
}

/*Subject�࣬������RealSubject��Proxo�Ĺ��ýӿڣ����������κ�ʹ��RealSubject�ĵط�������ʹ��Proxy*/
class Subject {
public:
	virtual void Request() = 0;
};




int main() {
	test1();
	return 0;
}