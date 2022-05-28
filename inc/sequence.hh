#ifndef SEQUENCE_HH
#define SEQUENCE_HH

#include "element.hh"

class sequence /* Klasa pozwalająca na dostęp dowolnych elementów listy dwukierunkowej*/
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
        Node *getNext() { return next; }         /* zwraca wskaźnik na następny węzeł */
        Node *getPrevious() { return previous; } // zwraca wskaźnik na poprzedni węzeł
        ~Node()
        {
            next = NULL;
            previous = NULL;
        }                // desktruktor
        friend sequence; // zaprzyjaźniona klasa sequence
    private:
        Node *next;     // wskaźnik na następny węzeł
        Node *previous; // wskaźnik na poprzeni węzeł
        Element elem;   // zawartość węzła
    };

public:
    // klasa pozwalająca na poruszanie się po węzłach
    class iterator
    {
    public:
        Element &operator*();                     // referencja do elementu
        bool operator==(const iterator &p) const; // porównanie pozycji
        bool operator!=(const iterator &p) const; // sprawdzanie czy różne
        iterator &operator++();                   // przejdź do następnego węzła
        iterator &operator--();                   // przejdź do poprzedniego węzła
        friend sequence;                          // zaprzyjaźniona klasa Sequence
    private:
        Node *wezel;       // wskaźnik na węzeł
        Iterator(Node *u); // utwórz od węzła, konstruktor
    };

public:
    sequence();                                       // konstruktor
    sequence(const sequence &sequence);               // konstruktor kopiujący
    sequence(const sequence &sequence, int size);     // konstruktor kopiujący z rozmiarem
    sequence &operator=(const sequence &sequence);    // operator przyrównania dla sekwencji (też może funkcjonować jako konstruktor kopiujący)
    int size() const;                                 // zwraca rozmiar sekwencji
    bool isEmpty() const;                             // czy pusta?
    iterator begin() const;                           // zwraca pozycję pierwszego elementu
    iterator end() const;                             // zwraca pozycję ostatniego elementu
    void insertBack(const Element &e);                // umieszczanie nowego Elementu e na końcu sekwencji
    void insertFront(const Element &e);               // umieszczanie nowego Elementu e na początku sekwencji
    void insert(const iterator &p, const Element &e); // umieszczanie nowego Elementu e w sekwencji przed Iteratorze p
    void eraseFront();                                // usuwanie pierwszego węzła sekwencji
    void eraseBack();                                 // usuwanie ostatniego węzła sekwencji
    void erase(const iterator &p);                    // usuwanie Elementu o Iteratorze p
    iterator atIndex(int i) const;                    // zwraca Iterator znajdujący się na indeksie i
    int indexOf(const iterator &p) const;             // zwraca indeks Iteratora p
    float medium();                                   // mediana
    float sumOfKeys();                                // suma kluczy wszystkich elementów sekwencji
    float average();                                  //średnia kluczy wszystkich elementów
    bool isSorted();                                  // funkcja sprawdza, czy sekwencja jest posortowana
    void clear();                                     // funkcja usuwa wszystkie elementy z sekwencji
    ~sequence();                                      // destruktor

private:
    int numberOfItems; // liczba elementów
    Node *header;      // wskaźnik na pierwszy element
    Node *trailer;     // wskaźnik na ostatni element
};

#endif