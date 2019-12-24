#pragma once
#include "gameNode.h"
#include <vector>

//FULL-OOP (������ü����) �÷��������� ����ü�� �����ϴ�
//OOP && Half-OOP �÷��������� ����ü�� ���Ҷ��� �ִ�

//�Ѿ˱���ü
struct tagBullet
{
	image* bulletImage;		//�Ѿ� �̹���
	RECT rc;				//�Ѿ� ��Ʈ
	float x, y;				//�Ѿ� ��ġ x,y
	float angle;			//�Ѿ� ����
	float radius;			//�Ѿ� ������
	float speed;			//�Ѿ� ���ǵ�
	float fireX, fireY;		//�Ѿ��� ù �߻���ġ
	bool isFire;			//�߻��ߴ�?
	int count;
};

//������ �� ������ �� �� �ִ� �Ѿ�
class bullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;
public:
	bullet() {};
	~bullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	// �Ѿ˹߻��Լ�  ���� ��ǥX,Y ����, �ӵ�
	void bulletFire(float x, float y, float angle, float speed);

	void bulletMove();

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }

};


//�����صΰ� �߻��ϴ� �̽���
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;		//��Ÿ� ����
public:
	missile() {};
	~missile() {};

	//�̻��� �ʱ�ȭ�Լ�(�ִ� ���, ��Ÿ�)
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();
	
	//�Ѿ� �߻��Լ�
	void fire(float x, float y);
	void move();	//�主���� �ʰڴ�...
};

//�߻��Ҷ� �����ؼ� ��� �̽���
class littleBoy : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _missileMax;

public:
	littleBoy() {};
	~littleBoy() {};

	virtual HRESULT init(int missileMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	void fire(float x, float y);

	void move();

	void removeBoy(int arrNum);

	vector<tagBullet> getVBoy() { return _vBullet; }
	vector<tagBullet>::iterator getViBoy() { return _viBullet; }
};