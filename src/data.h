/*  Project Name    : A2AF
 *  File Name       : data.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2AF_DATA_H_
#define A2AF_DATA_H_

#include <stdio.h>

#define BUF_SIZE 240

#define CITY_NAME_SIZE 32

struct City {
    char name[CITY_NAME_SIZE];  // city_ascii
    int pop;                    // population
};

void ReadData(struct City** table, int* n, char filename[]);

#endif  // A2AF_DATA_H_
