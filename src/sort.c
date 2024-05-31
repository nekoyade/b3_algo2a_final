/*  Project Name    : A2AF
 *  File Name       : sort.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "sort.h"

#include "data.h"

int comp_counter = 0;
int swap_counter = 0;
int copy_counter = 0;

void ClearCounters() {
    comp_counter = 0;
    swap_counter = 0;
    copy_counter = 0;
}

int City_Compare_(
        struct City const* a, struct City const* b, char mode, char order) {
    ++comp_counter;
    float a_val, b_val;
    switch (mode) {
    case 'a':
        a_val = a->lat;
        b_val = b->lat;
        break;
    case 'n':
        a_val = a->lng;
        b_val = b->lng;
        break;
    case 'p':
    default:
        a_val = a->pop;
        b_val = b->pop;
        break;
    }
    int result = a_val > b_val ?  1 : a_val < b_val ? -1 : 0;
    switch (order) {
    case 'd':
        result *= -1;
        break;
    case 'a':
    default:
        break;
    }
    return result;
}
