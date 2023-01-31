// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

// Sets default values
ABoard::ABoard()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Root Construct
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Board Root"));
	RootComponent = Root;

	// Board Construct
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshComponentBoard(TEXT("'/Game/StaticMeshes/SM_Board.SM_Board'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>
		MaterialBoard(TEXT("'/Game/Materials/Gold_Material.Gold_Material'"));

	BoardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Board"));
	BoardMesh->SetupAttachment(Root);
	BoardMesh->SetStaticMesh(MeshComponentBoard.Object);
	BoardMesh->SetMaterial(0, MaterialBoard.Object);

	// Springarm Construct
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Root);
	SpringArm->TargetArmLength = 1500.f;

	SpringArm->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// Parts Construct
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshComponentSpheres(TEXT("'/Game/StaticMeshes/SM_Sphere.SM_Sphere'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshComponentCross(TEXT("'/Game/StaticMeshes/SM_Cross.SM_Cross'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>
		MaterialParts(TEXT("'/Game/Materials/White_Material.White_Material'"));

	Parts.Init(NULL, 18);
	for (int i{}; i < 18; i++) {
		FString num = FString::FromInt(i);
		if (i < 9) {
			Parts[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(("Part " + num)));
			Parts[i]->SetupAttachment(Root);
			Parts[i]->SetStaticMesh(MeshComponentSpheres.Object);
			Parts[i]->SetMaterial(0, MaterialParts.Object);
			Parts[i]->SetVisibility(false);
		}
		else if (i >= 9) {
			Parts[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(("Part " + num)));
			Parts[i]->SetupAttachment(Root);
			Parts[i]->SetStaticMesh(MeshComponentCross.Object);
			Parts[i]->SetMaterial(0, MaterialParts.Object);
			Parts[i]->SetVisibility(false);
			Parts[i]->SetRelativeScale3D(FVector(0.2, 0.2, 0.2));
			Parts[i]->AddRelativeRotation(FQuat(0, 0, 0.3826834, 0.9238795));
		}
	}

	Parts[0]->SetRelativeLocation(FVector(330.f, -330.f, 0.f));
	Parts[1]->SetRelativeLocation(FVector(330.f, 0.f, 0.f));
	Parts[2]->SetRelativeLocation(FVector(330.f, 330.f, 0.f));
	Parts[3]->SetRelativeLocation(FVector(0.f, -330.f, 0.f));
	Parts[4]->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Parts[5]->SetRelativeLocation(FVector(0.f, 330.f, 0.f));
	Parts[6]->SetRelativeLocation(FVector(-330.f, -330.f, 0.f));
	Parts[7]->SetRelativeLocation(FVector(-330.f, 0.f, 0.f));
	Parts[8]->SetRelativeLocation(FVector(-330.f, 330.f, 0.f));

	Parts[9]->SetRelativeLocation(FVector(330.f, -330.f, 0.f));
	Parts[10]->SetRelativeLocation(FVector(330.f, 0.f, 0.f));
	Parts[11]->SetRelativeLocation(FVector(330.f, 330.f, 0.f));
	Parts[12]->SetRelativeLocation(FVector(0.f, -330.f, 0.f));
	Parts[13]->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Parts[14]->SetRelativeLocation(FVector(0.f, 330.f, 0.f));
	Parts[15]->SetRelativeLocation(FVector(-330.f, -330.f, 0.f));
	Parts[16]->SetRelativeLocation(FVector(-330.f, 0.f, 0.f));
	Parts[17]->SetRelativeLocation(FVector(-330.f, 330.f, 0.f));

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Welcome to Tic Tac Toe! Alternate in turns and use keys 1-9 to select your position on the board. Spacebar to reset."));
}


// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("1", IE_Pressed, this, &ABoard::OnePressed);
	PlayerInputComponent->BindAction("2", IE_Pressed, this, &ABoard::TwoPressed);
	PlayerInputComponent->BindAction("3", IE_Pressed, this, &ABoard::ThreePressed);
	PlayerInputComponent->BindAction("4", IE_Pressed, this, &ABoard::FourPressed);
	PlayerInputComponent->BindAction("5", IE_Pressed, this, &ABoard::FivePressed);
	PlayerInputComponent->BindAction("6", IE_Pressed, this, &ABoard::SixPressed);
	PlayerInputComponent->BindAction("7", IE_Pressed, this, &ABoard::SevenPressed);
	PlayerInputComponent->BindAction("8", IE_Pressed, this, &ABoard::EightPressed);
	PlayerInputComponent->BindAction("9", IE_Pressed, this, &ABoard::NinePressed);
	PlayerInputComponent->BindAction("Reset", IE_Pressed, this, &ABoard::Reset);
}

