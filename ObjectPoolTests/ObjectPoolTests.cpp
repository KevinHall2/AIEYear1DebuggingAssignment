#include "pch.h"
#include "CppUnitTest.h"
#include "../CDDS_Optimise/ObjectPool.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ObjectPoolTests
{
		int makeInt()
		{
			int item = 0;
			return item;
		}
	TEST_CLASS(ObjectPoolTests)
	{
	public:
		
		TEST_METHOD(ObjectPoolConstructor)
		{
			ObjectPool<int> objectPool = ObjectPool<int>(100, makeInt );
			Assert::AreEqual(100, objectPool.getInactiveCount());
			Assert::AreEqual(0, objectPool.getActiveCount());
		}

		TEST_METHOD(Get)
		{
			ObjectPool<int> objectPool = ObjectPool<int>(100, makeInt);
			objectPool.Get();
			Assert::AreEqual(99, objectPool.getInactiveCount());
			Assert::AreEqual(1, objectPool.getActiveCount());
		}

		TEST_METHOD(Release)
		{
			ObjectPool<int> objectPool = ObjectPool<int>(100, makeInt);
			objectPool.Get();
			objectPool.Release(55);
			Assert::AreEqual(100, objectPool.getInactiveCount());
			Assert::AreEqual(0, objectPool.getActiveCount());
		}

		TEST_METHOD(Clear)
		{
			ObjectPool<int> objectPool = ObjectPool<int>(100, makeInt);
			objectPool.Get();
			objectPool.Get();
			objectPool.Get();
			objectPool.Release(5);
			objectPool.Release(6);
			objectPool.Release(7);
			objectPool.Clear();
			Assert::AreEqual(0, objectPool.getInactiveCount());
			Assert::AreEqual(0, objectPool.getActiveCount());
		}

		
	};
}
