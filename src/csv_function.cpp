#include "csv_function.hh"
#include <cmath>

void uploadFileIntoSequence(Sequence *seq, rapidcsv::Document doc)
{
    float rating;
    std::string title;
    if (seq->size() != 0)
    {
        seq->clear();
    }

    for (int i = 0; doc.GetRowIdx(std::to_string(i)) == i; i++)
    {
        rating = doc.GetCell<float>("rating", i);
        title = doc.GetCell<std::string>("movie", i);
        seq->insertBack(Element(rating, title));
    }
}
void uploadFileIntoSequence(sequence *seq, rapidcsv::Document doc, int size)
{
    float rating;
    std::string title;
    if (seq->size() != 0)
    {
        seq->clear();
    }

    for (int i = 0; i < rozmiar; i++)
    {
        rating = doc.GetCell<float>("rating", i);
        title = doc.GetCell<std::string>("movie", i);
        seq->insertBack(Element(rating, title));
    }
}

void DeleteInvalid(sequence *seq)
{
    sequence::iterator p(seq->begin());
    sequence::iterator q = p;
    while (p != seq->end())
    {
        if (__isnanf((*p).getKey()))
        {
            q = p;
            ++p;
            seq->erase(q);
        }
        else
        {
            ++p;
        }
    }
}
