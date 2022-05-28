#ifndef CSV_FUNCTION_HH
#define CSV_FUNCTION_HH

#include "rapidcsv.h"
#include "sequence.hh"
#include "exceptions.hh"
#include <string>

void uploadFileIntoSequence(sequence *seq, rapidcsv::Document doc);           /* Funkcja odpowiadająca za dodanie pliku do sekwencji */
void uploadFileIntoSequence(sequence *seq, rapidcsv::Document doc, int size); /* Funkcja odpowiadająca za dodanie pliku o określonym rozmiarze do sekwencji */
void DeleteInvalid(sequence *seq);                                            /* Funkcja odpowiadająca za usunięcie błędnych pliku */

#endif