
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********/

/* @Version 1.0
 * Derived Class TwoDayShipping
 * Function Definitions
 */

#include "twodayshipping.h"
#include <math.h>
#include <iostream>

// Constructor
TwoDayShipping::TwoDayShipping(std::string nm, std::string adrs,
                               std::string cty, std::string st, double wt,
                               long int zip, double cpo, float ff)
    : Package(nm, adrs, cty, st, wt, zip, cpo) {
  setFlatFee(ff);
}

// set Flat Fee
void TwoDayShipping::setFlatFee(float ff) { flatFee = ff > 0 ? ff : 0; }

// Calculate Cost for TwoDayShipping
double TwoDayShipping::calculateCost() const {
  std::cout.precision(2);
  std::cout << "TOTAL SHIPPING COST : $" << std::fixed
            << ((weight * costPerOz) + flatFee) << std::endl;
}

// Error checking
void TwoDayShipping::checkFee(bool& success) {
  if (flatFee > 1000.00 || flatFee <= 0.00 || isalpha(flatFee) > 0) {
    throw "Not a valid fee weight. Please try again";
    cin >> flatFee;
    success = false;
  }
  success = true;
  return;
}
// output
void TwoDayShipping::print(std::ostream& os) const {
  Package::print(os);  // get output of Package virtual
  os.precision(2);
  os << "The Flat Rate is : $" << std::fixed << flatFee << std::endl;
}
// get input
void TwoDayShipping::getInput(std::istream& is) {
  bool flag;
  Package::getInput(is);  // get input of Package virtual
  std::cout << "Input Flat Rate : ";
  is >> flatFee;
  while (flag == false) {  // error checking
    try {
      checkFee(flag);
    } catch (const char* checkFee) {
      std::cout << checkFee << std::endl;
      is >> flatFee;
    }
  }
}
