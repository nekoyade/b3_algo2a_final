/*  Project Name    : A2AF
 *  File Name       : data.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "data.h"

#include <stdio.h>
#include <stdlib.h>

int CountNumOfRecords_(FILE* fp) {
    int n = 0;
    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, fp) != NULL) {
        ++n;
    }
    return n - 1;
}

void ReadData(struct City** table, int* n, char filename[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: Could not open %s.\n", filename);
        exit(1);
    }
    *n = CountNumOfRecords_(fp);
    *table = malloc(sizeof(struct City)*(*n));
    if (*table == NULL) {
        printf("ERROR: Could not allocate memory.\n");
        fclose(fp);
        exit(1);
    }
    // ...
    fclose(fp);
}
