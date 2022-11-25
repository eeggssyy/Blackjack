/*
* Date Created: 11/17/2022
* File: PlayerDeck.cpp
* Author: Will Delano
*/

#include "PlayerDeck.h"
#pragma warning(disable:)
void PlayerDeck::clearPDeck(vector<Card>& cards) {
    int count = playerCards.size();
    for (int i = 0; i < count; i++) {
        cards.push_back(playerCards.at((playerCards).size()-1));
        (playerCards).pop_back();
    }
}

void PlayerDeck::Compare(PlayerDeck& player, DealerDeck& dealer) {
    if (dealer.dealerValue() > 21) {
        cout << "Dealer bust. You won." << endl;
        cout << "Player value: " << player.playerValue() << endl;
        cout << "Dealer value: " << dealer.dealerValue() << endl << endl;
        giveWinnings();
    } else {
        if (player.playerValue() > 21) {
            Bust();
            cout << "Player value: " << player.playerValue() << endl << endl;
        }
        else {
            int value = player.playerValue() - dealer.dealerValue();
            if (value == 0) {
                cout << "Dealer cards: " << endl;
                dealer.printDealerCards(cout);
                cout << endl;
                cout << "Tie." << endl;
                balance += bet;
                cout << "Player value: " << player.playerValue() << endl;
                cout << "Dealer value: " << dealer.dealerValue() << endl << endl;
            }
            else if (value > 0) {
                cout << "Dealer cards: " << endl;
                dealer.printDealerCards(cout);
                cout << endl;
                cout << "You won." << endl;
                giveWinnings();
                cout << "Player value: " << player.playerValue() << endl;
                cout << "Dealer value: " << dealer.dealerValue() << endl << endl;
            }
            else {
                cout << "Dealer cards: " << endl;
                dealer.printDealerCards(cout);
                cout << endl;
                cout << "You lost." << endl;
                cout << "Player value: " << player.playerValue() << endl;
                cout << "Dealer value: " << dealer.dealerValue() << endl << endl;
            }
        }
    }
}

void PlayerDeck::Bust() {
    cout << "Bust. You Lost." << endl << endl;
}

void PlayerDeck::Decision(PlayerDeck& player, Deck& deck, DealerDeck& dealer) {
    char choice;
    cout << "Hit, Stand, or Double Down? (H/S/D)" << endl;
    cin >> choice;
    cout << endl;
    
    if (choice == 'H' || choice == 'h') {
        player.hit(deck.cards);
        
        if (player.playerValue() > 21) {
            player.printPlayerCards(cout);
            cout << "Value: " << player.playerValue() << endl;
            Bust();
        } else {
            player.printPlayerCards(cout);
            cout << "Value: " << player.playerValue() << endl << endl;
            Decision(player, deck, dealer);
        }
    }
    
    if (choice == 'd' || choice == 'D') {
        if (player.doubleDown()) {
            player.hit(deck.cards);
            player.printPlayerCards(cout);
            cout << "Value: " << player.playerValue() << endl << endl;
            Compare(player, dealer);
        }
        else {
            Decision(player, deck, dealer);
        }
    }
    
    if (choice == 's' || choice == 'S') {
        Compare(player, dealer);
    }
}

int PlayerDeck::playerValue() {
    bool ace = false;
    int count = 0;
    for (int i = 0; i < playerCards.size(); i++) {
        count += playerCards.at(i).value;
    }
    
    //searching for an ace
    for (int i = 0; i < playerCards.size(); i++) {
        if (playerCards.at(i).rank == 0) {
            ace = true;
        }
    }
    
    //sets the value of ace to 11 if it stays under 22
    if (ace && count + 10 < 22) {
        count += 10;
    }
    return count;
}

void PlayerDeck::dealCardToPlayer(vector<Card>& cards) {
    playerCards.push_back(cards.at((cards).size()-1));
    (cards).pop_back();
}

void PlayerDeck::hit(vector<Card>& cards) {
    dealCardToPlayer(cards);
}

bool PlayerDeck::doubleDown() {
    if (bet*2 <= balance) {
        balance -= bet;
        bet *= 2;
        return true;
    } else {
        std::cout << "Not enough funds, try again" << endl;
        return false;
    }
}

void PlayerDeck::printPlayerCards(ostream& out) {
    for (int i = 0; i < playerCards.size(); i++) {
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

        switch (playerCards.at(i).rank) {
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

        switch (playerCards.at(i).suit) {
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
        
        if (playerCards.at(i).rank == 0) {
            cout << " (1 or 11)";
        }
        else {
            cout << " (" << (playerCards.at(i).value) << ")";
        }

        out << endl;
    }
}
