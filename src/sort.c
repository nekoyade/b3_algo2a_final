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

void PrintCounters() {
    printf("  Compare: %d", comp_counter);
    printf("  Swap: %d", swap_counter);
    printf("  Copy: %d\n", copy_counter);
}

int Compare_(
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

void Swap_(struct City* a, struct City* b) {
    ++swap_counter;
    copy_counter += 3;
    struct City tmp = *a;
    *a = *b;
    *b = tmp;
}

void Copy_(struct City const* src, struct City* dst) {
    ++copy_counter;
    *dst = *src;
}

void BubbleSort(struct City* table, int n, char mode, char order) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (Compare_(&table[j - 1], &table[j], mode, order) == 1) {
                Swap_(&table[j - 1], &table[j]);
            }
        }
    }
}

void SelectionSort(struct City* table, int n, char mode, char order) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (Compare_(&table[min_idx], &table[j], mode, order) == 1) {
                min_idx = j;
            }
        }
        Swap_(&table[i], &table[min_idx]);
    }
}

void InsertionSort(struct City* table, int n, char mode, char order) {
    for (int i = 1; i < n; ++i) {
        int j = i;
        while ((j >= 1) && (Compare_(
                &table[j - 1], &table[j], mode, order) == 1)) {
            Swap_(&table[j - 1], &table[j]);
            --j;
        }
    }
}

void ShellSort(struct City* table, int n, char mode, char order) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; ++i) {
            int j = i;
            while ((j >= gap) && (Compare_(
                    &table[j - gap], &table[j], mode, order) == 1)) {
                Swap_(&table[j - gap], &table[j]);
                j -= gap;
            }
        }
        gap /= 2;
    }
}

void QuickSortImpl_(
        struct City* table, int left, int right, char mode, char order) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    struct City pivot;
    Copy_(&table[i + (j - i)/2], &pivot);
    do {
        while (Compare_(&table[i], &pivot, mode, order) == -1) { ++i; }
        while (Compare_(&table[j], &pivot, mode, order) ==  1) { --j; }
        if (i <= j) {
            Swap_(&table[i], &table[j]);
            ++i;
            --j;
        }
    } while (i <= j);
    QuickSortImpl_(table, left, j, mode, order);
    QuickSortImpl_(table, i, right, mode, order);
}

void QuickSort(struct City* table, int n, char mode, char order) {
    QuickSortImpl_(table, 0, n - 1, mode, order);
}
