/*
 *  Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *  Not a Contribution, Apache license notifications and license are retained
 *  for attribution purposes only.
 *
 *  Copyright (C) 2012 The Android Open Source Project
 *  Copyright (C) 2016 The CyanogenMod Project
 *  Copyright (C) 2020 The LineageOS Project
 *
 *  SPDX-License-Identifier: Apache-2.0
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#include <stdint.h>
#pragma push_macro("PROPERTY_VALUE_MAX")

#include <cutils/properties.h>
#include <string.h>

static inline const char* BtmGetDefaultName()
{
    char product_model[PROPERTY_VALUE_MAX];
    property_get("ro.product.model", product_model, "");

    if (strstr(product_model, "Mi 9"))
        return "Mi 9";
    

    // Fallback to ro.product.model
    return "";
}
#undef PROPERTY_VALUE_MAX

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()
// Disables read remote device feature
#define BTM_WBS_INCLUDED TRUE
#define BTIF_HF_WBS_PREFERRED TRUE

#define MAX_ACL_CONNECTIONS   16
#define MAX_L2CAP_CHANNELS    16
#define BLE_VND_INCLUDED   TRUE

/* Increasing SEPs to 12 from 6 to support SHO/MCast i.e. two streams per codec */
#define AVDT_NUM_SEPS 12
#pragma pop_macro("PROPERTY_VALUE_MAX")

#endif