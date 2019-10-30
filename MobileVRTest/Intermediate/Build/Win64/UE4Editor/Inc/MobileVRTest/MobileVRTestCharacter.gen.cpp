// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MobileVRTest/MobileVRTestCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMobileVRTestCharacter() {}
// Cross Module References
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestCharacter_NoRegister();
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MobileVRTest();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	MOBILEVRTEST_API UClass* Z_Construct_UClass_AMobileVRTestProjectile_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	void AMobileVRTestCharacter::StaticRegisterNativesAMobileVRTestCharacter()
	{
	}
	UClass* Z_Construct_UClass_AMobileVRTestCharacter_NoRegister()
	{
		return AMobileVRTestCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMobileVRTestCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUsingMotionControllers_MetaData[];
#endif
		static void NewProp_bUsingMotionControllers_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUsingMotionControllers;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireSound;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GunOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GunOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_L_MotionController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_L_MotionController;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_R_MotionController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_R_MotionController;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FirstPersonCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FirstPersonCameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VR_MuzzleLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VR_MuzzleLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VR_Gun_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VR_Gun;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FP_MuzzleLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FP_MuzzleLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FP_Gun_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FP_Gun;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh1P_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh1P;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMobileVRTestCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MobileVRTest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MobileVRTestCharacter.h" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** Whether to use motion controller location for aiming. */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Whether to use motion controller location for aiming." },
	};
#endif
	void Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers_SetBit(void* Obj)
	{
		((AMobileVRTestCharacter*)Obj)->bUsingMotionControllers = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers = { "bUsingMotionControllers", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AMobileVRTestCharacter), &Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireAnimation_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** AnimMontage to play each time we fire */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "AnimMontage to play each time we fire" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireAnimation = { "FireAnimation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, FireAnimation), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireAnimation_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireSound_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** Sound to play each time we fire */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Sound to play each time we fire" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireSound_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireSound_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "/** Projectile class to spawn */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Projectile class to spawn" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, ProjectileClass), Z_Construct_UClass_AMobileVRTestProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_ProjectileClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_ProjectileClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_GunOffset_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** Gun muzzle's offset from the characters location */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Gun muzzle's offset from the characters location" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_GunOffset = { "GunOffset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, GunOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_GunOffset_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_GunOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseLookUpRate_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseTurnRate_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_L_MotionController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "MobileVRTestCharacter" },
		{ "Comment", "/** Motion controller (left hand) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Motion controller (left hand)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_L_MotionController = { "L_MotionController", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, L_MotionController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_L_MotionController_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_L_MotionController_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_R_MotionController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "MobileVRTestCharacter" },
		{ "Comment", "/** Motion controller (right hand) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Motion controller (right hand)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_R_MotionController = { "R_MotionController", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, R_MotionController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_R_MotionController_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_R_MotionController_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** First person camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "First person camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FirstPersonCameraComponent = { "FirstPersonCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, FirstPersonCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_MuzzleLocation_MetaData[] = {
		{ "Category", "Mesh" },
		{ "Comment", "/** Location on VR gun mesh where projectiles should spawn. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Location on VR gun mesh where projectiles should spawn." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_MuzzleLocation = { "VR_MuzzleLocation", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, VR_MuzzleLocation), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_MuzzleLocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_MuzzleLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_Gun_MetaData[] = {
		{ "Category", "Mesh" },
		{ "Comment", "/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_Gun = { "VR_Gun", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, VR_Gun), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_Gun_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_Gun_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_MuzzleLocation_MetaData[] = {
		{ "Category", "Mesh" },
		{ "Comment", "/** Location on gun mesh where projectiles should spawn. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Location on gun mesh where projectiles should spawn." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_MuzzleLocation = { "FP_MuzzleLocation", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, FP_MuzzleLocation), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_MuzzleLocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_MuzzleLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_Gun_MetaData[] = {
		{ "Category", "Mesh" },
		{ "Comment", "/** Gun mesh: 1st person view (seen only by self) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Gun mesh: 1st person view (seen only by self)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_Gun = { "FP_Gun", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, FP_Gun), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_Gun_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_Gun_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_Mesh1P_MetaData[] = {
		{ "Category", "Mesh" },
		{ "Comment", "/** Pawn mesh: 1st person view (arms; seen only by self) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MobileVRTestCharacter.h" },
		{ "ToolTip", "Pawn mesh: 1st person view (arms; seen only by self)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_Mesh1P = { "Mesh1P", nullptr, (EPropertyFlags)0x00400000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMobileVRTestCharacter, Mesh1P), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_Mesh1P_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_Mesh1P_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMobileVRTestCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_bUsingMotionControllers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FireSound,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_ProjectileClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_GunOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_L_MotionController,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_R_MotionController,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FirstPersonCameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_MuzzleLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_VR_Gun,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_MuzzleLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_FP_Gun,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMobileVRTestCharacter_Statics::NewProp_Mesh1P,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMobileVRTestCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMobileVRTestCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMobileVRTestCharacter_Statics::ClassParams = {
		&AMobileVRTestCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMobileVRTestCharacter_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMobileVRTestCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMobileVRTestCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMobileVRTestCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMobileVRTestCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMobileVRTestCharacter, 3487301676);
	template<> MOBILEVRTEST_API UClass* StaticClass<AMobileVRTestCharacter>()
	{
		return AMobileVRTestCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMobileVRTestCharacter(Z_Construct_UClass_AMobileVRTestCharacter, &AMobileVRTestCharacter::StaticClass, TEXT("/Script/MobileVRTest"), TEXT("AMobileVRTestCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMobileVRTestCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
