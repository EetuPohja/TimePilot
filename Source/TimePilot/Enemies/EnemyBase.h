// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSpawnerEnemy.h"
#include "DamageTypes/DamageTypeBase.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "VisualLogger/VisualLoggerTypes.h"
#include "EnemyBase.generated.h"

USTRUCT(BlueprintType)
struct FEnemyFX
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	TWeakObjectPtr<class UNiagaraSystem> aImpactExplodeVFX = nullptr;
	//TArray<class UNiagraSystem*> aImpactExplodeVFX;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	TArray<class USoundCue*> aAudioExplosions;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	TWeakObjectPtr<class USoundCue> pAudioImpactGun = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	TWeakObjectPtr<class USoundCue> pAudioImpactMissile = nullptr;
};

USTRUCT(BlueprintType)
struct FEnemyProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	float m_fMovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	float m_fTurnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	float m_fTurnBoost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	float m_fVisionDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	float m_fAgression;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	FDataTableRowHandle EnemyDataRow;
};

USTRUCT(BlueprintType)
struct FEnemyDamageProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	bool bCanTakeDamage = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	TArray<EDamageId> aRespondsToDamageTypes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	float fHealth = 0.0f;
};


UCLASS(BlueprintType, Blueprintable)
class TIMEPILOT_API AEnemyBase : public AActor, public ILevelSpawnerEnemy//, public IVisualLoggerEditorInterface 
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyBase();

#if ENABLE_VISUAL_LOG
	// virtual void GrabDebugSnapshot(FVisualLogEntry* Snapshot) const override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetLevelSpawnControllerRef_Implementation(ALevelSpawner* pSpawnController) override { m_pLevelSpawnController = pSpawnController; }
	virtual void SetEventUID_Implementation(const int iUID) override { m_iEventUID = iUID; }

	virtual  float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION(BlueprintNativeEvent)
	void BeginDestroyEnemy();
	void BeginDestroyEnemy_Implementation() {}

	UFUNCTION(BlueprintNativeEvent)
	void TickAfterDamage(const float fDamageTaken);
	void TickAfterDamage_Implementation(const float fDamageTaken) {}

	// ------------------------------------------------------------------------------------------------------------
	// PROPERTIES
	// ------------------------------------------------------------------------------------------------------------
	
	UPROPERTY(BlueprintReadWrite)
	int m_iEventUID = 0;

	UPROPERTY(BlueprintReadWrite)
	class ALevelSpawner* m_pLevelSpawnController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USphereComponent* m_pCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* m_pMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UFloatingPawnMovement* m_pMovementComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<class UWeaponBase> m_Gun;
	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	FEnemyFX m_Effects;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	FEnemyProperties m_Params;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties | Enemy Settings")
	FEnemyDamageProperties m_DamageParams;
};
