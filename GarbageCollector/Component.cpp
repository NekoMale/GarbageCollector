#include "Component.h"
#include "World.h"

void Component::Register(UWorld* World)
{
	Ticker Ticker;
	Ticker.Context = this;
	Ticker.TickFunction = &Component::TickComponent;

	World->Tickers.push_back(Ticker);
}