// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
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
#ifdef MOBILEVRTEST_MobileVRTestProjectile_generated_h
#error "MobileVRTestProjectile.generated.h already included, missing '#pragma once' in MobileVRTestProjectile.h"
#endif
#define MOBILEVRTEST_MobileVRTestProjectile_generated_h

#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMobileVRTestProjectile(); \
	friend struct Z_Construct_UClass_AMobileVRTestProjectile_Statics; \
public: \
	DECLARE_CLASS(AMobileVRTestProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MobileVRTest"), NO_API) \
	DECLARE_SERIALIZER(AMobileVRTestProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMobileVRTestProjectile(); \
	friend struct Z_Construct_UClass_AMobileVRTestProjectile_Statics; \
public: \
	DECLARE_CLASS(AMobileVRTestProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MobileVRTest"), NO_API) \
	DECLARE_SERIALIZER(AMobileVRTestProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMobileVRTestProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMobileVRTestProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMobileVRTestProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMobileVRTestProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMobileVRTestProjectile(AMobileVRTestProjectile&&); \
	NO_API AMobileVRTestProjectile(const AMobileVRTestProjectile&); \
public:


#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMobileVRTestProjectile(AMobileVRTestProjectile&&); \
	NO_API AMobileVRTestProjectile(const AMobileVRTestProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMobileVRTestProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMobileVRTestProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMobileVRTestProjectile)


#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AMobileVRTestProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AMobileVRTestProjectile, ProjectileMovement); }


#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_9_PROLOG
#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_RPC_WRAPPERS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_INCLASS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_INCLASS_NO_PURE_DECLS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MOBILEVRTEST_API UClass* StaticClass<class AMobileVRTestProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MobileVRTest_Source_MobileVRTest_MobileVRTestProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
