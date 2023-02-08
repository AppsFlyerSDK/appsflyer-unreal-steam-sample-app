// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AFSTEAMEXAMPLE_AFSteamExampleCharacter_generated_h
#error "AFSteamExampleCharacter.generated.h already included, missing '#pragma once' in AFSteamExampleCharacter.h"
#endif
#define AFSTEAMEXAMPLE_AFSteamExampleCharacter_generated_h

#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_SPARSE_DATA
#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_RPC_WRAPPERS
#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAFSteamExampleCharacter(); \
	friend struct Z_Construct_UClass_AAFSteamExampleCharacter_Statics; \
public: \
	DECLARE_CLASS(AAFSteamExampleCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AFSteamExample"), NO_API) \
	DECLARE_SERIALIZER(AAFSteamExampleCharacter)


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAAFSteamExampleCharacter(); \
	friend struct Z_Construct_UClass_AAFSteamExampleCharacter_Statics; \
public: \
	DECLARE_CLASS(AAFSteamExampleCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AFSteamExample"), NO_API) \
	DECLARE_SERIALIZER(AAFSteamExampleCharacter)


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAFSteamExampleCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAFSteamExampleCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAFSteamExampleCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAFSteamExampleCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAFSteamExampleCharacter(AAFSteamExampleCharacter&&); \
	NO_API AAFSteamExampleCharacter(const AAFSteamExampleCharacter&); \
public:


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAFSteamExampleCharacter(AAFSteamExampleCharacter&&); \
	NO_API AAFSteamExampleCharacter(const AAFSteamExampleCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAFSteamExampleCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAFSteamExampleCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAFSteamExampleCharacter)


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AAFSteamExampleCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AAFSteamExampleCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AAFSteamExampleCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AAFSteamExampleCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AAFSteamExampleCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AAFSteamExampleCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AAFSteamExampleCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AAFSteamExampleCharacter, L_MotionController); }


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_17_PROLOG
#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_SPARSE_DATA \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_RPC_WRAPPERS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_INCLASS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_SPARSE_DATA \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_INCLASS_NO_PURE_DECLS \
	AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> AFSTEAMEXAMPLE_API UClass* StaticClass<class AAFSteamExampleCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AFSteamExample_Source_AFSteamExample_AFSteamExampleCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
