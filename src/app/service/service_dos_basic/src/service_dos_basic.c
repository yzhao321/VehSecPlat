/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#include "service_dos_basic.h"

#include "public.h"
#include "comm_ble.h"

void VehServiceDosBasic() {
    VehCommBleSendMsg();
}