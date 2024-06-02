/*  Project Name    : A2AF
 *  File Name       : main.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "data.h"
#include "sort.h"

double MeasureSortingTime(
        struct City* table, int n,
        void (*sort)(struct City*, int, char, char),
        char mode, char order, int trials) {
    double sec = 0.0;
    struct timeval start_time, end_time;
    for (int i = 0; i < trials; ++i) {
        // Shuffle the table
        QuickSort(table, n, 'p', 'd');
        ShuffleTable(table, n, 1u);

        // Measure sorting time
        gettimeofday(&start_time, NULL);
        sort(table, n, mode, order);
        gettimeofday(&end_time, NULL);
        sec += (
            (end_time.tv_sec - start_time.tv_sec)
            + (end_time.tv_usec - start_time.tv_usec)/1000000.0
        );
    }
    return sec/trials;
}

void SaveSortingTime(
        struct City* table, int n,
        void (*sort)(struct City*, int, char, char),
        char mode, char order, int trials, char caption[]) {
    char filename[BUF_SIZE];
    sprintf(filename, "out/%s_%c%c_%02d.csv", caption, mode, order, trials);
    FILE* fp = fopen(filename, "w");
    int k = 10;
    double sec;
    while (1) {
        if (k > n) {
            k = n;
        }
        sec = MeasureSortingTime(table, k, sort, mode, order, trials);
        fprintf(fp, "%d,%.9f\n", k, sec);
        if (k >= n) {
            break;
        }
        k *= 10;
    }
    fclose(fp);
}

int main() {
    char filename[] = "data/worldcities.csv";

    struct City* table = NULL;
    int n = 0;

    ReadData(&table, &n, filename);

    SaveSortingTime(table, n, QuickSort, 'p', 'd', 3, "quick");

    free(table);
    return 0;
}
