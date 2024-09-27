//2020105582 ±«πŒ¡ÿ

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPP_Custom_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ACPP_Custom_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACPP_Custom_PlayerController();

protected:
	virtual void BeginPlay() override;

private:
	void PossessNextCharacter();

	TArray<ACharacter*> Characters;

	FTimerHandle Timerhandle;

	int32 Index;
	
};
