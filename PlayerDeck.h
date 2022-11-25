//
//  PlayerDeck.h
//  Blackjack
//
//  Created by Will Delano on 11/21/22.
//

#ifndef PlayerDeck_h
#define PlayerDeck_h

#include "Bank.h"
#include "DealerDeck.h"
#include <stdio.h>

class PlayerDeck : public DealerDeck, public Bank {
public:
    vector<Card> playerCards;
    Bank money;
    
    void clearPDeck(vector<Card>&);
    void Compare(PlayerDeck&, DealerDeck&);
    void Bust();
    void Decision(PlayerDeck&, Deck&, DealerDeck&);
    void hit(vector<Card>&);
    bool doubleDown();
    void dealCardToPlayer(vector<Card>&);
    void printPlayerCards(ostream& out);
    int playerValue();
};

#endif /* PlayerDeck_h */
