//
//  Bank.cpp
//  Blackjack
//
//  Created by Will Delano on 11/19/22.
//
#include "Bank.h"
#include <iomanip>

int Bank::returnBalance() {
    return this->balance;
}

void Bank::printBet(std::ostream& out) {
    out << std::fixed << std::setprecision(2) << "$" << this->bet << std::endl;
}

void Bank::printBalance(std::ostream& out) {
    out << std::fixed << std::setprecision(2) << "$" << this->balance << std::endl;
}

void Bank::setBalance(double a) {
    this->balance = a;
}

void Bank::placeBet(double a) {
    /*if (a <= 0 || !isdigit(a)) {
        throw UNDERBET();
    }
    if (a > this->balance) {
        throw OVERBET();
    }*/
    this->bet = a;
    this->balance -= a;
}

void Bank::giveWinnings() {
    this->balance += 2*bet;
}
