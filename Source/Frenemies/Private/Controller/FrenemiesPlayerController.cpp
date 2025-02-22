// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/FrenemiesPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI/Widget/FrenemiesUserWidget.h"

AFrenemiesPlayerController::AFrenemiesPlayerController()
{
	bReplicates = true;
}

void AFrenemiesPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(FrenemiesMoveAction, ETriggerEvent::Triggered, this, &AFrenemiesPlayerController::Move);
	
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFrenemiesPlayerController::Look);

	EnhancedInputComponent->BindAction(OpenMenuAction, ETriggerEvent::Triggered, this, &AFrenemiesPlayerController::OpenMenuTrigger);

}


void AFrenemiesPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(FrenemiesPlayerContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(FrenemiesPlayerContext, 0);
	}
	

	//show mouse and its data
	// bShowMouseCursor = true;
	// DefaultMouseCursor = EMouseCursor::Default;
	//
	// FInputModeGameAndUI InputModeData;
	// InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	// InputModeData.SetHideCursorDuringCapture(false);
	// SetInputMode(InputModeData);
}

void AFrenemiesPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	//this gives forward vector of our player controller by using the yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	
}

void AFrenemiesPlayerController::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// add yaw and pitch input to controller
		ControlledPawn->AddControllerYawInput(LookAxisVector.X);
		ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AFrenemiesPlayerController::OpenAttributeMenuC()
{
	// Ensure the WidgetClass is valid (critical assumption)
	check(WidgetClass != nullptr); // Crash if WidgetClass is not set

	// Create the widget (critical operation)
	AttributeWidget = CreateWidget<UFrenemiesUserWidget>(this, WidgetClass);
	check(AttributeWidget != nullptr); // Crash if widget creation fails

	// Add the widget to the viewport
	AttributeWidget->AddToViewport();

	FVector2d ScreenPosition = FVector2d(50.0f,50.0f);
	
	// Set the widget's position in the viewport
	AttributeWidget->SetPositionInViewport(ScreenPosition, false); // Second parameter is "bRemoveDPIScale"

	// Set focus to the widget
	AttributeWidget->SetFocus();

	// Set input mode to UI Only
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(AttributeWidget->TakeWidget()); // Set the widget to focus
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // Allow mouse to move freely
	SetInputMode(InputMode);

	// Show the mouse cursor
	bShowMouseCursor = true;

	UE_LOG(LogTemp, Warning, TEXT("Widget opened at position (%f, %f) and input mode set to UI Only."), ScreenPosition.X, ScreenPosition.Y);
}



void AFrenemiesPlayerController::OpenMenuTrigger(const FInputActionValue& Value)
{
	OpenAttributeMenuC();
}
