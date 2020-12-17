
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********/

/* @Version 1.0
 * Derived Class OvernightPackage
 * Function Definitions
 */


#include "overnightpackage.h"
#include <iostream>

// Constructors
OvernightPackage::OvernightPackage(std::string nm, std::string adrs,
                                   std::string cty, std::string st, double wt,
                                   long int zip, double cpo, float fo)
    : Package(nm, adrs, cty, st, wt, zip, cpo) {
  setFeeOz(fo);
}

// calculate package cost
double OvernightPackage::calculateCost() const {
  std::cout.precision(2);
  std::cout << "Overnight Shipping Cost: $" << std::fixed
            << (weight * costPerOz) + (weight * feeOz) << std::endl;
}

// setters
void OvernightPackage::setFeeOz(float fo) { feeOz = fo > 0 ? fo : 00.00; }
// error checker (boolean)
void OvernightPackage::checkFeeOz(bool& success) {
  if (feeOz > 1000.00 || feeOz <= 0.00 || isalpha(feeOz) > 0) {
    throw "Not a valid overnight shipping fee. Please try again";
    std::cin >> feeOz;
    success = false;
  }
  success = true;
  return;
}

// print output
void OvernightPackage::print(std::ostream& os) const {
  Package::print(os);
  os.precision(2);
  os << "\t\tThe Fee Per Ounce is $" << std::fixed << feeOz << std::endl;
}

// get input (plus error checking)
void OvernightPackage::getInput(std::istream& is) {
  bool flag;
  is.clear();
  Package::getInput(is);
  std::cout << "\t\tInput Fee per Ounce for Overnight Shipping: ";
  is >> feeOz;
  while (flag == false) {
    try {
      checkFeeOz(flag);
    } catch (const char* checkFeeOz) {
      std::cout << checkFeeOz << std::endl;
      is >> feeOz;
    }
  }
}
