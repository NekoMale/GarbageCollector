#include "Object.h"
#include "GarbageCollector.h"
#include "World.h"

int main(int argc, char** argv)
{
	UObject* Obj = new UObject();

	bool bIsAlive = GarbageCollector::Get().IsAlive(Obj);

	UWorld* World = new UWorld();
	Obj->SetParent(World);
	
	Obj->MarkForDestroy();

	GarbageCollector::Get().Collect();

	return 0;
}