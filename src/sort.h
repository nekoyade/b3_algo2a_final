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
void PrintCounters();

// just for debugging
int Compare_(
        struct City const* a, struct City const* b, char mode, char order);
void Swap_(struct City* a, struct City* b);
void Copy_(struct City const* src, struct City* dst);

#endif  // A2AF_SORT_H_
