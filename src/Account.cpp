/**
 * @file Account.cpp
 *
 * @brief The Account implementation
 *
 * Here are the implementations.
 *
 * @author Gene De Lisa <gene@rockhoppertech.com>
 *
 */

//#include <Account.hpp>

#include "Account.hpp"

namespace gend {
    Account::Account() : balance(0) {}

    Account::~Account() {}

    void Account::deposit(double amount) { balance += amount; }

    void Account::withdraw(double amount) { balance -= amount; }

    double Account::getBalance() const { return balance; }

} // namespace gend
