/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#include "comm_ble.h"
#include "public.h"
#include "driver_ble.h"

VEH_INT32 VehCommBleInit() {
    return VEH_OK;
}

VEH_INT32 VehCommBleSendMsg() {
    VehTermPrint("Veh Comm Ble Send Msg\n");
    BspDriverBleSendMsg();
    return VEH_OK;
}

VEH_INT32 VehCommBleRecvMsg() {
    return VEH_OK;
}
