#pragma once
#include <set>
#include "Reflection.h"

class UObject
{
private:
	bool bMarkedForDestroy;
	UObject* Parent;
	std::set<UObject*> Children;

public:
	UObject();

	~UObject();

	static Reflection Reflection;
	int Dummy_01;
	int Dummy_02;

	void SetParent(UObject* Parent);

	bool IsMarkedForDestroy() const
	{
		return bMarkedForDestroy;
	}

	void MarkForDestroy()
	{
		if (!bMarkedForDestroy)
		{
			bMarkedForDestroy = true;
			for (UObject* Child : Children)
			{
				Child->MarkForDestroy();
			}

			if (Parent != nullptr)
			{
				if (!Parent->IsMarkedForDestroy())
				{
					Parent->Children.erase(this);
				}
			}
		}
	}
};