#pragma once
#ifndef _KSDK_PATCHING_H
#define _KSDK_PATCHING_H
#include "ksdk.h"

void init_505_ksdk(uint8_t* kbase);
void init_672_ksdk(uint8_t* kbase);
void init_702_ksdk(uint8_t* kbase);
void init_755_ksdk(uint8_t* kbase);

#endif