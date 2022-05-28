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
        this->header->next = this->begin().wezel; // ustawianie headera na pierwszy węzeł
        this->begin().wezel->previous = header;
        this->trailer->previous = this->end().wezel; // ustawianie trailera na ostatni węzeł
        this->end().wezel->next = trailer;
    }
    return *this;
}

// zwraca Iterator znajdujący się na indeksie i
Sequence::Iterator Sequence::atIndex(int i) const
{
    Iterator p = begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}

// zwraca indeks Iteratora p
int Sequence::indexOf(const Iterator &p) const
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

// zwraca rozmiar sekwencji
int Sequence::size() const
{
    return numberOfItems;
}

// czy sekwencja jest pusta?
bool Sequence::isEmpty() const
{
    return (numberOfItems == 0);
}

// zwraca Iterator będący pierwszym elementem sekwencji
Sequence::Iterator Sequence::begin() const
{
    return Iterator(header->next);
}

// zwraca Iterator będący ostatnim elementem sekwencji
Sequence::Iterator Sequence::end() const
{
    return Iterator(trailer);
}

// umieszczanie nowego Elementu e w sekwencji przed Iteratorze p
void Sequence::insert(const Iterator &p, const Element &e)
{
    Node *w = p.wezel;     // w wskazuje na węzeł p
    Node *u = w->previous; // u wskazuje na element poprzedni do p
    Node *v = new Node;    // v zostanie nowym węzłem
    v->elem = e;           // uzupełnienie węzła v Elementem e
    v->next = w;
    w->previous = v; // v porzedza w
    v->previous = u;
    u->next = v; // v jest po u
    numberOfItems++;
}

// umieszczanie nowego Elementu e na końcu sekwencji
void Sequence::insertBack(const Element &e)
{
    insert(end(), e);
}

// umieszczanie nowego Elementu e na początku sekwencji
void Sequence::insertFront(const Element &e)
{
    insert(begin(), e);
}

// usuwanie Elementu o Iteratorze p
void Sequence::erase(const Iterator &p)
{
    Node *v = p.wezel;     // węzeł do usunięcia
    Node *w = v->next;     // następny węzeł
    Node *u = v->previous; // poprzedni węzeł
    u->next = w;
    w->previous = u; // odczepianie połączeń do p

    delete v;        // usuwanie węzła
    numberOfItems--; // zmiejszanie rozmiaru sekwencji
}

// usuwanie pierwszego węzła sekwencji
void Sequence::eraseFront()
{
    erase(begin());
}

// usuwanie ostatniego węzła sekwencji
void Sequence::eraseBack()
{
    erase(--end());
}

float Sequence::medium()
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
bool Sequence::isSorted()
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
void Sequence::clear()
{
    while (this->size() > 0)
    { // usuwanie poprzednich elementów sekwencji
        this->eraseBack();
    }
}