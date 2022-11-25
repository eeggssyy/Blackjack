//
//  main.cpp
//  Blackjack
//
//  Created by Will Delano on 11/19/22.
//  11/24/22 813 lines


/* Create HARD MODE */

#include <stdio.h>
#include "Deck.h"
#include "PlayerDeck.h"
#include "DealerDeck.h"
#include <ctime>

int main() {
    srand(time(0));
    Deck deck;
    PlayerDeck player;
    DealerDeck dealer;
    double startBalance, bet;
    string again = "\0";
    
    cout << "Choose your starting balance." << endl;
    while (true) {
        cin >> startBalance;
        cout << endl;
        if (/* DISABLES CODE */ (!true)) { //not a digit
            cout << "Not a valid amount, try again." << endl;
        }
        else {
            break;
        }
    }

    player.setBalance(startBalance);
    
    while (again != "0") {
        startBalance = player.returnBalance();
        while (true) {
            cout << "Choose your bet." << endl;
            cin >> bet;
            cout << endl;
            if (bet > startBalance || bet <= 0) {
                    cout << "Not a valid amount, try again." << endl;
            }
            else {
                player.placeBet(bet);
                break;
            }
        }
       /* while(true) {
            try {
                player.placeBet(bet);
                break;
            } catch (OVERBET) {
                cout << "Not enough funds, try again." << endl;
            } catch (UNDERBET) {
                cout << "Not a valid amount, try again." << endl;
            }
        }*/
    
        
        deck.createDeck();
        deck.shuffleDeck();
        player.dealCardToPlayer(deck.cards);
        player.dealCardToPlayer(deck.cards);
        dealer.drawCardToDealer(deck.cards);
        
        cout << "Your hand is: " << endl;
        player.printPlayerCards(cout);
        cout << "Value: " << player.playerValue() << endl << endl;

        cout << "The dealers card is ";
        dealer.printDealerCards(cout);
        dealer.drawCardToDealer(deck.cards);
        
        player.Decision(player, deck, dealer);
        
        cout << "New balance: ";
        player.printBalance(cout);

        player.clearPDeck(deck.cards); //return cards to deck
        dealer.clearDDeck(deck.cards); //return cards to deck
        
        cout << "Enter \"0\" if you would like to exit the game," <<
        "or anything else if not." << endl;
        cin >> again;
        cout << endl;
    }
}
