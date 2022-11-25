//
//  Bank.h
//  Blackjack
//
//  Created by Will Delano on 11/19/22.
//

#ifndef Bank_h
#define Bank_h

#include <iostream>
#include "BADINDEX.h"
#include <stdio.h>

class Bank {
public:
    double balance, bet;
    
    void printBet(std::ostream&);
    void printBalance(std::ostream&);
    void setBalance(double);
    void placeBet(double);
    void takeLosses();
    void giveWinnings();
    int returnBalance();
};

#endif /* Bank_h */
