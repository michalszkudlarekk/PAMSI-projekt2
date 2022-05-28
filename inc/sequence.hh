#ifndef SEQUENCE_HH
#define SEQUENCE_HH

#include "element.hh"

class sequence /* Klasa pozwalająca na dostęp dowolnych elementów listy dwukierunkowej*/
{
private:
    class node /* Węzeł listy dwukierunkowej */
    {
    public: /* Konstruktor */
        node()
        {
            next = NULL;
            previous = NULL;
        }
        node *getNext() { return next; }         /* Zwrócenie wskaźnika na następny węzeł */
        node *getPrevious() { return previous; } /* Zwrócenie wskaźnika na poprzedni węzeł */
        ~node()
        { /* Ustawienie następnego i poprzedniego węzła na zero */
            next = NULL;
            previous = NULL;
        }
        friend sequence; /* Pomocnicza(zaprzyjaźniona) klasa do sequence */
    private:
        node *next;     /* Wskaźnik na następny węzeł */
        node *previous; /* Wskaźnik na poprzedni węzeł */
        element elem;   /* Zawartosć węzła*/
    };

public:
    class iterator /* Klasa umożliwiająca na poruszanie się po węzłach */
    {
    public:
        element &operator*();                            /* Referencja do poszczególnego elementu */
        bool operator==(const iterator &iterator) const; /* Porównanie pozycji*/
        bool operator!=(const iterator &iterator) const; /* Sprawdzenie czy pozycje się różnią*/
        iterator &operator++();                          /* Przejście do następnego wezła*/
        iterator &operator--();                          /* Przejście do poprzedniego węzła*/
        friend sequence;                                 /* Pomocnicza(zaprzyjaźniona) klasa do sequence */
    private:
        node *node;        /* Wskaźnik na węzeł */
        iterator(node *u); /* Utworzenie od węzła, konstruktor ( u - utwórz) */
    };

public:
    sequence();                                       /* Konstruktor*/
    sequence(const sequence &sequence);               /* Konstruktor kopiujący */
    sequence(const sequence &sequence, int size);     /* Konstruktor z rozmiarem*/
    sequence &operator=(const sequence &sequence);    /* Operator przyrównania dla sekwencji*/
    int size() const;                                 /* Zwrócenie rozmiaru sekwencji*/
    bool isEmpty() const;                             /* Sprawdzenie czy pusta sekwencja */
    iterator begin() const;                           /* Zwrócenie pozycji pierwszego elementu*/
    iterator end() const;                             /* Zwrócenie pozycji ostatniego elementu*/
    void insertBack(const element &e);                /* Umieszczenie nowego elemetnu na końcu sekwencji ( e - element) */
    void insertFront(const element &e);               /* Umieszczenie nowego elemetnu na początku sekwencji ( e - element) */
    void insert(const iterator &p, const element &e); /* Umieszczenie nowego elemetnu przed iteratorem */
    void eraseFront();                                /* Usunięcie pierwszego węzła sekwencji */
    void eraseBack();                                 /* Usunięcie ostatniego węzła sekwencji */
    void erase(const iterator &p);                    /* Usunięcie elementu o iteratorze p */
    iterator atIndex(int i) const;                    /* Zwrócenie iteratora znajdującego się na indeksie i ( i - indeks)*/
    int indexOf(const iterator &p) const;             /* Zwrócenie indeksu iteratora p */
    float medium();                                   /* Mediana */
    float sumOfKeys();                                /* Suma wszystkich kluczy elementów sekwencji */
    float average();                                  /* Średnia wszystkich kluczy elementów sekwencji */
    bool isSorted();                                  /* Sprawdzenie czy dana sekwencja jest dobrze posortowana */
    void clear();                                     /* Usunięcie wszystkich elementów z sekwencji */
    ~sequence();                                      /* Dekonstruktor */

private:
    int numberOfItems; /* Liczba wszystkich elementów */
    Node *header;      /* Wskaźnik na pierwszy element */
    Node *trailer;     /* Wskaźnik na ostatni element */
};

#endif