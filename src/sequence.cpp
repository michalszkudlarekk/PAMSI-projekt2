#include "sequence.hh"

// FUNKCJE DLA KLASY ITERATOR

// konstruktor Iteratora
Sequence::Iterator::Iterator(Node *u)
{
    wezel = u;
}

// operator * wskazuje na element węzła Iteratora
Element &Sequence::Iterator::operator*()
{
    return wezel->elem;
}

// operator porównawczy dla Iteratorów, porównuje węzły
bool Sequence::Iterator::operator==(const Iterator &p) const
{
    return wezel == p.wezel;
}

// perator sprawdzajączy czy węzły Iteratorów są różne
bool Sequence::Iterator::operator!=(const Iterator &p) const
{
    return wezel != p.wezel;
}

// operator postinkrementacji, przesuwa Iterator na następny węzeł
Sequence::Iterator &Sequence::Iterator::operator++()
{
    wezel = wezel->next;
    return *this;
}

// operator postdekrementacji, przesuwa Iterator na poprzedni węzeł
Sequence::Iterator &Sequence::Iterator::operator--()
{
    wezel = wezel->previous;
    return *this;
}

// FUNKCJE DLA KLASY SEQUENCE-------------------------------------------
// konstruktor dla sekwencji
Sequence::Sequence()
{
    numberOfItems = 0;      // na początku sekwencja jest pusta
    header = new Node;      // header wskazuje na nowy węzeł
    trailer = new Node;     // trailer wskazuje na nowy węzeł
    header->next = trailer; // header i trailer zostają połączone
    header->previous = NULL;
    trailer->previous = header;
    trailer->next = NULL; // pozostałe wskaźniki ustawiane są na NULL
}

// destruktor dla sekwencji
Sequence::~Sequence()
{

    while (this->size() > 0)
    { // usuwanie poprzednich elementów sekwencji
        this->eraseBack();
    }
    delete header; // usuwanie headera i trailera
    delete trailer;
}

// konstruktor kopiujący dla sekwencji
Sequence::Sequence(const Sequence &sekwencja)
{
    this->header = new Node;  // header wskazuje na nowy węzeł
    this->trailer = new Node; // traiker wskazuje na nowy węzeł
    header->next = trailer;   // header i trailer zostają połączone
    header->previous = NULL;
    trailer->previous = header;
    trailer->next = NULL; // pozostałe wskaźniki ustawiane są na NULL

    numberOfItems = 0;
    for (int i = 0; i < sekwencja.numberOfItems; i++) // uzupełnianie Sequence
    {
        this->insertBack(sekwencja.atIndex(i).wezel->elem);
    }
}
// konstruktor kopiujący z rozmiarem
Sequence::Sequence(const Sequence &sekwencja, int size)
{
    this->header = new Node;  // header wskazuje na nowy węzeł
    this->trailer = new Node; // traiker wskazuje na nowy węzeł
    header->next = trailer;   // header i trailer zostają połączone
    header->previous = NULL;
    trailer->previous = header;
    numberOfItems = 0;
    trailer->next = NULL;          // pozostałe wskaźniki ustawiane są na NULL
    for (int i = 0; i < size; i++) // uzupełnianie Sequence
    {
        this->insertBack(sekwencja.atIndex(i).wezel->elem);
    }
}

// operator przyrównania dla sekwencji (też może funkcjonować jako konstruktor kopiujący)
Sequence &Sequence::operator=(const Sequence &sekwencja)
{
    if (this != &sekwencja)
    { // o ile nie są takie same:
        while (this->size() > 0)
        { // usuwanie poprzednich elementów, jeśli istnieją
            this->eraseBack();
        }

        this->numberOfItems = sekwencja.numberOfItems; // ustawianie tej samej liczby elementów
        for (int i = 0; i < this->numberOfItems; i++)
        {
            this->insertBack(sekwencja.atIndex(i).wezel->elem); // uzupełnanie sekwencji
        }
        this->header->next = this->begin().wezel; /* ustawianie headera jako pierwszy węzeł */
        this->begin().wezel->previous = header;
        this->trailer->previous = this->end().wezel; /* ustawianie trailera jako ostatni węzeł */
        this->end().wezel->next = trailer;
    }
    return *this;
}

