#include "Object.h"
#include "GarbageCollector.h"
#include <iostream>

UObject::UObject() : bMarkedForDestroy(false), Parent(nullptr)
{
	GarbageCollector::Get().AddUObject(this);
}

UObject::~UObject()
{
	std::cout << "Object Destroyed " << std::hex << this << std::dec << std::endl;
}

void UObject::SetParent(UObject* InParent)
{
	if (Parent != nullptr)
	{
		abort();
	}
	Parent = InParent;
	Parent->Children.insert(this);
}