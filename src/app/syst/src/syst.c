/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#include "syst.h"
#include "public.h"
#include "comm.h"
#include "service.h"
#include "client.h"

VEH_INT32 VehSystInitHardware() {
    // TODO
    return VEH_OK;
}

VEH_INT32 VehSystInitComm() {
    VEH_INT32 ret = VehCommInit();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Comm Err: 0x%x\n", ret);
        return ret;
    }
    return VEH_OK;
}

VEH_INT32 VehSystInitService() {
    VEH_INT32 ret = VehServiceInit();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Service Err: 0x%x\n", ret);
        return ret;
    }
    return VEH_OK;
}


VEH_INT32 VehSystInitClient() {
    VEH_INT32 ret = VehClientInit();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Client Err: 0x%x\n", ret);
        return ret;
    }
    return VEH_OK;
}

VEH_INT32 VehSystInit() {
    VEH_INT32 ret;

    ret = VehSystInitHardware();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Hardware Err: 0x%x\n", ret);
        return ret;
    }

    ret = VehSystInitComm();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Comm Err: 0x%x\n", ret);
        return ret;
    }

    ret = VehSystInitService();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Service Err: 0x%x\n", ret);
        return ret;
    }

    ret = VehSystInitClient();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Syst Init Client Err: 0x%x\n", ret);
        return ret;
    }

    return VEH_OK;
}

void VehSystRun() {
    VehTermPrint("Veh Syst Run\n");
    VehServiceRun();
    return;
}
