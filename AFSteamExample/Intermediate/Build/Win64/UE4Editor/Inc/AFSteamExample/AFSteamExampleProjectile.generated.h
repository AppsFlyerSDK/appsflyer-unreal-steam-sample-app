// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef AFSTEAMEXAMPLE_AFSteamExampleProjectile_generated_h
#error "AFSteamExampleProjectile.generated.h already included, missing '#pragma once' in AFSteamExampleProjectile.h"
#endif
#define AFSTEAMEXAMPLE_AFSteamExampleProjectile_generated_h

#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_SPARSE_DATA
#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAFSteamExampleProjectile(); \
	friend struct Z_Construct_UClass_AAFSteamExampleProjectile_Statics; \
public: \
	DECLARE_CLASS(AAFSteamExampleProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AFSteamExample"), NO_API) \
	DECLARE_SERIALIZER(AAFSteamExampleProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAAFSteamExampleProjectile(); \
	friend struct Z_Construct_UClass_AAFSteamExampleProjectile_Statics; \
public: \
	DECLARE_CLASS(AAFSteamExampleProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AFSteamExample"), NO_API) \
	DECLARE_SERIALIZER(AAFSteamExampleProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAFSteamExampleProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAFSteamExampleProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAFSteamExampleProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAFSteamExampleProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAFSteamExampleProjectile(AAFSteamExampleProjectile&&); \
	NO_API AAFSteamExampleProjectile(const AAFSteamExampleProjectile&); \
public:


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAFSteamExampleProjectile(AAFSteamExampleProjectile&&); \
	NO_API AAFSteamExampleProjectile(const AAFSteamExampleProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAFSteamExampleProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAFSteamExampleProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAFSteamExampleProjectile)


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AAFSteamExampleProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AAFSteamExampleProjectile, ProjectileMovement); }


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_12_PROLOG
#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_SPARSE_DATA \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_RPC_WRAPPERS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_INCLASS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_SPARSE_DATA \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_INCLASS_NO_PURE_DECLS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AFSTEAMEXAMPLE_API UClass* StaticClass<class AAFSteamExampleProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AFSteamExample_Source_AFSteamExample_AFSteamExampleProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
