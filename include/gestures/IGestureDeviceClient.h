/*
 * Copyright (c) 2012-2013 The Linux Foundation. All rights reserved.
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_IGESTURE_DEVICE_APP_H
#define ANDROID_HARDWARE_IGESTURE_DEVICE_APP_H

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <utils/Timers.h>
#include <system/gestures.h>

namespace android {

class IGestureDeviceClient: public IInterface
{
public:
    DECLARE_META_INTERFACE(GestureDeviceClient);

    virtual void notifyCallback(int32_t msgType, int32_t ext1, int32_t ext2) = 0;
    virtual void dataCallback(gesture_result_t* gs_results) = 0;
};

// ----------------------------------------------------------------------------

class BnGestureDeviceClient: public BnInterface<IGestureDeviceClient>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

}; // namespace android

#endif
