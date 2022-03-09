#pragma once
#include "Object.h"
#include <unordered_set>
#include <vector>
#include <assert.h>

class GarbageCollector
{
private:
	std::unordered_set<UObject*> ExistingObjects;

public:
	static GarbageCollector& Get()
	{
		static GarbageCollector* gc = nullptr;
		if (gc == nullptr)
		{
			gc = new GarbageCollector();
		}
		return *gc;
	}

	void AddUObject(UObject* ObjectToAdd)
	{
		ExistingObjects.insert(ObjectToAdd);
	}

	void Collect()
	{
		std::vector<UObject*> DyingObjects;
		for (UObject* Obj : ExistingObjects)
		{
			if (Obj->IsMarkedForDestroy())
			{
				DyingObjects.push_back(Obj);
			}
		}
		for (UObject* DyingObj : DyingObjects)
		{
			ExistingObjects.erase(DyingObj);
			delete DyingObj;
		}
	}

	bool IsAlive(UObject* ObjectToCheck)
	{
		if (ExistingObjects.find(ObjectToCheck) == ExistingObjects.end())
		{
			abort();
		}
		return !ObjectToCheck->IsMarkedForDestroy();
	}
};