// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MobileVRTest/MobileVRTestGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMobileVRTestGameMode() {}
// Cross Module References
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestGameMode_NoRegister();
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MobileVRTest();
// End Cross Module References
	void AMobileVRTestGameMode::StaticRegisterNativesAMobileVRTestGameMode()
	{
	}
	UClass* Z_Construct_UClass_AMobileVRTestGameMode_NoRegister()
	{
		return AMobileVRTestGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMobileVRTestGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMobileVRTestGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MobileVRTest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MobileVRTestGameMode.h" },
		{ "ModuleRelativePath", "MobileVRTestGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMobileVRTestGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMobileVRTestGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMobileVRTestGameMode_Statics::ClassParams = {
		&AMobileVRTestGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMobileVRTestGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMobileVRTestGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMobileVRTestGameMode, 584099102);
	template<> MOBILEVRTEST_API UClass* StaticClass<AMobileVRTestGameMode>()
	{
		return AMobileVRTestGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMobileVRTestGameMode(Z_Construct_UClass_AMobileVRTestGameMode, &AMobileVRTestGameMode::StaticClass, TEXT("/Script/MobileVRTest"), TEXT("AMobileVRTestGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMobileVRTestGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
