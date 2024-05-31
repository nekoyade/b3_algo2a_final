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

    for (int i = 0; i < 3; ++i) {
        PrintCity(&table[i]);
    }
    Copy_(&table[0], &table[1]);
    for (int i = 0; i < 3; ++i) {
        PrintCity(&table[i]);
    }

    free(table);
    return 0;
}
