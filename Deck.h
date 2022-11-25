/*
* Date Created: 11/17/2022
* File: DealerDeck.cpp
* Author: Will Delano
*/

#ifndef Deck_h
#define Deck_h

#include "Card.h"
#include "Bank.h"
#include <string>
#include <vector>
#include <iostream>
#define MAXSIZE 52
using namespace std;

class Deck : public Card {
public:
    vector<Card> cards;
public:
    int size();
    void printDeck(ostream&);
    void createDeck();
    void shuffleDeck();
    bool isEmpty();
};

#endif /* Deck_h */
