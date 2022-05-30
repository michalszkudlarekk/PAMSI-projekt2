#include "csv_functions.hh"
#include <chrono>
#include "sorting_algorithms.hh"

using namespace std;
using namespace chrono;

int main()
{

     Sequence MainSequence;
     /*Dane z eportalu zostały zedytowane w celu wykonania pomiarów dla wartości większych od 400k */
     rapidcsv::Document doc("./projekt2_dane.CNGRDs-i.csv", rapidcsv::LabelParams(0, 0), rapidcsv::SeparatorParams(),
                            rapidcsv::ConverterParams(true));

     uploadFileIntoSequence(&MainSequence, doc);

     auto start = high_resolution_clock::now();
     DeleteInvalid(&MainSequence);
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas filtrowania:" << duration.count() << " milisekund." << endl;

     Sequence _10kSequenceMerge(MainSequence, 10000);
     cout << "Wyniki dla 10 000 danych:\n"
          << endl;

     start = high_resolution_clock::now();
     mergeSort(_10kSequenceMerge);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
     if (_10kSequenceMerge.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _10kSequenceQuick(MainSequence, 10000);

     start = high_resolution_clock::now();
     QuickSort(_10kSequenceQuick);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
     if (_10kSequenceQuick.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _10kSequenceBucket(MainSequence, 10000);

     start = high_resolution_clock::now();
     bucketSort(_10kSequenceBucket);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
     if (_10kSequenceBucket.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     cout << endl;

     cout << "Srednia arytmetyczna wynosi: " << _10kSequenceBucket.average() << endl;
     cout << "Mediana wynosi:" << _10kSequenceBucket.medium() << endl;

     cout << "Wyniki dla 100 000 danych:\n"
          << endl;

     Sequence _100kSequenceMerge(MainSequence, 100000);

     start = high_resolution_clock::now();
     mergeSort(_100kSequenceMerge);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
     if (_100kSequenceMerge.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _100kSequenceQuick(MainSequence, 100000);

     start = high_resolution_clock::now();
     QuickSort(_100kSequenceQuick);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
     if (_100kSequenceQuick.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _100kSequenceBucket(MainSequence, 100000);

     start = high_resolution_clock::now();
     bucketSort(_100kSequenceBucket);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
     if (_100kSequenceBucket.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     cout << endl;

     cout << "Srednia arytmetyczna wynosi: " << _100kSequenceBucket.average() << endl;
     cout << "Mediana wynosi:" << _100kSequenceBucket.medium() << endl;

     cout << "Wyniki dla 500 000 danych:\n"
          << endl;

     Sequence _500kSequenceMerge(MainSequence, 500000);

     start = high_resolution_clock::now();
     mergeSort(_500kSequenceMerge);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
     if (_500kSequenceMerge.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _500kSequenceQuick(MainSequence, 500000);

     start = high_resolution_clock::now();
     QuickSort(_500kSequenceQuick);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
     if (_500kSequenceQuick.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _500kSequenceBucket(MainSequence, 500000);

     start = high_resolution_clock::now();
     bucketSort(_500kSequenceBucket);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
     if (_500kSequenceBucket.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     cout << endl;

     cout << "Srednia arytmetyczna wynosi: " << _500kSequenceBucket.average() << endl;
     cout << "Mediana wynosi:" << _500kSequenceBucket.medium() << endl;

     cout << "Wyniki dla 750 000 danych:\n"
          << endl;

     Sequence _750kSequenceMerge(MainSequence, 750000);

     start = high_resolution_clock::now();
     mergeSort(_750kSequenceMerge);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania przez scalanie:" << duration.count() << "milisekund." << endl;
     if (_750kSequenceMerge.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _750kSequenceQuick(MainSequence, 750000);

     start = high_resolution_clock::now();
     QuickSort(_750kSequenceQuick);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania QuickSort:" << duration.count() << "milisekund." << endl;
     if (_750kSequenceQuick.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _750kSequenceBucket(MainSequence, 750000);

     start = high_resolution_clock::now();
     bucketSort(_750kSequenceBucket);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania kubelkowego:" << duration.count() << "milisekund." << endl;
     if (_750kSequenceBucket.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     cout << endl;

     cout << "Srednia arytmetyczna wynosi: " << _750kSequenceBucket.average() << endl;
     cout << "Mediana wynosi:" << _750kSequenceBucket.medium() << endl;

     cout << "Wyniki dla maksymalnej liczby danych:\n"
          << endl;

     Sequence _1000kSequenceMerge(MainSequence);

     start = high_resolution_clock::now();
     mergeSort(_1000kSequenceMerge);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania przez scalanie:" << duration.count() << "milisekund." << endl;
     if (_1000kSequenceMerge.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _1000kSequenceQuick(MainSequence);

     start = high_resolution_clock::now();
     QuickSort(_1000kSequenceQuick);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania QuickSort:" << duration.count() << "milisekund." << endl;
     if (_1000kSequenceQuick.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     Sequence _1000kSequenceBucket(MainSequence);

     start = high_resolution_clock::now();
     bucketSort(_1000kSequenceBucket);
     stop = high_resolution_clock::now();
     duration = duration_cast<milliseconds>(stop - start);
     cout << "Czas sortowania kubełkowego:" << duration.count() << "milisekund." << endl;
     if (_1000kSequenceBucket.isSorted())
          cout << "Sortowanie wykonane poprawnie.\n"
               << endl;

     cout << endl;

     cout << "Srednia arytmetyczna wynosi: " << _1000kSequenceBucket.average() << endl;
     cout << "Mediana wynosi:" << _1000kSequenceBucket.medium() << endl;

     return 0;
}