/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>

#include <gend/Account.hpp>

using namespace gend;

void orYouCouldDoThis() {
    using std::cout;
    using std::endl;

    Account account;

    account.deposit(100);
    cout << "balance after deposit: " << account.getBalance() << "\n";

    account.withdraw(50);
    cout << "balance after withdraw: " << account.getBalance() << endl;
}

int main() {
    std::cout << std::setprecision(2) << std::fixed;

    Account* account = new Account();
    account->deposit(100);
    std::cout << "balance after deposit: " << account->getBalance()
              << std::endl;
    account->withdraw(50);
    std::cout << "balance after withdraw: " << account->getBalance()
              << std::endl;

    std::stringstream ss;
    ss.imbue(std::locale("en_US"));
    // smallest non-fractional units of the currency: cents in the U.S,
    // an actual dollar class would use pennies as in integer for the balance
    ss << std::showbase << std::put_money(account->getBalance() * 100.0);
    std::cout << std::locale("en_US").name() << ": " << ss.str() << std::endl;
    
    orYouCouldDoThis();
    
    return EXIT_SUCCESS;
}

