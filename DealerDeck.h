//
//  DealerDeck.h
//  Blackjack
//
//  Created by Will Delano on 11/21/22.
//

#ifndef DealerDeck_h
#define DealerDeck_h

#include "Deck.h"
#include <stdio.h>

class DealerDeck : public Deck {
public:
    vector<Card> dealerCards;
    
    void clearDDeck(vector<Card>&);
    int dealerValue();
    void printDealerCards(ostream& out);
    void drawCardToDealer(vector<Card>&);
};

#endif /* DealerDeck_h */
