// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MobileVRTest/MobileVRTestProjectile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMobileVRTestProjectile() {}
// Cross Module References
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestProjectile_NoRegister();
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MobileVRTest();
	MOBILEVRTEST_API UFunction* Z_Construct_UFunction_AMobileVRTestProjectile_OnHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	void AMobileVRTestProjectile::StaticRegisterNativesAMobileVRTestProjectile()
	{
		UClass* Class = AMobileVRTestProjectile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHit", &AMobileVRTestProjectile::execOnHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics
	{
		struct MobileVRTestProjectile_eventOnHit_Parms
		{
			UPrimitiveComponent* HitComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalImpulse;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MobileVRTestProjectile_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_Hit_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_Hit_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MobileVRTestProjectile_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MobileVRTestProjectile_eventOnHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MobileVRTestProjectile_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MobileVRTestProjectile_eventOnHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_HitComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_HitComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_Hit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_NormalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::NewProp_HitComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** called when projectile hits something */" },
		{ "ModuleRelativePath", "MobileVRTestProjectile.h" },
		{ "ToolTip", "called when projectile hits something" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMobileVRTestProjectile, nullptr, "OnHit", nullptr, nullptr, sizeof(MobileVRTestProjectile_eventOnHit_Parms), Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMobileVRTestProjectile_OnHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMobileVRTestProjectile_OnHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMobileVRTestProjectile_NoRegister()
	{
		return AMobileVRTestProjectile::StaticClass();
	}
	struct Z_Construct_UClass_AMobileVRTestProjectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMobileVRTestProjectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MobileVRTest,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMobileVRTestProjectile_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMobileVRTestProjectile_OnHit, "OnHit" }, // 2128173588
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestProjectile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MobileVRTestProjectile.h" },
		{ "ModuleRelativePath", "MobileVRTestProjectile.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_ProjectileMovement_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "/** Projectile movement component */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestProjectile.h" },
		{ "ToolTip", "Projectile movement component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_ProjectileMovement = { "ProjectileMovement", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestProjectile, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_ProjectileMovement_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_ProjectileMovement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_CollisionComp_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "/** Sphere collision component */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestProjectile.h" },
		{ "ToolTip", "Sphere collision component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_CollisionComp = { "CollisionComp", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestProjectile, CollisionComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_CollisionComp_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_CollisionComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMobileVRTestProjectile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_ProjectileMovement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestProjectile_Statics::NewProp_CollisionComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMobileVRTestProjectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMobileVRTestProjectile>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMobileVRTestProjectile_Statics::ClassParams = {
		&AMobileVRTestProjectile::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMobileVRTestProjectile_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestProjectile_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestProjectile_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestProjectile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMobileVRTestProjectile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMobileVRTestProjectile_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMobileVRTestProjectile, 1670071586);
	template<> MOBILEVRTEST_API UClass* StaticClass<AMobileVRTestProjectile>()
	{
		return AMobileVRTestProjectile::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMobileVRTestProjectile(Z_Construct_UClass_AMobileVRTestProjectile, &AMobileVRTestProjectile::StaticClass, TEXT("/Script/MobileVRTest"), TEXT("AMobileVRTestProjectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMobileVRTestProjectile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
