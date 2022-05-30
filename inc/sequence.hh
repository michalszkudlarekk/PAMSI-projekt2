#ifndef SEQUENCE_HH
#define SEQUENCE_HH

#include "element.hh"

class Sequence /* Klasa pozwalająca na dostęp dowolnych elementów listy dwukierunkowej*/
{
private:
    class Node /* Węzeł listy dwukierunkowej */
    {
    public: /* Konstruktor */
        Node()
        {
            next = NULL;
            previous = NULL;
        }
        Node *getNext() { return next; }         /* Zwrócenie wskaźnika na następny węzeł */
        Node *getPrevious() { return previous; } /* Zwrócenie wskaźnika na poprzedni węzeł */
        ~Node()
        { /* Ustawienie następnego i poprzedniego węzła na zero */
            next = NULL;
            previous = NULL;
        }
        friend Sequence; /* Pomocnicza(zaprzyjaźniona) klasa do sequence */
    private:
        Node *next;     /* Wskaźnik na następny węzeł */
        Node *previous; /* Wskaźnik na poprzedni węzeł */
        Element elem;   /* Zawartosć węzła*/
    };

public:
    class Iterator /* Klasa umożliwiająca na poruszanie się po węzłach */
    {
    public:
        Element &operator*();                     /* Referencja do poszczególnego elementu */
        bool operator==(const Iterator &p) const; /* Porównanie pozycji*/
        bool operator!=(const Iterator &p) const; /* Sprawdzenie czy pozycje się różnią*/
        Iterator &operator++();                   /* Przejście do następnego wezła*/
        Iterator &operator--();                   /* Przejście do poprzedniego węzła*/
        friend Sequence;                          /* Pomocnicza(zaprzyjaźniona) klasa do sequence */
    private:
        Node *wezel;       /* Wskaźnik na węzeł */
        Iterator(Node *u); /* Utworzenie od węzła, konstruktor ( u - utwórz) */
    };

public:
    Sequence();                                       /* Konstruktor*/
    Sequence(const Sequence &Sequence);               /* Konstruktor kopiujący */
    Sequence(const Sequence &Sequence, int size);     /* Konstruktor z rozmiarem*/
    Sequence &operator=(const Sequence &Sequence);    /* Operator przyrównania dla sekwencji*/
    int size() const;                                 /* Zwrócenie rozmiaru sekwencji*/
    bool isEmpty() const;                             /* Sprawdzenie czy pusta sekwencja */
    Iterator begin() const;                           /* Zwrócenie pozycji pierwszego elementu*/
    Iterator end() const;                             /* Zwrócenie pozycji ostatniego elementu*/
    void insertBack(const Element &e);                /* Umieszczenie nowego elemetnu na końcu sekwencji ( e - element) */
    void insertFront(const Element &e);               /* Umieszczenie nowego elemetnu na początku sekwencji ( e - element) */
    void insert(const Iterator &p, const Element &e); /* Umieszczenie nowego elemetnu przed iteratorem */
    void eraseFront();                                /* Usunięcie pierwszego węzła sekwencji */
    void eraseBack();                                 /* Usunięcie ostatniego węzła sekwencji */
    void erase(const Iterator &p);                    /* Usunięcie elementu o iteratorze p */
    Iterator atIndex(int i) const;                    /* Zwrócenie iteratora znajdującego się na indeksie i ( i - indeks)*/
    int indexOf(const Iterator &p) const;             /* Zwrócenie indeksu iteratora p */
    float medium();                                   /* Mediana */
    float sumOfKeys();                                /* Suma wszystkich kluczy elementów sekwencji */
    float average();                                  /* Średnia wszystkich kluczy elementów sekwencji */
    bool isSorted();                                  /* Sprawdzenie czy dana sekwencja jest dobrze posortowana */
    void clear();                                     /* Usunięcie wszystkich elementów z sekwencji */
    ~Sequence();                                      /* Dekonstruktor */

private:
    int numberOfItems; /* Liczba wszystkich elementów */
    Node *header;      /* Wskaźnik na pierwszy element */
    Node *trailer;     /* Wskaźnik na ostatni element */
};

#endif