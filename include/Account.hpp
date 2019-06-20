/**
* @file Account.hpp
* @author Gene De Lisa <gene@rockhoppertech.com>
* @version 1.0 6/16/19
*
* @section LICENSE
* Copyright (c) Rockhopper Technologies, Inc. All rights reserved.
*
* Licensed under the MIT License.

* See LICENSE in the project for license information.
*
* @section DESCRIPTION
* The Account class represents an account. :)
*
* @todo clean this up
* @todo the sections above look far to big in the output.
*/

#pragma once

/**
 * @brief A namespace containing Gene's frobs.
 *
 * Right now it contains just the **Account** class.
 *
 * @author Gene
 */
namespace gend {

    // http://www.doxygen.nl/manual/faq.html#faq_code_inc

    /** @class Account Account.hpp "Account.hpp"
     *
     *
     * @brief This is an example class.
     *
     * A non-real world Account that maintains a balance.
     * Nothing exciting.
     *
     * ## Usage:
     *
     *  @code
     *  Account a;
     *  a.deposit(100.0);
     *  a.withdraw(10.0);
     *  std::cout << a.getBalance() << std::endl;
     *  @endcode
     *
     * @note Figuring this doxygen guff out.
     */
    class Account {
      public:
        /**
         * @brief The nondefault default ctor.
         *
         */
        Account();
        /**
         * @brief the destructor.
         *
         * Not really needed since there are no pointers
         *
         */
        virtual ~Account();

        /**
         * @brief deposit money; duh!
         *
         * Increase the account's balance.
         * Just what you'd expext from a deposit function!
         *
         * ## Typical usage:
         *
         * @code
         * Account* account = new Account();
         * account->deposit(100.0);
         * @endcode
         *
         * @param amount double. The amount to deposit
         * @returns void
         *
         *  @todo Fix this I think. Maybe not.
         */
        void deposit(double amount);

        /**
         * @brief remove the amount from the balance.
         *
         */
        void withdraw(double amount);

        /**
         * @brief get the current balance.
         * @returns a double representing the balance
         */
        double getBalance() const;

      private:
        // Superman III FTW!
        // really, double is not good for finance.
        // Use a currency class. Or use int based on pennies.
        double balance{0.0};
    };

} // namespace gend
