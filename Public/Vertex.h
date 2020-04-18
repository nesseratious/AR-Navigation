/**
* AR Navigation
*
* Copyright 2020 Denis Esie
**/

#pragma once

#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Vertex.generated.h"

UCLASS()
class NAVIGATION_API AVertex : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AVertex();

    // Internal Tag, used for search algorithms. If empty, vertex's name will be used as Tag.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Vertex)
    FString Tag;

    // Localizable user-friendly name for this vertex (Canteen, Library etc).
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Vertex)
    FText friendlyName;

    // Array of NavigationGraphVertex connected to this vertex bilaterally (Stair, Corridor etc). Navigation path will be drawed in both directions.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Connections)
    TArray<AVertex*> bilaterallyConnectedVerticles;

    // Array of NavigationGraphVertex connected to this vertex laterally (Turnstile, Escalator etc). Navigation path will be drawed only in one direction.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Connections)
    TArray<AVertex*> laterallyConnectedVerticles;

    // 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Debug)
    bool drawDebugVisualization;

    //
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Debug)
    float debugVisualizationScale;

    // Build shortes path from current vertex to destination vertex with searchTag.
    UFUNCTION(BlueprintCallable, Category = Navigation)
    void buildNavigationPath(const FString searchTag);

    // Delegate
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Navigation)
    void didUpdateShortest(float& distance);

protected:
    
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    void searchFor(const FString destinationTag, const FString departureTag);

    void recreatePath(const FString departureTag);

    void getAllConnectedVerticles();

    void reset();

    UPROPERTY(BlueprintReadOnly, Category = Connections)
    TArray<AVertex*> connectedVerticles;

    bool isVisited;

    float shortestLength;

    FVector vertexWorldLocation;

};
