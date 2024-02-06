

#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ABird::ABird()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(Capsule);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);

}

void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABird::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABird::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABird::Turn);
}

void ABird::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void ABird::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ABird::Turn(float Value)
{
	AddControllerYawInput(Value);
}

