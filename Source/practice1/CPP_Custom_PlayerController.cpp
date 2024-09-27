//2020105582 ±«πŒ¡ÿ

#include "CPP_Custom_PlayerController.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"

ACPP_Custom_PlayerController::ACPP_Custom_PlayerController() {
	Index = 0;
}

void ACPP_Custom_PlayerController::BeginPlay() {
	Super::BeginPlay();

	for (TActorIterator<ACharacter> It(GetWorld()); It; ++It) {
		Characters.Add(*It);
	}

	GetWorld()->GetTimerManager().SetTimer(
		Timerhandle,
		this,
		&ACPP_Custom_PlayerController::PossessNextCharacter,
		2.0f,
		true
	);
}

void ACPP_Custom_PlayerController::PossessNextCharacter() {
	if (Characters.Num() > 0) {
		Possess(Characters[Index]);
		Index = (Index + 1) % Characters.Num();
	}
}