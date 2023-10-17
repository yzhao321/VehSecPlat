/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#include "driver_ble.h"
#include "public.h"

VEH_INT32 BspDriverBleInit() {
    return VEH_OK;
}

VEH_INT32 BspDriverBleSendMsg() {
    // TODO
    VehTermPrint("Bsp Ble send Msg\n");
    return VEH_OK;
}

VEH_INT32 BspDriverBleRecvMsg() {
    return VEH_OK;
}