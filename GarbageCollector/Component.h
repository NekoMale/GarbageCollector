#pragma once

class World;

class Component
{
	Component();
	~Component();

	void Register(UWorld* World);

	virtual void TickComponent(float DeltaTime)
	{

	}
};