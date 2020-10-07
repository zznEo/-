#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//���й�����Ա��
class BankWorker {
public:
	void SaveService() { cout << "������ҵ��..." << endl; }
	void PayService() { cout << "����֧��ҵ��..." << endl; }
	void TranferService() { cout << "����ת��ҵ��..." << endl; }
};

//
void DoSave(BankWorker* worker) { worker->SaveService(); }
void DoPay(BankWorker* worker) { worker->PayService(); }
void DoTranfer(BankWorker* worker) { worker->TranferService(); }

void test1() {
	BankWorker* worker = new BankWorker;
	DoSave(worker);
	delete worker;
}
#endif

class AbstractBankWorker {
public:
	virtual void doWork() = 0;
};

class SaveWorker :public AbstractBankWorker {
public:
	virtual void doWork() { cout << "������ҵ��..." << endl; }
};

class PayWorker :public AbstractBankWorker {
public:
	virtual void doWork() { cout << "����֧��ҵ��..." << endl; }
};

class TranferWorker :public AbstractBankWorker {
public:
	virtual void doWork() { cout << "����ת��ҵ��..." << endl; }
};

void doBusiness(AbstractBankWorker* worker) {
	worker->doWork();
}

void test2() {
	AbstractBankWorker* worker = new TranferWorker;
	doBusiness(worker);
	delete worker;
	worker = nullptr;
}

int main() {
	//test1();
	test2();
	return 0;
}