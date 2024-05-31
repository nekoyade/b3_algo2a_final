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

    for (int i = 0; i < 2; ++i) {
        PrintCity(&table[i]);
    }
    printf("%d\n", City_Compare_(&table[0], &table[1], 'p', 'a'));
    printf("%d\n", City_Compare_(&table[0], &table[1], 'p', 'd'));
    printf("%d\n", City_Compare_(&table[0], &table[1], 'a', 'a'));
    printf("%d\n", City_Compare_(&table[0], &table[1], 'a', 'd'));
    printf("%d\n", City_Compare_(&table[0], &table[1], 'n', 'a'));
    printf("%d\n", City_Compare_(&table[0], &table[1], 'n', 'd'));

    free(table);
    return 0;
}
