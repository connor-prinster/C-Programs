/************************
* A#: A02095542
* Course: CS1400
* CS1400 Section: 1
* CS1405 Section: 3
* HW#: 10
***********************/

//
// Created by Connor Prinster on 3/27/2017.
//

#ifndef HW_10_PIGGY_BANK_PIGGYBANK_H
#define HW_10_PIGGY_BANK_PIGGYBANK_H

#include <array>



class PiggyBank
{
private:
  bool isBroken;
  double savings;

public:
  PiggyBank();
  PiggyBank(double initSavings);

  double getSavings();
  double depositMoney(double deposit);
  double smash();

  ~PiggyBank();
};


#endif //HW_10_PIGGY_BANK_PIGGYBANK_H
