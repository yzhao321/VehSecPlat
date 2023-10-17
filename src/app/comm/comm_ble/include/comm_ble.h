/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#ifndef COMM_BLE_H_
#define COMM_BLE_H_

#include "public.h"

VEH_INT32 VehCommBleInit();
VEH_INT32 VehCommBleSendMsg();
VEH_INT32 VehCommBleRecvMsg();

#endif  // COMM_BLE_H_