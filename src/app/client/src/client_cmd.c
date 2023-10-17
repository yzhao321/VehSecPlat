/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#include "client.h"

#include "public.h"
#include <string.h>

#include "service_dos_basic.h"

void VehClientHelp(VEH_CHAR **argv) {
    VehTermPrint("================================================\n");
    for (int i = 0; i < VEH_CLIENT_CMD_NUM_MAX; i++) {
        if (strcmp(g_vehClientCmdList[i].cmd, "NULL") == 0) {
            break;
        }
        VehTermPrint("%s\t\t\t", g_vehClientCmdList[i].cmd);
        VehTermPrint("%s\n", g_vehClientCmdList[i].desc);
    }
    VehTermPrint("================================================\n");
}

void VehClientDosTest(VEH_CHAR **argv) {
    VehTermPrint("Veh Client Dos Test Print\n");
    VehServiceDosBasic();
}

struct VehClientCmd g_vehClientCmdList[VEH_CLIENT_CMD_NUM_MAX] = {
    { "?",          "show client cmd",              VehClientHelp           },
    { "help",       "show client cmd",              VehClientHelp           },
    { "DosTest",    "test dos attck",               VehClientDosTest        },
    { "NULL",       "NULL",                         NULL                    },
};