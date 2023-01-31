// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "Containers/Array.h"
#include "UObject/NameTypes.h"
#include "UObject/ConstructorHelpers.h"
#include "Board.generated.h"

enum BoardStates {
	NOT_OCCUPIED    = 0,
	CROSS_OCCUPIED  = 1,
	SPHERE_OCCUPIED = 2,
};

UCLASS()
class TICTACTOE_LUKA_API ABoard : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	ABoard();
	bool GameOngoing{ true };
	int turn{ 1 };
	int occupiedSpace[9] = {0,0,0,0,0,0,0,0,0};

	// Function definition
	void OnePressed() {
		UE_LOG(LogTemp, Warning, TEXT("One Pressed!"));
		if (turn == -1 && occupiedSpace[0] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[0]->SetVisibility(true);
			Parts[9]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[0] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[0] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[0]->SetVisibility(false);
			Parts[9]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[0] = CROSS_OCCUPIED;
			WinCondition();
		}
	}
	void TwoPressed() {
		UE_LOG(LogTemp, Warning, TEXT("Two Pressed!"));
		if (turn == -1 && occupiedSpace[1] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[1]->SetVisibility(true);
			Parts[10]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[1] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[1] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[1]->SetVisibility(false);
			Parts[10]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[1] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void ThreePressed() {
		UE_LOG(LogTemp, Warning, TEXT("Three Pressed!"));
		if (turn == -1 && occupiedSpace[2] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[2]->SetVisibility(true);
			Parts[11]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[2] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[2] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[2]->SetVisibility(false);
			Parts[11]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[2] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void FourPressed() {
		UE_LOG(LogTemp, Warning, TEXT("Four Pressed!"));
		if (turn == -1 && occupiedSpace[3] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[3]->SetVisibility(true);
			Parts[12]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[3] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[3] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[3]->SetVisibility(false);
			Parts[12]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[3] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void FivePressed() {
		UE_LOG(LogTemp, Warning, TEXT("Five Pressed!"));
		if (turn == -1 && occupiedSpace[4] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[4]->SetVisibility(true);
			Parts[13]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[4] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[4] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[4]->SetVisibility(false);
			Parts[13]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[4] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void SixPressed() {
		UE_LOG(LogTemp, Warning, TEXT("Six Pressed!"));
		if (turn == -1 && occupiedSpace[5] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[5]->SetVisibility(true);
			Parts[14]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[5] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[5] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[5]->SetVisibility(false);
			Parts[14]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[5] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void SevenPressed() {
		UE_LOG(LogTemp, Warning, TEXT("Seven Pressed!"));
		if (turn == -1 && occupiedSpace[6] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[6]->SetVisibility(true);
			Parts[15]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[6] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[6] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[6]->SetVisibility(false);
			Parts[15]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[6] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void EightPressed() {
		UE_LOG(LogTemp, Warning, TEXT("Eight Pressed!"));
		if (turn == -1 && occupiedSpace[7] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[7]->SetVisibility(true);
			Parts[16]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[7] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[7] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[7]->SetVisibility(false);
			Parts[16]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[7] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void NinePressed() {
		UE_LOG(LogTemp, Warning, TEXT("Nine Pressed!"));
		if (turn == -1 && occupiedSpace[8] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[8]->SetVisibility(true);
			Parts[17]->SetVisibility(false);
			turn *= -1;
			occupiedSpace[8] = SPHERE_OCCUPIED;
			WinCondition();
		}
		else if (turn == 1 && occupiedSpace[8] == NOT_OCCUPIED && GameOngoing == true) {
			Parts[8]->SetVisibility(false);
			Parts[17]->SetVisibility(true);
			turn *= -1;
			occupiedSpace[8] = CROSS_OCCUPIED;
			WinCondition();
		}
	};
	void WinCondition() {
		// Check for Cross Win

		// horizontal check
		if (occupiedSpace[0] == CROSS_OCCUPIED && occupiedSpace[1] == CROSS_OCCUPIED && occupiedSpace[2] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[3] == CROSS_OCCUPIED && occupiedSpace[4] == CROSS_OCCUPIED && occupiedSpace[5] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[6] == CROSS_OCCUPIED && occupiedSpace[7] == CROSS_OCCUPIED && occupiedSpace[8] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		// vertical check
		else if (occupiedSpace[2] == CROSS_OCCUPIED && occupiedSpace[5] == CROSS_OCCUPIED && occupiedSpace[8] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[1] == CROSS_OCCUPIED && occupiedSpace[5] == CROSS_OCCUPIED && occupiedSpace[7] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[0] == CROSS_OCCUPIED && occupiedSpace[3] == CROSS_OCCUPIED && occupiedSpace[6] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		// diagonal check
		else if (occupiedSpace[0] == CROSS_OCCUPIED && occupiedSpace[4] == CROSS_OCCUPIED && occupiedSpace[8] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[2] == CROSS_OCCUPIED && occupiedSpace[4] == CROSS_OCCUPIED && occupiedSpace[6] == CROSS_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Cross Wins!"));
			GameOngoing = false;
		}
		//Check for Sphere Win

		// horizontal check
		else if (occupiedSpace[0] == SPHERE_OCCUPIED && occupiedSpace[1] == SPHERE_OCCUPIED && occupiedSpace[2] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[3] == SPHERE_OCCUPIED && occupiedSpace[4] == SPHERE_OCCUPIED && occupiedSpace[5] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[6] == SPHERE_OCCUPIED && occupiedSpace[7] == SPHERE_OCCUPIED && occupiedSpace[8] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		// vertical check
		else if (occupiedSpace[2] == SPHERE_OCCUPIED && occupiedSpace[5] == SPHERE_OCCUPIED && occupiedSpace[8] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[1] == SPHERE_OCCUPIED && occupiedSpace[5] == SPHERE_OCCUPIED && occupiedSpace[7] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[0] == SPHERE_OCCUPIED && occupiedSpace[3] == SPHERE_OCCUPIED && occupiedSpace[6] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		// diagonal check
		else if (occupiedSpace[0] == SPHERE_OCCUPIED && occupiedSpace[4] == SPHERE_OCCUPIED && occupiedSpace[8] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		else if (occupiedSpace[2] == SPHERE_OCCUPIED && occupiedSpace[4] == SPHERE_OCCUPIED && occupiedSpace[6] == SPHERE_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Sphere Wins!"));
			GameOngoing = false;
		}
		// check for draw
		else if (occupiedSpace[0] != NOT_OCCUPIED && occupiedSpace[1] != NOT_OCCUPIED && occupiedSpace[2] != NOT_OCCUPIED
			&& occupiedSpace[3] != NOT_OCCUPIED && occupiedSpace[4] != NOT_OCCUPIED && occupiedSpace[5] != NOT_OCCUPIED
			&& occupiedSpace[6] != NOT_OCCUPIED && occupiedSpace[7] != NOT_OCCUPIED && occupiedSpace[8] != NOT_OCCUPIED) {
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Game Draw!"));
		}
	};
	void Reset() {
		for (int i{0}; i < 18; i++) {
			if (i < 9) {
				occupiedSpace[i] = 0;
				Parts[i]->SetVisibility(false);
			};
			if (i >= 9) {
				Parts[i]->SetVisibility(false);
			};
		};
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Game Reset!"));
		GameOngoing = true;
	};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		USceneComponent* Root;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BoardMesh;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TArray<UStaticMeshComponent*> Parts;
};