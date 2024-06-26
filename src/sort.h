/*  Project Name    : A2AF
 *  File Name       : sort.h
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#ifndef A2AF_SORT_H_
#define A2AF_SORT_H_

#include "data.h"

void ClearCounters();
void PrintCounters();

void BubbleSort(struct City* table, int n, char mode, char order);
void SelectionSort(struct City* table, int n, char mode, char order);
void InsertionSort(struct City* table, int n, char mode, char order);
void ShellSort(struct City* table, int n, char mode, char order);
void QuickSort(struct City* table, int n, char mode, char order);
void MergeSort(struct City* table, int n, char mode, char order);
void HeapSort(struct City* table, int n, char mode, char order);

int CheckOrder(struct City* table, int n, char mode, char order);

void ShuffleTable(struct City* table, int n, unsigned int seed);

#endif  // A2AF_SORT_H_