Sequence::Iterator Sequence::atIndex(int i) const /* Zwrócenie iteratora znajdującego się na indeksie i*/
{
    Iterator p = begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}

int Sequence::indexOf(const Iterator &p) const /* Zwrócenie indeksu iteratora p*/
{
    Iterator q = begin();
    int j = 0;
    while (q != p)
    {
        ++q;
        ++j;
    }
    return j;
}

int Sequence::size() const /* Zwrócenie rozmiaru sekwencji */
{
    return numberOfItems;
}

bool Sequence::isEmpty() const /* Sprawdzenie czy sekwencja jest pusta */
{
    return (numberOfItems == 0);
}

/* Zwraca iterator będący pierwszym elementem sekwencji */
Sequence::Iterator Sequence::begin() const
{
    return Iterator(header->next);
}

Sequence::Iterator Sequence::end() const /* Zwrócenie iteratora będącego ostatnim elementem sekwencji */
{
    return Iterator(trailer);
}

void Sequence::insert(const Iterator &p, const Element &e) /* Umieszczenie nowego elementu e w sekwencji przed iteratorem p */
{
    Node *w = p.wezel;     /* w zostaje dołączone do węzła p */
    Node *u = w->previous; /* u zostaje dołączone na element poprzedni do p */
    Node *v = new Node;    /* v jako nowy węzeł */
    v->elem = e;           /*uzupełnienie węzła v elementem e */
    v->next = w;
    w->previous = v; /*v przed w */
    v->previous = u;
    u->next = v; /* v po u */
    numberOfItems++;
}

void Sequence::insertBack(const Element &e) /* Umieszczenie nowego elementu e na końcu sekwencji */
{
    insert(end(), e);
}

void Sequence::insertFront(const Element &e) /* Umieszczenie nowego elementu e na początku sekwencji */
{
    insert(begin(), e);
}

void Sequence::erase(const Iterator &p) /* Usuwanie elementu o iteratorze p */
{
    Node *v = p.wezel;     /* Węzeł do usunięcia  */
    Node *w = v->next;     /* Następny węzeł */
    Node *u = v->previous; /* Poprzedni węzeł */
    u->next = w;
    w->previous = u; /* Odłączenie połączeń do p */

    delete v;        /* Usunięcię węzła */
    numberOfItems--; /* Postdekrementacja rozmiaru sekwencji */
}

void Sequence::eraseFront() /* Usunięcie pierwszego węzła sekwencji */
{
    erase(begin());
}

void Sequence::eraseBack() /* Usunięcie ostatniego węzła sekwencji */
{
    erase(--end());
}

float Sequence::medium() /* Mediana */
{
    float medium = 0;
    if (this->isSorted())
    {
        if (this->size() % 2 == 1)
        {
            medium = (*(this->atIndex(numberOfItems / 2))).getKey();
        }
        else
        {
            medium = ((*(this->atIndex(numberOfItems / 2 - 1))).getKey() + (*(this->atIndex(numberOfItems / 2))).getKey()) / 2;
            ;
        }
    }
    return medium;
}
float Sequence::sumOfKeys()
{
    float sum = 0;
    Sequence::Iterator p(this->begin());
    while (p != this->end())
    {
        sum += (*p).getKey();
        ++p;
    }
    return sum;
}
float Sequence::average()
{
    float average;
    average = this->sumOfKeys() / this->size();
    return average;
}
bool Sequence::isSorted() /* sprawdzenie czy posortowano */
{
    if (this->size() == 0)
        return false;
    if (this->size() == 1)
        return true;
    Sequence::Iterator p(this->begin());
    while (++p != this->end())
    {
        if ((*p).getKey() < (*(--p)).getKey())
            return false;
        ++p;
    }
    return true;
}
void Sequence::clear() /* Usunięcie poprzednich elementó sekwencji */
{
    while (this->size() > 0)
    {
        this->eraseBack();
    }
}