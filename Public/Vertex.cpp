/**
* AR Navigation
*
* Copyright 2020 Denis Esie
**/

#include "Vertex.h"

AVertex::AVertex()
{
	PrimaryActorTick.bCanEverTick = false;
	drawDebugVisualization = false;
	debugVisualizationScale = 1.0f;
}

void AVertex::BeginPlay()
{
	Super::BeginPlay();
	this->getAllConnectedVerticles();
	this->reset();
}

void AVertex::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AVertex::buildNavigationPath(const FString searchTag)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Building path to %s"), *searchTag));
	vertexWorldLocation = GetActorLocation();
	shortestLength = 0.0;
	this->searchFor(searchTag, Tag);
}

void AVertex::searchFor(const FString destinationTag, const FString departureTag)
{
	if (this->Tag == destinationTag)
    {

		isVisited = true;
		this->recreatePath(departureTag);

	} else {

		if (!isVisited)
		{
			GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Green, FString::Printf(TEXT("Searching from %s to %s"), *this->Tag, *destinationTag));

			for (auto& vertex : connectedVerticles)
			{
				float newDistance = shortestLength + GetDistanceTo(vertex);
				float storedDistance = vertex->shortestLength;

				GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Blue, FString::Printf(TEXT("Iterating from %s to %s %f"), *this->Tag, *vertex->Tag, newDistance));

				if (newDistance < storedDistance)
				{
					vertex->shortestLength = newDistance;
					this->didUpdateShortest(newDistance);
				}
			}

			isVisited = true;

			for (auto& nextVertex : connectedVerticles)
			{
				nextVertex->searchFor(destinationTag, departureTag);
			}
		}
	}
}

void AVertex::recreatePath(const FString departureTag)
{
	if (isVisited) 
	{
		bool isPathBuilt = false;
		float shortestLength = TNumericLimits<float>::Max();
		AVertex* nearestVertex = connectedVerticles[0];

		for (auto& vertex : connectedVerticles)
		{
			if (vertex->shortestLength < shortestLength)
			{
				if (vertex->Tag == departureTag)
				{
					isPathBuilt = true;
				}
				shortestLength = vertex->shortestLength;
				nearestVertex = vertex;
			}
		}

		FVector linkStart = GetActorLocation();
		FVector linkEnd = nearestVertex->GetActorLocation();
		DrawDebugLine(GetWorld(), linkStart, linkEnd, FColor(255, 255, 255), true, -1.0f, 255, 20);

		if (!isPathBuilt) 
		{
			nearestVertex->recreatePath(departureTag);
		}
	}
}

void AVertex::didUpdateShortest_Implementation(float& distance)
{

}

void AVertex::getAllConnectedVerticles()
{
	for (auto& vertex : laterallyConnectedVerticles)
	{
		connectedVerticles.AddUnique(vertex);
	}
	for (auto& vertex : bilaterallyConnectedVerticles)
	{
		GEngine->AddOnScreenDebugMessage(-1, 500.f, FColor::Orange, FString::Printf(TEXT("Added %s to self %s"), *vertex->Tag, *this->Tag));
		connectedVerticles.AddUnique(vertex);
		vertex->connectedVerticles.AddUnique(this);
	}
}

void AVertex::reset()
{
	vertexWorldLocation = GetActorLocation();
	isVisited = false;
	shortestLength = TNumericLimits<float>::Max();
}


