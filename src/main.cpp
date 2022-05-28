#include "csv_function.hh"
#include "algorithms.hh"
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{

    sequence MainSequence;

    rapidcsv::Document doc("./projekt2_dane_eportal.csv", rapidcsv::LabelParams(0, 0), rapidcsv::SeparatorParams(),
                           rapidcsv::ConverterParams(true));

    uploadFileIntoSequence(&MainSequence, doc);

    auto start = high_resolution_clock::now();
    DeleteInvalid(&MainSequence);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas filtrowania:" << duration.count() << " milisekund." << endl;

    Sequence _10kSequenceMerge(MainSequence, 10000);
    cout << "10 000 danych:\n"
         << endl;

    start = high_resolution_clock::now();
    mergeSort(_10kSequenceMerge);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
    if (_10kSequenceMerge.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _10kSequenceQuick(MainSequence, 10000);

    start = high_resolution_clock::now();
    QuickSort(_10kSequenceQuick);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
    if (_10kSequenceQuick.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _10kSequenceBucket(MainSequence, 10000);

    start = high_resolution_clock::now();
    bucketSort(_10kSequenceBucket);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
    if (_10kSequenceBucket.isSorted())
        cout << "Posortowano.\n"
             << endl;

    cout << endl;

    cout << "Srednia arytmetyczna: " << _10kSequenceBucket.average() << endl;
    cout << "Mediana :" << _10kSequenceBucket.medium() << endl;

    cout << "100 000 danych:\n"
         << endl;

    Sequence _100kSequenceMerge(MainSequence, 100000);

    start = high_resolution_clock::now();
    mergeSort(_100kSequenceMerge);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
    if (_100kSequenceMerge.isSorted())
        cout << "Jest posortowana.\n"
             << endl;

    Sequence _100kSequenceQuick(MainSequence, 100000);

    start = high_resolution_clock::now();
    QuickSort(_100kSequenceQuick);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
    if (_100kSequenceQuick.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _100kSequenceBucket(MainSequence, 100000);

    start = high_resolution_clock::now();
    bucketSort(_100kSequenceBucket);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
    if (_100kSequenceBucket.isSorted())
        cout << "Posortowano.\n"
             << endl;

    cout << endl;

    cout << "Srednia arytmetyczna: " << _100kSequenceBucket.average() << endl;
    cout << "Mediana :" << _100kSequenceBucket.medium() << endl;

    cout << "250 000 danych:\n"
         << endl;

    Sequence _250kSequenceMerge(MainSequence, 250000);

    start = high_resolution_clock::now();
    mergeSort(_250kSequenceMerge);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
    if (_250kSequenceMerge.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _250kSequenceQuick(MainSequence, 250000);

    start = high_resolution_clock::now();
    QuickSort(_250kSequenceQuick);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
    if (_250kSequenceQuick.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _250kSequenceBucket(MainSequence, 250000);

    start = high_resolution_clock::now();
    bucketSort(_250kSequenceBucket);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
    if (_250kSequenceBucket.isSorted())
        cout << "Posortowano.\n"
             << endl;

    cout << endl;

    cout << "Srednia arytmetyczna: " << _250kSequenceBucket.average() << endl;
    cout << "Mediana :" << _250kSequenceBucket.medium() << endl;

    cout << "400 000 danych:\n"
         << endl;

    Sequence _400kSequenceMerge(MainSequence, 400000);

    start = high_resolution_clock::now();
    mergeSort(_400kSequenceMerge);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania przez scalanie:" << duration.count() << " milisekund." << endl;
    if (_400kSequenceMerge.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _400kSequenceQuick(MainSequence, 400000);

    start = high_resolution_clock::now();
    QuickSort(_400kSequenceQuick);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania QuickSort:" << duration.count() << " milisekund." << endl;
    if (_400kSequenceQuick.isSorted())
        cout << "Posortowano.\n"
             << endl;

    Sequence _400kSequenceBucket(MainSequence, 400000);

    start = high_resolution_clock::now();
    bucketSort(_400kSequenceBucket);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Czas sortowania kubelkowego:" << duration.count() << " milisekund." << endl;
    if (_400kSequenceBucket.isSorted())
        cout << "Posortowano.\n"
             << endl;

    cout << endl;

    cout << "Srednia arytmetyczna: " << _400kSequenceBucket.average() << endl;
    cout << "Mediana :" << _400kSequenceBucket.medium() << endl;

    return 0;
}