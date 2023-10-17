/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#ifndef DRIVER_BLE_H_
#define DRIVER_BLE_H_

#include "public.h"

VEH_INT32 BspDriverBleInit();
VEH_INT32 BspDriverBleSendMsg();
VEH_INT32 BspDriverBleRecvMsg();

#endif  // DRIVER_BLE_H_