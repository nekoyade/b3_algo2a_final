/*  Project Name    : A2AF
 *  File Name       : sort.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "sort.h"

int comp_counter = 0;
int swap_counter = 0;
int copy_counter = 0;

void ClearCounters() {
    comp_counter = 0;
    swap_counter = 0;
    copy_counter = 0;
}
