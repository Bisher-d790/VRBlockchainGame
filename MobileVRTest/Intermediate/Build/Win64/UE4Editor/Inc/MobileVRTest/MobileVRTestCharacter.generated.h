// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MOBILEVRTEST_MobileVRTestCharacter_generated_h
#error "MobileVRTestCharacter.generated.h already included, missing '#pragma once' in MobileVRTestCharacter.h"
#endif
#define MOBILEVRTEST_MobileVRTestCharacter_generated_h

#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_RPC_WRAPPERS
#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMobileVRTestCharacter(); \
	friend struct Z_Construct_UClass_AMobileVRTestCharacter_Statics; \
public: \
	DECLARE_CLASS(AMobileVRTestCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MobileVRTest"), NO_API) \
	DECLARE_SERIALIZER(AMobileVRTestCharacter)


#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAMobileVRTestCharacter(); \
	friend struct Z_Construct_UClass_AMobileVRTestCharacter_Statics; \
public: \
	DECLARE_CLASS(AMobileVRTestCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MobileVRTest"), NO_API) \
	DECLARE_SERIALIZER(AMobileVRTestCharacter)


#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMobileVRTestCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMobileVRTestCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMobileVRTestCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMobileVRTestCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMobileVRTestCharacter(AMobileVRTestCharacter&&); \
	NO_API AMobileVRTestCharacter(const AMobileVRTestCharacter&); \
public:


#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMobileVRTestCharacter(AMobileVRTestCharacter&&); \
	NO_API AMobileVRTestCharacter(const AMobileVRTestCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMobileVRTestCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMobileVRTestCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMobileVRTestCharacter)


#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AMobileVRTestCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AMobileVRTestCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AMobileVRTestCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AMobileVRTestCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AMobileVRTestCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AMobileVRTestCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AMobileVRTestCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AMobileVRTestCharacter, L_MotionController); }


#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_11_PROLOG
#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_RPC_WRAPPERS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_INCLASS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_INCLASS_NO_PURE_DECLS \
	MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MOBILEVRTEST_API UClass* StaticClass<class AMobileVRTestCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MobileVRTest_Source_MobileVRTest_MobileVRTestCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
