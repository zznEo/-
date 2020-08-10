#include <iostream>
using namespace std;

class Television {
public:
	void On() { cout << "电视机开启" << endl; }
	void Off() { cout << "电视机关闭！" << endl; }
};

class Light {
public:
	void On() { cout << "灯开启" << endl; }
	void Off() { cout << "灯关闭！" << endl; }
};

class Audio {
public:
	void On() { cout << "音响开启" << endl; }
	void Off() { cout << "音响关闭！" << endl; }
};

class Microphone {
public:
	void On() { cout << "麦克风开启" << endl; }
	void Off() { cout << "麦克风关闭！" << endl; }
};

class DVDPlayer {
public:
	void On() { cout << "DVD播放器开启" << endl; }
	void Off() { cout << "DVD播放器关闭！" << endl; }
};

class Gamemachine {
public:
	void On() { cout << "游戏机开启" << endl; }
	void Off() { cout << "游戏机关闭！" << endl; }
};

class KTVMode {
public:
	KTVMode() {
		pTv = new Television;
		light = new Light;
		audio = new Audio;
		microphone = new Microphone;
		dvd = new DVDPlayer;
	}

	void OnKTV() {
		pTv->On();
		light->Off();
		audio->On();
		microphone->On();
		dvd->On();
	}

	void OffKTV() {
		pTv->Off();
		light->On();
		audio->Off();
		microphone->Off();
		dvd->Off();
	}

	~KTVMode() {
		delete pTv;
		delete light;
		delete audio;
		delete microphone;
		delete dvd;

		pTv = nullptr;
		light = nullptr;
		audio = nullptr;
		microphone = nullptr;
		dvd = nullptr;
	}

private:
	Television* pTv;
	Light* light;
	Audio* audio;
	Microphone* microphone;
	DVDPlayer* dvd;
};

void test1() {
	KTVMode* ktv = new KTVMode;
	ktv->OnKTV();
	delete ktv;
	ktv = nullptr;
}
int main() {
	test1();
	return 0;
}