LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := ./oled_test.c 
LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_MODULE := oled_test
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := /home/network_share/test/oled
include $(BUILD_EXECUTABLE) 