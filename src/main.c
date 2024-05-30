/*  Project Name    : A2AF
 *  File Name       : main.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "data.h"

int main() {
    char filename[] = "data/worldcities.csv";

    struct City* table = NULL;
    int n = 0;

    ReadData(&table, &n, filename);

    for (int i = 0; i < 4; ++i) {
        printf("%s %d\n", table[i].name, table[i].pop);
    }
    printf("n=%d\n", n);

    free(table);
    return 0;
}
