#include "algorithms.hh"

bool isLess(Element a, Element b)
{
    return (a.getKey() < b.getKey());
}

void merge(sequence &S1, sequence &S2, sequence &S) /* Scalanie */
{
    sequence::iterator p1 = S1.begin();
    sequence::iterator p2 = S2.begin();
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

void mergeSort(sequence &S) /* Sortowanie przez scalanie */
{
    int n = S.size();
    if (n <= 1)
        return;
    sequence S1, S2;
    sequence::iterator p = S.begin();
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

void QuickSort(sequence &S) /* Sortowanie szybkie */
{

    if (S.size() <= 1)
        return;

    Element p = *(--S.end());

    sequence L, E, G;

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

void bucketSort(sequence &S) /* Sortowanie kubełkowe*/
{
    sequence buckets[10];

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