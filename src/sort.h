/*  Project Name    : A2AF
 *  File Name       : sort.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2AF_SORT_H_
#define A2AF_SORT_H_

#include "data.h"

void ClearCounters();

// just for debugging
int City_Compare_(
        struct City const* a, struct City const* b, char mode, char order);

#endif  // A2AF_SORT_H_
