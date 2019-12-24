#pragma once
#include <vector>

class animation
{
public:
	typedef vector<POINT>	vFrameList;	//������ �ε��� ����� ����
	typedef vector<int>		vPlayList;	//�÷��� �ε��� ����� ����

private:
	int			_frameNum;			//�ִϸ��̼� ������ ����

	vFrameList	_frameList;			//������ ����Ʈ
	vPlayList	_playList;			//�÷��� ����Ʈ

	int _frameWidth;				//������ ����ũ��
	int _frameHeight;				//������ ����ũ��

	BOOL _loop;						//�ִϸ��̼� ���� ����

	float _frameUpdateSec;			//������ ����ð�
	float _elapsedSec;				//��Ÿ Ÿ��

	DWORD _nowPlayIndex;			//���� �÷��� �ε���
	BOOL _play;						//�ִϸ��̼� �������

public:
	animation();
	~animation();

	//�ִϸ��̼� init(�̹��� ��ü ����ũ��, ����ũ��, ������ ����ũ��, ����ũ�� )
	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release();

	//����Ʈ �ִϸ��̼�
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);

	//�迭�� ��� �ִϸ��̼� ���
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);

	//���� �ִϸ��̼� ���
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	//�ִϸ��̼� ������ ����ӵ� ����
	void setFPS(int framePerSec);

	//������
	void frameUpdate(float elapsedTime);

	void start();
	void stop();
	void pause();
	void resume();

	inline BOOL isPlay() { return _play; }
	inline POINT getFramePos() { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth() { return _frameWidth; }
	inline int getFrameHeight() { return _frameHeight; }
};

