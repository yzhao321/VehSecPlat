/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#ifndef COMM_CAN_H_
#define COMM_CAN_H_

#include "public.h"

VEH_INT32 VehCommCanInit();
VEH_INT32 VehCommCanSendMsg();
VEH_INT32 VehCommCanRecvMsg();

#endif  // COMM_CAN_H_