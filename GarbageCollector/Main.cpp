#include "Object.h"
#include "GarbageCollector.h"
#include "World.h"

int main(int argc, char** argv)
{
	UObject::Reflection = Reflection();
	UObject::Reflection.Properties["Dummy_01"] = Property(offsetof(UObject, Dummy_01), sizeof(int));
	UObject::Reflection.Properties["Dummy_02"] = Property(offsetof(UObject, Dummy_02), sizeof(int));

	UObject* Obj = new UObject();
	Obj->Dummy_01 = 7;
	Obj->Dummy_02 = 14;

	bool bIsAlive = GarbageCollector::Get().IsAlive(Obj);

	UWorld* World = new UWorld();
	Obj->SetParent(World);
	
	Obj->MarkForDestroy();

	GarbageCollector::Get().Collect();

	return 0;
}