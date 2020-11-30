/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
#ifndef __PLATFORM_H__
#define __PLATFORM_H__ ;
//#define PRINTF(...)  printf((f_),##__VA_ARGS__);
//#define PRINTF(f_,...)  printf((f_),##__VA_ARGS__);
/******************************************************************************
 Platform - MSP432
******************************************************************************/
#ifdef MSP432
include "msp432p401r.h"
#define PRINTF(f_,...)  ();
#endif
/******************************************************************************
 Platform - HOST
******************************************************************************/
#ifndef HOST
#include <stdio.h>
#define PRINTF(f_,...) printf((f_),##__VA_ARGS__ );
//printf("%s\n", "HOST");
#endif
/******************************************************************************
 Platform - Unsupported
******************************************************************************/
#else
 #error "Platform provided is not supported in this Build System";

#endif /* __PLATFORM_H__ */
