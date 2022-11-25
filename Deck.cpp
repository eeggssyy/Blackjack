/*
* Date Created: 11/17/2022
* File: Deck.cpp
* Author: Will Delano
*/

#include "Deck.h"
#include <cstdlib>

bool Deck::isEmpty() {
    return this->cards.size() == 0;
}

void Deck::createDeck() {
    Card card;

    for (int suit = 0; suit < card.numSuits; suit++) {
        for (int rank = 0; rank < card.numRanks; rank++) {
            card.suit = Suit(suit);
            card.rank = Rank(rank);
            card.value = rank + 1;
            if (card.value > 10) {
                card.value = 10;
            }
            this->cards.push_back(card);
        }
    }
}

void Deck::shuffleDeck() {
    //creates a new deck for cards to be randomly placed into
    Deck shuffled;

    while (!this->cards.empty()) {
        unsigned int index = rand() % this->cards.size();

        //places cards randomly picked from the original deck into the new shuffled deck
        shuffled.cards.push_back(this->cards.at(index));

        //erases the old non-shuffled cards
        cards.erase(cards.begin() + index);
    }

    //replaces the now empty original deck with the shuffled cards
    cards = shuffled.cards;
}

int Deck::size() {
    return static_cast<int>(cards.size());
}

void Deck::printDeck(ostream& out) {
    for (int i = 0; i < MAXSIZE; i++) {
        /*switch (cards.at(i).suit) {
        case 0:
            out << "Red ";
            break;
        case 1:
            out << "Red ";
            break;
        default:
            out << "Black ";
        }*/

        switch (cards.at(i).rank) {
        case 0:
            out << "Ace";
            break;
        case 1:
            out << "Two";
            break;
        case 2:
            out << "Three";
            break;
        case 3:
            out << "Four";
            break;
        case 4:
            out << "Five";
            break;
        case 5:
            out << "Six";
            break;
        case 6:
            out << "Seven";
            break;
        case 7:
            out << "Eight";
            break;
        case 8:
            out << "Nine";
            break;
        case 9:
            out << "Ten";
            break;
        case 10:
            out << "Jack";
            break;
        case 11:
            out << "Queen";
            break;
        case 12:
            out << "King";
        }

        out << " of ";

        switch (cards.at(i).suit) {
        case 0:
            out << "Hearts";
            break;
        case 1:
            out << "Diamonds";
            break;
        case 2:
            out << "Clubs";
            break;
        case 3:
            out << "Spades";
            break;
        }
        
        if (cards.at(i).rank == 0) {
            cout << " (1 or 11)" << endl;
        }
        else {
            cout << " (" << (cards.at(i).value) << ")";
        }

        out << endl;
    }
}
