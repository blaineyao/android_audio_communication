LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := AudioCoder
LOCAL_SRC_FILES := AudioCoder.cpp

include $(BUILD_SHARED_LIBRARY)
