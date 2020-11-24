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
/**
 * @file <stats.h>
 * @brief <collects prototype of statistical functions >
 *
 *
 *
 * @author <efrem e. ayichew, modified by>
 * @date <22NOV2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* void print_statestics(array)
   echo the contents of the array in a consol
*/
void print_array(unsigned char *, int);

// perform bubble sort of an array
void sort_array(unsigned char *array, int length);
//
void swapChar(unsigned char*, unsigned char*);
void print_statistics(unsigned char *, int);
void find_minimum(unsigned char *, int);
void find_maximum(unsigned char *, int);
void find_mean(unsigned char *, int );
void find_median(unsigned char *, int );



#endif /* __STATS_H__ */
