//
//  DealerDeckr.cpp
//  Blackjack
//
//  Created by Will Delano on 11/21/22.
//

#include "DealerDeck.h"

void DealerDeck::clearDDeck(vector<Card>& cards) {
    int count = dealerCards.size();
    for (int i = 0; i < count; i++) {
        cards.push_back(dealerCards.at((dealerCards).size()-1));
        (dealerCards).pop_back();
    }
}

void DealerDeck::drawCardToDealer(vector<Card>& cards) {
    dealerCards.push_back(cards.at(cards.size() -1));
    cards.pop_back();
}

int DealerDeck::dealerValue() {
    bool ace = false;
    int count = 0;
    for (int i = 0; i < dealerCards.size(); i++) {
        count += dealerCards.at(i).value;
    }
    
    //searching for an ace
    for (int i = 0; i < dealerCards.size(); i++) {
        if (dealerCards.at(i).rank == 0) {
            ace = true;
        }
    }
    
    //sets the value of ace to 11 if it stays under 22
    if (ace && count + 10 < 22) {
        count += 10;
    }
    return count;
}

void DealerDeck::printDealerCards(ostream& out) {
    for (int i = 0; i < dealerCards.size(); i++) {
        /*switch (playerCards.at(i).suit) {
        case 0:
            out << "Red ";
            break;
        case 1:
            out << "Red ";
            break;
        default:
            out << "Black ";
        }*/

        switch (dealerCards.at(i).rank) {
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

        switch (dealerCards.at(i).suit) {
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
        
        if (dealerCards.at(i).rank == 0) {
            cout << " (1 or 11)";
        }
        else {
            cout << " (" << (dealerCards.at(i).value) << ")";
        }
        out << endl;
    }
}
