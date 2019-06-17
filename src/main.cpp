/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
 *  Licensed under the MIT License.
 *  See LICENSE in the project for license information.
 *--------------------------------------------------------------------------------------------*/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <locale>

#include <Account.hpp>

using namespace gend;

int main() {
	std::cout << std::setprecision(2) << std::fixed;

	Account *account = new Account();
	account->deposit(100);
	std::cout << "balance after deposit: " << account->getBalance() << std::endl;
	account->withdraw(50);
	std::cout << "balance after withdraw: " << account->getBalance() << std::endl;

	std::stringstream ss;
	std::locale::global(std::locale(""));
	// Sets the local configuration
	ss.imbue(std::locale(""));

	ss << std::showbase << std::put_money(account->getBalance());

	std::cout << std::locale().name() << ": " << ss.str() << '\n';
	return EXIT_SUCCESS;
}
