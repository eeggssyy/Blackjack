/*
* Date Created: 11/17/2022
* File: Main.cpp
* Author: Will Delano


#include "Deck.h"
#include "DealerDeck.h"
#include "PlayerDeck.h"

int main() {
    Deck a;
    PlayerDeck player;
    DealerDeck dealer;
    
    a.createDeck();
    a.printDeck(cout);
    
    cout << endl;
    cout << "Shuffled : " << endl << endl;

    a.shuffleDeck();
    a.printDeck(cout);
    cout << endl;

    cout << "Player cards after drawing: " << endl;
    player.dealCardToPlayer(a.cards);
    player.printPlayerCards(cout);
    
    dealer.drawCardToDealer(a.cards);
    dealer.printDealerCards(cout);
    
    a.setBalance(5000);
    a.printBalance(cout);
    a.placeBet(1000);
    a.printBalance(cout);
    a.giveWinnings();
    a.printBalance(cout);
    cout << a.size();
}
*/
