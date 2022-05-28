#ifndef ELEMENT_HH
#define ELEMENT_HH

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class Element /* Klasa element */
{

public:
    Element() /* Konstruktor */
    {
        key = 0;
        contents = "";
    }
    Element(float k, std::string c) /* Konstruktor odpowiadający za kopiowanie */
    {
        key = k;
        contents = c;
    }
    float getKey() { return key; }                 /* Funckaj zwracająca zawartość */
    std::string getContents() { return contents; } /* Funckaj zwracająca zawartość */
private:                                           /* Pole prywatne klasy */
    float key;                                     /* Klucz */
    std::string contents;                          /* Zawartość */
};

#endif