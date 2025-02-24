#pragma once
#include <iostream>

template<typename T>
class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	void Clear();


	T Get();

	//determines if something was released back to the pool or not
	bool Release();


	int getActiveCount();
	int getInactiveCount();

private:
	int m_count;

};

template<typename T>
inline ObjectPool<T>::ObjectPool()
{
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline void ObjectPool<T>::Clear()
{
}

template<typename T>
inline T ObjectPool<T>::Get()
{
	return T();
}

template<typename T>
inline bool ObjectPool<T>::Release()
{
	return false;
}

template<typename T>
inline int ObjectPool<T>::getActiveCount()
{
	return 0;
}

template<typename T>
inline int ObjectPool<T>::getInactiveCount()
{
	return 0;
}
