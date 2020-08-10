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
		cout << "系统启动" << endl;
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
			cout << "用户名和密码正确，验证通过" << endl;
			pSystem->run();
		}
		else {
			cout << "用户名或者密码错误，权限不足！" << endl;
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

/*Subject类，定义了RealSubject和Proxo的共用接口，这样就在任何使用RealSubject的地方都可以使用Proxy*/
class Subject {
public:
	virtual void Request() = 0;
};




int main() {
	test1();
	return 0;
}