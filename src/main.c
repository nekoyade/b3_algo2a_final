/*  Project Name    : A2AF
 *  File Name       : main.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "sort.h"

int main() {
    char filename[] = "data/worldcities.csv";

    struct City* table = NULL;
    int n = 0;

    ReadData(&table, &n, filename);

    ClearCounters();
    PrintCounters();
    Compare_(&table[0], &table[1], 'p', 'a');
    Swap_(&table[0], &table[1]);
    Copy_(&table[0], &table[1]);
    PrintCounters();
    ClearCounters();
    PrintCounters();

    free(table);
    return 0;
}
