/*
 * Copyright (C) 2015 The Android Open Source Project
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

#define LOG_TAG "Sensors"

#include <gui/SensorManagerCompat.h>

// ----------------------------------------------------------------------------
namespace android {
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// compat with gpsd
// ----------------------------------------------------------------------------

ANDROID_SINGLETON_STATIC_INSTANCE(SensorMgrComp)

SensorMgrComp::SensorMgrComp() {
    sensorManagerInst = &SensorManager::getInstanceForPackage(String16());
}

SensorMgrComp::~SensorMgrComp() {
    sensorManagerInst = NULL;
}

ssize_t SensorMgrComp::getSensorList(Sensor const* const** list) const {
    return sensorManagerInst->getSensorList(list);
}

Sensor const* SensorMgrComp::getDefaultSensor(int type) {
    return sensorManagerInst->getDefaultSensor(type);
}

sp<SensorEventQueue> SensorMgrComp::createEventQueue() {
    return sensorManagerInst->createEventQueue();
}

// ----------------------------------------------------------------------------
}; // namespace android
