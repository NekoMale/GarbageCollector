#pragma once
#include <set>
#include "Component.h"

class World;

class Actor
{
public:
	Actor();
	~Actor();

	std::set<Component> Components;

	void Register(UWorld* World);

	virtual void Tick(float DeltaTime)
	{

	}
};