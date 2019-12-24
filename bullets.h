#pragma once
#include "gameNode.h"
#include <vector>

//FULL-OOP (완전객체지향) 플랫폼에서는 구조체가 불편하다
//OOP && Half-OOP 플랫폼에서는 구조체가 편할때도 있다

//총알구조체
struct tagBullet
{
	image* bulletImage;		//총알 이미지
	RECT rc;				//총알 렉트
	float x, y;				//총알 위치 x,y
	float angle;			//총알 각도
	float radius;			//총알 붼지름
	float speed;			//총알 스피드
	float fireX, fireY;		//총알의 첫 발사위치
	bool isFire;			//발사했누?
	int count;
};

//누구나 다 가져다 쓸 수 있는 총알
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

	// 총알발사함수  나갈 좌표X,Y 각도, 속도
	void bulletFire(float x, float y, float angle, float speed);

	void bulletMove();

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getViBullet() { return _viBullet; }

};


//생성해두고 발사하는 미쏴일
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;		//사거리 변수
public:
	missile() {};
	~missile() {};

	//미사일 초기화함수(최대 몇발, 사거리)
	HRESULT init(int bulletMax, float range);
	void release();
	void update();
	void render();
	
	//총알 발사함수
	void fire(float x, float y);
	void move();	//긴말하지 않겠다...
};

//발사할때 생성해서 쏘는 미쏴일
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