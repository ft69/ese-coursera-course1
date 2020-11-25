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
 * @file <stats.c>
 * @brief <contains main function for computing stat >
 *
 * <Add Extended Description Here>
 *
 * @author <efrem e. ayichew, modified by>
 * @date <22NOV2020>
 *
 */

#include <stdio.h>
#include <math.h>

#include "stats.h"

// define a macro to calculate array size. Calculating an array size via
// function call is un-unsolved mystry, it looks like :)
#define ARRAY_SIZE( array ) ( sizeof( array ) / sizeof( array[0] ) )

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* calculating number of elements in an array is not straight forward in c :-) */
  //int NumberOfElements = sizeof(test)/sizeof(test[0]);
  int NumberOfElements = ARRAY_SIZE(test);

  // unsigned char *originalTest;
  // originalTest = test ; // save initial array if needed

  printf(" \n ********** Array before sorting :\n \n");
  print_array(test, NumberOfElements);

  //override the original array with a sorted array and print
  sort_array(test,NumberOfElements)  ;
  printf("\n ********** Array after sorting :\n \n");
  print_array(test, NumberOfElements);

  print_statistics(test,NumberOfElements);

  //print_statistics(test);
  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
}

void print_statistics(unsigned char *sortedArray,int length){
   // - A function that prints the statistics of an array including
   // minimum, maximum, mean, and median.

   // pass pointer to the sorted array; no min/max search required
   find_minimum(&sortedArray[0],length);
   find_maximum(&sortedArray[0],length);
   find_mean(&sortedArray[0]   ,length);
   find_median(&sortedArray[0] ,length);
   printf("\n \n");
}

void  print_array(unsigned char *array, int NumberOfElements) {
    	//- Given an array of data and a length, prints the array to the screen
      // it is a display only funciton and has no return value
      for(int i = 0; i < NumberOfElements; i++)
        printf("%d ", array[i]);
      printf("\n ");
}

void find_median(unsigned char *array, int NumberOfElements){
	// - Given an array of data and a length, returns the median value
  //
  printf("number of elements in the array is :");
  printf("%d",NumberOfElements);
  printf("\n");
  unsigned int isEven = (NumberOfElements % 2 == 0);
  if(isEven){
    printf("... since the the number of elements are even, there are potentially two medians and they also could be same numbers.");
    printf("\n");
    unsigned int halfway = ceil(NumberOfElements/2) ;
    //printf("\n %d", halfway);
    printf("...first median : ");
    printf("%d",array[halfway-1] );
    printf("\n");
    printf("...second median: ");
    printf("%d",array[halfway]);
    printf("\n");
  }
  else {
    printf("... since the the number of elements are odd, there is one  : ");
    printf("\n");
    int halfway = (NumberOfElements/2.0) ;
    printf("...median : ");
    printf("%d",array[halfway]);
    printf("\n");
  }

}
void find_mean(unsigned char *array, int NumberOfElements){
  int sum = 0;
  for (int i=0;i<NumberOfElements;i++){
    // cast into int from char type required to do accurate arithimetic
    sum = sum + (int) array[i];
  }
  float avg = sum/NumberOfElements;
  printf("Mean : ");
  printf("%F ",avg);
  printf("\n ");
}


void  find_minimum(unsigned char *sortedOutArray, int length) {
	//- Given an array of data and a length, returns the minimum
  // the passed array is sorted

  // since the array passed in sorted in descending order, the min and max locaiton is trivial
  printf("\n");
  printf("Minimum :");
  printf("%d ",sortedOutArray[length-1]);
  printf("\n");
}

void  find_maximum(unsigned char *sortedOutArray, int length) {
	//- Given an array of data and a length, returns the minimum
  // the passed array is sorted. Since the array passed in sorted in
  // descending order, the min and max locaiton is trivial
  printf("\n \n");
  printf("Maximum :");
  printf("%d ",sortedOutArray[0]);
  printf("\n \n");
}

void sort_array(unsigned char *array, int length) {
  // requirement
  //- Given an array of data and a length, sorts the array from largest to 	smallest.
  // (The zeroth Element should be the largest value, and the last element (n-1)
  // should be the smallest value.)

  // the below routine performs bubble sort. The highest value will bubbled
  // out to the top. Full array search will be done for first place and
  // subsequent searches will have one less search than the one before
  // since the preceeding memeber is established, the next search will take
  // place below it

  unsigned char charBuff ; // buffer to hold swapped value
  for (int i=0;i<length;i++){ // rank loop
   for(int j = i+1; j < length; j++){ // search loop
     swapChar(&array[i],&array[j]);
      /* if(array[i]< array[j]){ charBuff = array[i]; array[i] = array[j];  array[j] = charBuff;   } */
    }
  }
}

void swapChar(unsigned char *a, unsigned char *b){
  // this function swaps the place of two values if the first is less than
  // the second. It is called by a sort function to bubble larger values to the top
  // candidate numbers are passed by reference, hence no return value is required
  unsigned char Buff ; // buffer to hold swapped value
  if(*a<*b){
    Buff = *a;
    *a   = *b;
    *b   = Buff;
  }
}
