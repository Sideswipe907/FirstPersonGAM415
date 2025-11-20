// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerlinProcTerrain.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class FIRSTPERSON415_API APerlinProcTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerlinProcTerrain();

	//generates how we're gonna be generating the size our landscape. Values of these variables cannot go Can't go below zero

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0)) //generates how we're gonna be generating the size our landscape using the X value

		int XSize = 0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0)) //generates how we're gonna be generating the size our landscape using the Y Value.

		int YSize = 0;


	//ZMultiplier multiplies the height of our Noise. These 2 Variables go hand in hand

	UPROPERTY(EditAnywhere, BlueprintReadwrite, Meta = (ClampMin = 0))

		float ZMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))

		float NoiseScale = 1.0f;

	//Scale and UVScale I believe is how a scale works in a 3D modeler

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))

		float Scale = 0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0.000001))

		float UVScale = 0;

	//Radius and Depth are for how you want the holes in your terrain to be


	UPROPERTY(EditAnywhere)

		float radius;

	UPROPERTY(EditAnywhere)

		FVector Depth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Mat; // our material that we're able to apply to our class

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void AlterMesh(FVector impactPoint); // the function we're gonna call to alter the mesh

private:
	UProceduralMeshComponent* ProcMesh;
	TArray<FVector> Vertices;
	TArray<int> Triangles;
	TArray<FVector2D> UV0;
	TArray<FVector> Normals;
	TArray<FColor> UpVertexColors;

	int sectionID = 0;

	void CreateVertices(); //generate our vertices first
	void CreateTriangles(); //generate our triangles last

};
