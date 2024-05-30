/*  Project Name    : A2AF
 *  File Name       : data.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "data.h"

#include <stdio.h>

int CountNumOfRecords_(FILE* fp) {
    int n = 0;
    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, fp) != NULL) {
        ++n;
    }
    return n - 1;
}
