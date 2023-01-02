#pragma once
#include "DrawDebugHelpers.h"

#define RADIUS 25.f
#define SEGMENTS 24
#define LIFETIME 30.f

class DebugUtils
{
public:
	static void debugSphere(FVector actorLocation, UWorld* World)
	{
		if (World != nullptr)
		{
			DrawDebugSphere(World, actorLocation,RADIUS,SEGMENTS, FColor::Red, false,LIFETIME);
		}
	}

	static void debugLine(FVector actorLocation, FVector actorForwardVector, UWorld* World)
	{
		if (World != nullptr)
		{
			DrawDebugLine(World, actorLocation, actorForwardVector, FColor::Blue, false,LIFETIME);
		}
	}
};
