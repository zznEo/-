#include <iostream>
#include <queue>
#include <Windows.h>
using namespace std;

class HandleClientProtocol {
public:
	void AddMoney() { cout << "给玩家增加金币！" << endl; }
	void AddDiamond() { cout << "给玩家增加钻石！" << endl; }
	void AddEipment() { cout << "给玩家增加装备！" << endl; }
	void AddLevel() { cout << "给玩家升级！" << endl; }
};

class AbstractCommand {
public:
	virtual void handle() = 0;
};

class AddMoneyCommand :public AbstractCommand {
public:
	AddMoneyCommand(HandleClientProtocol* protocol) :pProtocol(protocol) {}
	virtual void handle() { pProtocol->AddMoney(); }
private:
	HandleClientProtocol* pProtocol;
};

class AddDiamondCommand :public AbstractCommand {
public:
	AddDiamondCommand(HandleClientProtocol* protocol) :pProtocol(protocol) {}
	virtual void handle() { pProtocol->AddDiamond(); }
private:
	HandleClientProtocol* pProtocol;
};

class AddEipmentCommand :public AbstractCommand {
public:
	AddEipmentCommand(HandleClientProtocol* protocol) :pProtocol(protocol) {}
	virtual void handle() { pProtocol->AddEipment(); }
private:
	HandleClientProtocol* pProtocol;
};

class AddLevelCommand :public AbstractCommand {
public:
	AddLevelCommand(HandleClientProtocol* protocol) :pProtocol(protocol) {}
	virtual void handle() { pProtocol->AddLevel(); }
private:
	HandleClientProtocol* pProtocol;
};

class Server {
public:
	void addRequest(AbstractCommand* command) { mCommands.push(command); }
	void StartHandle() {
		while (!mCommands.empty()) {
			AbstractCommand* nowCommand = mCommands.front();
			mCommands.pop();
			nowCommand->handle();
			delete nowCommand;
			nowCommand = nullptr;
			Sleep(2000);
		}
	}
	~Server() {
		while (!mCommands.empty()) {
			AbstractCommand* nowCommand = mCommands.front();
			mCommands.pop();
			delete nowCommand;
			nowCommand = nullptr;
		}
	}
private:
	queue<AbstractCommand*> mCommands;
};

void test1() {
	Server* server = new Server;
	HandleClientProtocol* protocol = new HandleClientProtocol;
	AbstractCommand *addMoney = new AddMoneyCommand(protocol);
	AbstractCommand* addDiamond = new AddDiamondCommand(protocol);
	AbstractCommand* addeipment = new AddEipmentCommand(protocol);
	AbstractCommand* addlevel = new AddLevelCommand(protocol);

	server->addRequest(addMoney);
	server->addRequest(addDiamond);
	server->addRequest(addeipment);
	server->addRequest(addlevel);

	server->StartHandle();
}

int main() {
	test1();
	return 0;
}