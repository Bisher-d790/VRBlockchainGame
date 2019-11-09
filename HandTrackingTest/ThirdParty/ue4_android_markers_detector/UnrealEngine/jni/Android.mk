LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := markersdetector
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libmarkersdetector.so
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r2.2.0
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r2.2.0.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r2.3.3
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r2.3.3.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r3.0.1
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r3.0.1.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r4.0.0
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r4.0.0.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r4.0.3
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r4.0.3.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r4.1.1
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r4.1.1.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r4.2.0
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r4.2.0.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r4.3.0
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r4.3.0.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_camera_r4.4.0
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libnative_camera_r4.4.0.so
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := UE4
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libUE4.so
include $(PREBUILT_SHARED_LIBRARY)
