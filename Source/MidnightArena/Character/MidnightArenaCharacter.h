// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.h"
#include "MidnightArenaCharacter.generated.h"

UCLASS(Blueprintable)
class AMidnightArenaCharacter : public ABaseCharacter
{
	GENERATED_BODY()
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Widget, meta = (AllowPrivateAccess = true))
		class UWidgetComponent* OverheadWidget;
protected:
	virtual void BeginPlay() override;

public:
	AMidnightArenaCharacter();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	UFUNCTION(Category = Camera)
		void CameraZoom(float value);
	UFUNCTION(Category = "Movement")
		void MoveAlongControllerAxisX(float Value);

	UFUNCTION(Category = "Movement")
		void MoveAlongControllerAxisY(float Value);
	UFUNCTION(Category = "Movement")
		void MoveAlongCameraAxisX(float Value);

	UFUNCTION(Category = "Movement")
		void MoveAlongCameraAxisY(float Value);

	UFUNCTION(Category = "Movement")
		void LookAtLocation(FVector locationToLookAt);


};

