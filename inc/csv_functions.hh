#ifndef CSV_FUNCTIONS_HH
#define CSV_FUNCTIONS_HH

#include "rapidcsv.h"
#include "sequence.hh"
#include "exceptions.hh"
#include <string>

void uploadFileIntoSequence(Sequence *Seq, rapidcsv::Document doc);              /* Funkcja odpowiadająca za dodanie pliku do sekwencji */
void uploadFileIntoSequence(Sequence *Seq, rapidcsv::Document doc, int rozmiar); /* Funkcja odpowiadająca za dodanie pliku o określonym rozmiarze do sekwencji */
void DeleteInvalid(Sequence *Seq);                                               /* Funkcja odpowiadająca za usunięcie błędnych pliku */

#endif