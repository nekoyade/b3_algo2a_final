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
    HeapSort(table, n, 'p', 'd');
    PrintCounters();

    //DisplayTable(table, n);
    printf("%d\n", CheckOrder(table, n, 'p', 'd'));
    printf("%d\n", CheckOrder(table, n, 'p', 'a'));
    printf("%d\n", CheckOrder(table, n, 'a', 'd'));
    printf("%d\n", CheckOrder(table, n, 'a', 'a'));
    printf("%d\n", CheckOrder(table, n, 'n', 'd'));
    printf("%d\n", CheckOrder(table, n, 'n', 'a'));

    free(table);
    return 0;
}
