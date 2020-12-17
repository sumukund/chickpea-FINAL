/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********/

/* @Version 1.0
 * Derived Class OvernightPackage
 * Header
 */

#include <iostream>
#include "package.h"
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

// inherits from Package

class OvernightPackage : public Package {
 public:
  // Constructors
  OvernightPackage() {}
  OvernightPackage(std::string, std::string, std::string, std::string, double,
                   long int, double, float = 0.0);
  ~OvernightPackage() {}
  // setters
  void setFeeOz(float);
  // error checking
  void checkFeeOz(bool &);
  /* virtual */ double calculateCost() const;
  /* virtual */ void print(std::ostream &os) const;
  /* virtual */ void getInput(std::istream &is);

 private:
  float feeOz;
};

#endif