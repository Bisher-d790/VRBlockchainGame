// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MobileVRTest/MobileVRTestHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMobileVRTestHUD() {}
// Cross Module References
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestHUD_NoRegister();
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_MobileVRTest();
// End Cross Module References
	void AMobileVRTestHUD::StaticRegisterNativesAMobileVRTestHUD()
	{
	}
	UClass* Z_Construct_UClass_AMobileVRTestHUD_NoRegister()
	{
		return AMobileVRTestHUD::StaticClass();
	}
	struct Z_Construct_UClass_AMobileVRTestHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMobileVRTestHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_MobileVRTest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "MobileVRTestHUD.h" },
		{ "ModuleRelativePath", "MobileVRTestHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMobileVRTestHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMobileVRTestHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMobileVRTestHUD_Statics::ClassParams = {
		&AMobileVRTestHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMobileVRTestHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMobileVRTestHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMobileVRTestHUD, 2903951165);
	template<> MOBILEVRTEST_API UClass* StaticClass<AMobileVRTestHUD>()
	{
		return AMobileVRTestHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMobileVRTestHUD(Z_Construct_UClass_AMobileVRTestHUD, &AMobileVRTestHUD::StaticClass, TEXT("/Script/MobileVRTest"), TEXT("AMobileVRTestHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMobileVRTestHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
