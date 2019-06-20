/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include <iomanip>
#include <iostream>
#include <locale>
#include <memory> // We need to include this for shared_ptr
#include <sstream>

#include <Account.hpp>

using namespace gend;

int main() {
    std::wstring s;

    std::cout << std::setprecision(2) << std::fixed;

    //auto myAccount {std::make_shared<Account>()};
    //auto herAccount = myAccount;

    auto account {std::make_unique<Account>()};

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

    return EXIT_SUCCESS;
}
