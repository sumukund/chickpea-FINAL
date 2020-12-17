
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********/

/* @Version 1.0
 * Derived Class TwoDayShipping
 *
 */

#include <iostream>
#include "package.h"
#ifndef TWODAYSHIPPING_H
#define TWODAYSHIPPING_H

// Inherits from Package
class TwoDayShipping : public Package {
 public:
  // Constructors
  TwoDayShipping() {}
  TwoDayShipping(std::string, std::string, std::string, std::string, double,
                 long int, double, float = 0.0);

  // setter
  void setFlatFee(float);
  // error handler
  void checkFee(bool &);

  /* virtual */ double calculateCost() const override;
  /* virtual */ void print(std::ostream &os) const override;
  /* virtual */ void getInput(std::istream &is) override;

 private:
  float flatFee;
};

#endif