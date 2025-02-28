#pragma once
#include <iostream>
#include "List.h"


template<typename T>
class ObjectPool
{
	typedef T(*CreateItemSignature)();

public:
	ObjectPool(int size, CreateItemSignature createItemFunction);
	~ObjectPool();

	//removes anything in both the active and inactive lists
	void Clear();

	//takes out of the inactive list and places into active list
	//returns the thing<T> that was just moved
	T Get();

	//determines if something was released back to the pool or not
	//opposite of Get(), moves from the active list to the inactive list
	//returns the thing<T> that was just moved
	//also checks if the thing<T> is already in the inactive list, and if it is, doesn't add it in again
	bool Release(T value);


	int getActiveCount();
	int getInactiveCount();

private:
	List<T> m_inactiveList;
	List<T> m_activeList;

	CreateItemSignature m_createItemFunction;
};

template<typename T>
inline ObjectPool<T>::ObjectPool(int size, CreateItemSignature createItemFunction)
{
	m_createItemFunction = createItemFunction;
     
	//check if int size is a valid number
	if (size <= 0)
		return;

	for (int i = 0; i < size; i++)
	{
		T item = createItemFunction();
		//then add the newly made item to the inactive list
		m_inactiveList.pushFront(item);
	}
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline void ObjectPool<T>::Clear()
{
	m_inactiveList.~List();
	m_activeList.~List();
}

template<typename T>
inline T ObjectPool<T>::Get()
{
	//if the object pool is empty, make a new item to put into the inactive list
	if (getInactiveCount() <= 0)
	{
	  T item = m_createItemFunction();
	  m_inactiveList.pushFront(item);
	}
	//if the pool is not empty, get an item from the inactive list and put it into the active list
	else
	{
		T item = m_inactiveList.begin();
		m_activeList.pushFront(item);
		m_inactiveList.popFront();
	}
	return item;
}

template<typename T>
inline bool ObjectPool<T>::Release(T value)
{
	if (m_inactiveList.find(value))
		break;
	else
	{
		T item = m_activeList.find(value);
		m_inactiveList.pushFront(item);
		m_activeList.remove(item);
	}
	return item;
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
