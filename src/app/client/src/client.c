/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#include "client.h"
#include "public.h"
#include <string.h>

VEH_INT32 VehClientGetCmd(VEH_CHAR *inputString) {
    VEH_CHAR inputChar;
    VEH_INT32 i = 0;

    while ((inputChar = VehTermGet()) != '\n') {
        inputString[i++] = inputChar;
        if (i >= VEH_CLIENT_INPUT_STRING_LEN_MAX) {
            break;
        }
    }

    inputString[i] = '\0';

    return i;
}

enum VehClientSplitState {
    VEH_CLIENT_SPLIT_STATE_SPACE,
    VEH_CLIENT_SPLIT_STATE_CHAR,
};

VEH_INT32 VehClientSplitCmd(VEH_CHAR *inputString, VEH_INT32 len, VEH_CHAR **argv) {
    enum VehClientSplitState state = VEH_CLIENT_SPLIT_STATE_SPACE;
    VEH_INT32 argc = -1;
    VEH_INT32 cur = 0;

    for (int i = 0; i < len; i++) {
        switch (state) {
            case VEH_CLIENT_SPLIT_STATE_SPACE:
                if (inputString[i] != ' ') {
                    argc++;
                    cur = i;
                    state = VEH_CLIENT_SPLIT_STATE_CHAR;
                }
                break;

            case VEH_CLIENT_SPLIT_STATE_CHAR:
                if (inputString[i] == ' ') {
                    state = VEH_CLIENT_SPLIT_STATE_SPACE;
                    inputString[i] = '\0';
                    argv[argc] = inputString + cur;
                }
                break;

            default:
                break;
        }
    }

    argv[argc] = inputString + cur;
    return argc + 1;
}

void VehClientImplCmd(VEH_CHAR *inputString, VEH_INT32 len, VEH_CHAR **argv) {
    VEH_INT32 argc;

    argc = VehClientSplitCmd(inputString, len, argv);
    if (argc == 0) {
        return;
    }

    for (int i = 0; i < VEH_CLIENT_CMD_NUM_MAX; i++) {
        if (strcmp(g_vehClientCmdList[i].cmd, argv[0]) == 0) {
            g_vehClientCmdList[i].func(argv);
            return;
        }
        if (strcmp(g_vehClientCmdList[i].cmd, "NULL") == 0) {
            break;
        }
    }

    VehTermPrint("Invalid command. Use ? or help to get command list\n");
}

void *VehClientRun() {
    VEH_INT32 len = 0;
    VEH_CHAR inputString[VEH_CLIENT_INPUT_STRING_LEN_MAX] = {0};

    VEH_CHAR **argv = (VEH_CHAR **)VehMemMalloc(sizeof(VEH_CHAR *) * VEH_CLIENT_CMD_ARGC_MAX);
    for (int i = 0; i < VEH_CLIENT_CMD_ARGC_MAX; i++) {
        argv[i] = (VEH_CHAR *)VehMemMalloc(sizeof(VEH_CHAR *) * VEH_CLIENT_CMD_ARGV_MAX);
    }

    while (VEH_TRUE) {
        VehTermPrint("VEH SHELL:/>> ");
        len = VehClientGetCmd(inputString);
        VehClientImplCmd(inputString, len, argv);
    }

    for (int i = 0; i < VEH_CLIENT_CMD_ARGC_MAX; i++) {
        VehMemFree(argv[i]);
    }
    VehMemFree(argv);
}

VEH_INT32 VehClientInitHardware() {
    return VEH_OK;
}

VEH_INT32 VehClientInitTask() {
    VEH_INT32 ret;
    VehTask vehClientTask;

    ret = VehTaskCreate(&vehClientTask, NULL, VehClientRun, NULL);
    if (ret != VEH_OK) {
        VehTermPrint("Veh Client Create Task Err: 0x%x\n", ret);
        return ret;
    }

    VehTermPrint("Veh Client Create Task Succ\n");
    VehTaskJoin(vehClientTask, NULL);

    return VEH_OK;
}

VEH_INT32 VehClientInit() {
    VEH_INT32 ret;

    ret = VehClientInitHardware();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Client Init Hardware Err: 0x%x\n", ret);
        return ret;
    }

    ret = VehClientInitTask();
    if (ret != VEH_OK) {
        VehTermPrint("Veh Client Init Task Err: 0x%x\n", ret);
        return ret;
    }

    return VEH_OK;
}
