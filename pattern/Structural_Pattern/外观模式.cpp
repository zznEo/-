#include <iostream>
using namespace std;

class Television {
public:
	void On() { cout << "���ӻ�����" << endl; }
	void Off() { cout << "���ӻ��رգ�" << endl; }
};

class Light {
public:
	void On() { cout << "�ƿ���" << endl; }
	void Off() { cout << "�ƹرգ�" << endl; }
};

class Audio {
public:
	void On() { cout << "���쿪��" << endl; }
	void Off() { cout << "����رգ�" << endl; }
};

class Microphone {
public:
	void On() { cout << "��˷翪��" << endl; }
	void Off() { cout << "��˷�رգ�" << endl; }
};

class DVDPlayer {
public:
	void On() { cout << "DVD����������" << endl; }
	void Off() { cout << "DVD�������رգ�" << endl; }
};

class Gamemachine {
public:
	void On() { cout << "��Ϸ������" << endl; }
	void Off() { cout << "��Ϸ���رգ�" << endl; }
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