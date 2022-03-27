#include "Actor.h"
#include "World.h"

void Actor::Register(UWorld* World)
{
	Ticker Ticker;
	Ticker.Context = this;
	Ticker.TickFunction = &Actor::Tick;

	World->Tickers.push_back(Ticker);
}