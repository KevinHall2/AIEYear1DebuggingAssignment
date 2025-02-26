#pragma once
#include <iostream>
#include "List.h"


template<typename T>
class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	//removes anything in both the active and inactive lists
	void Clear();

	//takes out of the inactive list and places into active list
	//returns the thing<T> that was just moved
	T Get();

	//determines if something was released back to the pool or not
	//opposite of Get(), moves from the active list to the inactive list
	//returns the thing<T> that was just moved
	//also checks if something is already in the inactive list, and if it is, doesn't add it in again
	bool Release(T value);


	int getActiveCount();
	int getInactiveCount();

private:
	List<T> m_inactiveList;
	List<T> m_activeList;

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
inline bool ObjectPool<T>::Release(T value)
{
	return false;
}

template<typename T>
inline int ObjectPool<T>::getActiveCount()
{
	//returns the length of the active list
	return m_activeList.getLength();
}

template<typename T>
inline int ObjectPool<T>::getInactiveCount()
{
	//returns the length of the inactive list
	return m_inactiveList.getLength();
}
