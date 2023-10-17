/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#ifndef CLIENT_H_
#define CLIENT_H_

#include "public.h"

#define VEH_CLIENT_INPUT_STRING_LEN_MAX 128
#define VEH_CLIENT_CMD_NUM_MAX          64
#define VEH_CLIENT_CMD_ARGC_MAX         8
#define VEH_CLIENT_CMD_ARGV_MAX         16

struct VehClientCmd {
    VEH_CHAR cmd[VEH_CLIENT_INPUT_STRING_LEN_MAX];
    VEH_CHAR desc[VEH_CLIENT_INPUT_STRING_LEN_MAX];
    void (*func)(VEH_CHAR **);
};

VEH_INT32 VehClientInit();
extern struct VehClientCmd g_vehClientCmdList[VEH_CLIENT_CMD_NUM_MAX];

#endif  // CLIENT_H_