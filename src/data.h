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
#define CTRY_NAME_SIZE 32  // country
#define ISO2_NAME_SIZE  3
#define ISO3_NAME_SIZE  4
#define ADMN_NAME_SIZE 32  // admin_name
#define CPTL_NAME_SIZE 32  // capital

struct City {
    char name[CITY_NAME_SIZE];     // city_ascii
    char country[ISO3_NAME_SIZE];  // iso3

    int pop;    // population
    float lat;  // latitude
    float lng;  // longitude
};

void PrintCity(struct City* city);

void ReadData(struct City** table, int* n, char filename[]);
void DisplayTable(struct City* table, int n);

#endif  // A2AF_DATA_H_
