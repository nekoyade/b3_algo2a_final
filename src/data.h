/*  Project Name    : A2AF
 *  File Name       : data.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2AF_DATA_H_
#define A2AF_DATA_H_

// just for debugging
#include <stdio.h>

#define BUF_SIZE 240

#define CITY_NAME_SIZE 32

struct City {
    int pop;                    // population
    char name[CITY_NAME_SIZE];  // city_ascii
};

// just for debugging
int CountNumOfRecords_(FILE* fp);

#endif  // A2AF_DATA_H_
