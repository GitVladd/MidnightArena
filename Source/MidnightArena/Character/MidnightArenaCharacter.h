// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MidnightArenaCharacter.generated.h"

UCLASS(Blueprintable)
class AMidnightArenaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMidnightArenaCharacter();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraZoomSpeed = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraInitialDistance = 1500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraMaxDistance = 2000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraMinDistance = 500;


private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = true))
		class UHealthComponent* HealthComponent;

private:
	void InitHealthComponent();
public:
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }


	UFUNCTION(Category = Camera)
		void CameraZoom(float value);

	UFUNCTION(Category = "Movement")
		void MoveCharacter(float axisX, float axisY);

	UFUNCTION(Category = "Movement")
		void LookAtLocation(FVector locationToLookAt);

	/** Event for taking damage. Overridden from APawn.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
		float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};

