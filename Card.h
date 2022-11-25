//
//  Card.h
//  Blackjack
//
//  Created by Will Delano on 11/19/22.
//

#ifndef Card_h
#define Card_h

#include "BADINDEX.h"
#include <stdio.h>

enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};

class Card {
public:
    Rank rank;
    Suit suit;
    int value;
    int numSuits = 4;
    int numRanks = 13;
public:
    Card();
};

#endif /* Card_h */
