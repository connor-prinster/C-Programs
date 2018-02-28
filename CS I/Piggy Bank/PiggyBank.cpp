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

#include "PiggyBank.h"
#include <iostream>

using namespace std;

PiggyBank::PiggyBank()
{
  isBroken = false;
  savings = 0.0;
}

PiggyBank::PiggyBank(double initSavings)
{
  isBroken=false;
  savings=initSavings;
}

double PiggyBank::getSavings()
{
  if(!isBroken)
  {
    return savings;
  }
  else
  {
    return savings = 0;
  }

}

double PiggyBank::depositMoney(double deposit)
{
  if(deposit >= 0 && !isBroken)
  {
    savings = savings + deposit;
    return true;
  }
  else
  {
    return false;
  }
}

double PiggyBank::smash()
{
  isBroken = true;
  return savings;
}

PiggyBank::~PiggyBank()
{
  if(isBroken)
  {
    cout << "Poor Broken Pig!" << endl;
  }
};