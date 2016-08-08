// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be last include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
	
	void AimTowardsCrosshair(); //move barrel to where crosshair is pointing

	bool GetSightRayHitLocation(FVector& HitLocation) const;// return an out parameter, true if hit landscape

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};

