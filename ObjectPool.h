#pragma once
#include<queue>
#include<vector>
#include"Object.h"

class ObjectPool
{
	priority_queue<Object*> pool;
	//queue<Object*> pool;
	vector<Object*> ActivePool;
public:
	ObjectPool();
	~ObjectPool();
	void InssertPool(int num);
	void InssertActiveObject();

	inline Object* GetPoolObject() { return pool.top(); }
	inline Object* GetActivePoolObject(int num) { return ActivePool[num]; }
	inline int GetPoolSize() { return pool.size(); }
	inline int GetActivePoolSize() { return ActivePool.size(); }

	template<typename T>
	void Init(int size,Object obj);
};
#include"ObjectPool.hpp"
