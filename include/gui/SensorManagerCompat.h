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

#ifndef ANDROID_GUI_SENSOR_MANAGER_COMPAT_H
#define ANDROID_GUI_SENSOR_MANAGER_COMPAT_H

#include <gui/SensorManager.h>

// ----------------------------------------------------------------------------
namespace android {
// ----------------------------------------------------------------------------

// Compatibility with KitKat SensorManager
class SensorMgrComp :
    public ASensorManager,
    public Singleton<SensorMgrComp>
{
public:
    SensorMgrComp();
    ~SensorMgrComp();
    ssize_t getSensorList(Sensor const* const** list) const;
    Sensor const* getDefaultSensor(int type);
    sp<SensorEventQueue> createEventQueue();
private:
    SensorManager* sensorManagerInst;
};

// ----------------------------------------------------------------------------
}; // namespace android

#endif // ANDROID_GUI_SENSOR_MANAGER_COMPAT_H
