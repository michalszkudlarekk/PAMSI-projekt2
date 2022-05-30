#include "sorting_algorithms.hh"

bool isLess(Element a, Element b)
{
    return (a.getKey() < b.getKey());
}

void mergeSort(Sequence &S)
{
    int n = S.size();
    if (n <= 1)
        return;
    Sequence S1, S2;
    Sequence::Iterator p = S.begin();
    for (int i = 0; i < n / 2; i++)
    {
        S1.insertBack(*p);
        ++p;
    };
    for (int i = n / 2; i < n; i++)
    {
        S2.insertBack(*p);
        ++p;
    };
    while (!S.isEmpty())
    {
        S.eraseBack();
    };
    mergeSort(S1);
    mergeSort(S2);
    merge(S1, S2, S);
}

void merge(Sequence &S1, Sequence &S2, Sequence &S)
{
    Sequence::Iterator p1 = S1.begin();
    Sequence::Iterator p2 = S2.begin();
    while (p1 != S1.end() && p2 != S2.end())
    {
        if (isLess(*p1, *p2))
        {
            S.insertBack(*p1);
            ++p1;
        }
        else
        {
            S.insertBack(*p2);
            ++p2;
        }
    }

    while (p1 != S1.end())
    {
        S.insertBack(*p1);
        ++p1;
    };
    while (p2 != S2.end())
    {
        S.insertBack(*p2);
        ++p2;
    };
}

void QuickSort(Sequence &S)
{

    if (S.size() <= 1)
        return;

    Element p = *(--S.end()); // pivot

    Sequence L, E, G;

    while (!S.isEmpty())
    {
        if (isLess(*(--S.end()), p))
        {
            L.insertBack(*(--S.end()));
            S.eraseBack();
        }
        else if (!isLess(*(--S.end()), p) && !isLess(p, *(--S.end())))
        {
            E.insertBack(*(--S.end()));
            S.eraseBack();
        }
        else
        {
            G.insertBack(*(--S.end()));
            S.eraseBack();
        }
    }
    QuickSort(L);
    QuickSort(G);

    while (!L.isEmpty())
    {
        S.insertBack(*L.begin());
        L.eraseFront();
    }
    while (!E.isEmpty())
    {
        S.insertBack(*E.begin());
        E.eraseFront();
    }
    while (!G.isEmpty())
    {
        S.insertBack(*G.begin());
        G.eraseFront();
    }
}

void bucketSort(Sequence &S)
{
    Sequence buckets[10];

    while (!S.isEmpty())
    {
        buckets[(int)ceil(static_cast<double>((*(S.begin())).getKey())) - 1].insertBack(*S.begin());
        S.eraseFront();
    }

    for (int i = 0; i < 10; i++)
    {
        QuickSort(buckets[i]);
    }

    for (int i = 0; i < 10; i++)
    {

        while (!buckets[i].isEmpty())
        {
            S.insertBack(*buckets[i].begin());
            buckets[i].eraseFront();
        }
    }
}