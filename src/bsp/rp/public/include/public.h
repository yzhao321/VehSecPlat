/****************************************************************************

Vehicle Security Platform

Copyright 2023, UCSC, ZJU, SCUT.
All rights reserved.

Author: Yinyuan Zhao.

****************************************************************************/

#ifndef PUBLIC_H_
#define PUBLIC_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define VEH_INT32       int
#define VEH_INT16       short
#define VEH_UINT32      unsigned int
#define VEH_UINT16      unsigned short
#define VEH_CHAR        char
#define VEH_OK          0
#define VEH_ERR         1
#define VEH_TRUE        true
#define VEH_FALSE       false

// Terminal IO
#define VehTermPrint        printf
#define VehTermGet          getchar

// Task
#define VehTask             pthread_t
#define VehTaskCreate       pthread_create
#define VehTaskJoin         pthread_join

// Memory
#define VehMemMalloc        malloc
#define VehMemFree          free

#endif  // PUBLIC_H_