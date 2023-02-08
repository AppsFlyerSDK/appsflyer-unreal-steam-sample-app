// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AFSteamExample/AFSteamExampleHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAFSteamExampleHUD() {}
// Cross Module References
	AFSTEAMEXAMPLE_API UClass* Z_Construct_UClass_AAFSteamExampleHUD_NoRegister();
	AFSTEAMEXAMPLE_API UClass* Z_Construct_UClass_AAFSteamExampleHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_AFSteamExample();
// End Cross Module References
	void AAFSteamExampleHUD::StaticRegisterNativesAAFSteamExampleHUD()
	{
	}
	UClass* Z_Construct_UClass_AAFSteamExampleHUD_NoRegister()
	{
		return AAFSteamExampleHUD::StaticClass();
	}
	struct Z_Construct_UClass_AAFSteamExampleHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAFSteamExampleHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_AFSteamExample,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAFSteamExampleHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "AFSteamExampleHUD.h" },
		{ "ModuleRelativePath", "AFSteamExampleHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAFSteamExampleHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAFSteamExampleHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAFSteamExampleHUD_Statics::ClassParams = {
		&AAFSteamExampleHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAFSteamExampleHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAFSteamExampleHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAFSteamExampleHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAFSteamExampleHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAFSteamExampleHUD, 1915859373);
	template<> AFSTEAMEXAMPLE_API UClass* StaticClass<AAFSteamExampleHUD>()
	{
		return AAFSteamExampleHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAFSteamExampleHUD(Z_Construct_UClass_AAFSteamExampleHUD, &AAFSteamExampleHUD::StaticClass, TEXT("/Script/AFSteamExample"), TEXT("AAFSteamExampleHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAFSteamExampleHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
