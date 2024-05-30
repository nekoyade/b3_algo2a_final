/*  Project Name    : A2AF
 *  File Name       : data.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2AF_DATA_H_
#define A2AF_DATA_H_

#define CITY_NAME_SIZE 32

struct City {
    int pop;                    // population
    char name[CITY_NAME_SIZE];  // city_ascii
};

#endif  // A2AF_DATA_H_
