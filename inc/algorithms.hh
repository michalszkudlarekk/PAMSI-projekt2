#ifndef ALGORITHM_HH
#define ALGORITHM_HH

#include "sequence.hh"
#include <cmath>

bool isLess(element a, element b);                   /* Sprawdzenie wielkosci elementu*/
void merge(sequence &S, sequence &S1, sequence &S2); /* Scalanie potrzebne do sortowania przez scalanie */
void mergeSort(sequence &S);                         /* Sortowanie przez scalanie */
void quickSort(sequence &S);                         /* Sortowanie szybkie */
void bucketSort(sequence &S);                        /* Sortowanie kubełkowe */

#endif