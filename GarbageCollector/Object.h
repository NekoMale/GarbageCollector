#pragma once
#include <set>

class UObject
{
private:
	bool bMarkedForDestroy;
	UObject* Parent;
	std::set<UObject*> Children;

public:
	UObject();

	~UObject();

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