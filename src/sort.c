/*  Project Name    : A2AF
 *  File Name       : sort.c
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 *  Used sample codes in Algorithm 2A lectures as a reference.
 *
 */

#include "sort.h"

#include <stdlib.h>

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

void MergeSortImpl_(
        struct City* table, int left, int right, struct City* work,
        char mode, char order) {
    if (left >= right) {
        return;
    }
    int center = left + (right - left)/2;
    MergeSortImpl_(table, left, center, work, mode, order);
    MergeSortImpl_(table, center + 1, right, work, mode, order);
    int i, num;
    for (i = left, num = 0; i <= center; ++i) {
        Copy_(&table[i], &work[num++]);
    }
    int j = 0;
    int base = left;
    while ((i <= right) && (j < num)) {
        if (Compare_(&work[j], &table[i], mode, order) == 1) {
            Copy_(&table[i++], &table[base++]);
        } else {
            Copy_(&work[j++], &table[base++]);
        }
    }
    while (j < num) {
        Copy_(&work[j++], &table[base++]);
    }
}

void MergeSort(struct City* table, int n, char mode, char order) {
    struct City* work = malloc(sizeof(struct City)*n);
    if (work == NULL) {
        printf("ERROR: Could not allocate memory.\n");
        free(table);
        exit(1);
    }
    MergeSortImpl_(table, 0, n - 1, work, mode, order);
    free(work);
}

void HeapSortImpl_(
        struct City* table, int left, int right, char mode, char order) {
    struct City root;
    Copy_(&table[left], &root);
    int parent, child;
    for (parent = left; parent < (right + 1)/2; parent = child) {
        int l = 2*parent + 1;
        int r = l + 1;
        if ((r <= right) && (Compare_(
                &table[r], &table[l], mode, order) == 1)) {
            child = r;
        } else {
            child = l;
        }
        if (Compare_(&root, &table[child], mode, order) == 1) {
            break;
        }
        Copy_(&table[child], &table[parent]);
    }
    Copy_(&root, &table[parent]);
}

void HeapSort(struct City* table, int n, char mode, char order) {
    for (int i = n/2 - 1; i >= 0; --i) {
        HeapSortImpl_(table, i, n - 1, mode, order);
    }
    for (int i = n - 1; i > 0; --i) {
        Swap_(&table[0], &table[i]);
        HeapSortImpl_(table, 0, i - 1, mode, order);
    }
}

int CheckOrder(struct City* table, int n, char mode, char order) {
    for (int i = 1; i < n; ++i) {
        if (Compare_(&table[i - 1], &table[i], mode, order) == 1) {
            float a_val, b_val;
            switch (mode) {
            case 'a':
                a_val = table[i - 1].lat;
                b_val = table[i].lat;
                break;
            case 'n':
                a_val = table[i - 1].lng;
                b_val = table[i].lng;
                break;
            case 'p':
            default:
                a_val = table[i - 1].pop;
                b_val = table[i].pop;
                break;
            }
            printf("    Fault!  ");
            printf("%f (idx: %d)  ", a_val, i - 1);
            printf("%f (idx: %d)\n", b_val, i);
            return 0;
        }
    }
    return 1;
}
