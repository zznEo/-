#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
//银行工作人员类
class BankWorker {
public:
	void SaveService() { cout << "办理存款业务..." << endl; }
	void PayService() { cout << "办理支付业务..." << endl; }
	void TranferService() { cout << "办理转账业务..." << endl; }
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
	virtual void doWork() { cout << "办理存款业务..." << endl; }
};

class PayWorker :public AbstractBankWorker {
public:
	virtual void doWork() { cout << "办理支付业务..." << endl; }
};

class TranferWorker :public AbstractBankWorker {
public:
	virtual void doWork() { cout << "办理转账业务..." << endl; }
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