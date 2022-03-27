#pragma once
#include <set>
#include <vector>
#include <functional>
#include "Object.h"
#include "Actor.h"

struct Ticker
{
	void* Context;
	std::function<void(void*, float)> TickFunction;
};

class UWorld : public UObject
{
public:
	std::set<Actor*> Actors;
	std::vector<Ticker> Tickers;

	virtual void Tick(float DeltaTime)
	{
		for (Ticker Ticker : Tickers)
		{
			Ticker.TickFunction(Ticker.Context, DeltaTime);
		}
	}
};