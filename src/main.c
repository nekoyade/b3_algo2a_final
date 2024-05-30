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
    FILE* fp = fopen("data/worldcities.csv", "r");
    if (fp == NULL) {
        printf("ERROR: Could not open the file.\n");
        exit(1);
    }
    printf("n=%d\n", CountNumOfRecords_(fp));
    fclose(fp);

    return 0;
}
