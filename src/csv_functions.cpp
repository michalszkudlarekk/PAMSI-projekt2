#include "csv_functions.hh"
#include <cmath>

void uploadFileIntoSequence(Sequence *Seq, rapidcsv::Document doc)
{
    float rating;
    std::string title;
    if (Seq->size() != 0)
    {
        Seq->clear();
    }

    for (int i = 0; doc.GetRowIdx(std::to_string(i)) == i; i++)
    {
        rating = doc.GetCell<float>("rating", i);
        title = doc.GetCell<std::string>("movie", i);
        Seq->insertBack(Element(rating, title));
    }
}
void uploadFileIntoSequence(Sequence *Seq, rapidcsv::Document doc, int rozmiar)
{
    float rating;
    std::string title;
    if (Seq->size() != 0)
    {
        Seq->clear();
    }

    for (int i = 0; i < rozmiar; i++)
    {
        rating = doc.GetCell<float>("rating", i);
        title = doc.GetCell<std::string>("movie", i);
        Seq->insertBack(Element(rating, title));
    }
}

void DeleteInvalid(Sequence *Seq)
{
    Sequence::Iterator p(Seq->begin());
    Sequence::Iterator q = p;
    while (p != Seq->end())
    {
        if (__isnanf((*p).getKey()))
        {
            q = p;
            ++p;
            Seq->erase(q);
        }
        else
        {
            ++p;
        }
    }
}
