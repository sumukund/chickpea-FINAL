
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********
 * Member function definitions for
 * the abstract base class, Package
 *
 * Definitions are not for virtual functions
 *
 * Error and exception handling.
 *
 */
#include "package.h"
#include <ctype.h>
#include <math.h>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

// constructor
Package::Package(std::string fn, std::string adrs, std::string cty,
                 std::string st, double wt, long int zip, float cpo) {
  fullName = fn;
  city = cty;
  state = st;
  setAddress(adrs);
  setWeight(wt);
  setZip(zip);
  setCostPerOz(cpo);
}

// Setters
void Package::setAddress(std::string adrs) { address = adrs; }
void Package::setZip(long int zip) { zipCode = zip > 0 ? zip : 00000; }
void Package::setWeight(double wt) { weight = wt >= 0.00 ? wt : 0.00; }
void Package::setCostPerOz(float cpo) { costPerOz = cpo >= 0.0 ? cpo : 0.0; }

// ERROR HANDLERS (Booleans)
void Package::isStateOk(bool& success) {
  if (state.length() != 2) { //if state is longer than 2 characters
    throw "Input a valid state: ";
    success = false;
  }
  success = true;
  return;
}
void Package::error(bool& success) {
  string str = to_string(zipCode); // to test the length of the zip code
  int len = str.length();
  if (zipCode > 99999 || zipCode < 00000 || len != 5) {
    throw "Not a valid Zip Code";
    success = false;
  }
  success = true;
  return;
}
void Package::weighterror(bool& success) {
  if (weight > 1000.00 || weight <= 0) { // package weight can't be negative
    throw "Not a valid package weight. Please try again";
    cin >> weight;
    success = false;
  }
  success = true;
  return;
}

void Package::cpoerror(bool& success) {
  if (costPerOz > 1000.00 || costPerOz <= 0.00 || isalpha(costPerOz) > 0) { // cost weight can't be negative
    throw "Not a valid cost weight. Please try again";
    cin >> costPerOz;
    success = false;
  }
  success = true;
  return;
}

/******************
 * GET INPUT (With validation)
*******************/
void Package::getInput(std::istream& is) {
  bool flag = false;
  is.ignore();
  std::cout << "Input full name " << std::endl;
  getline(is, fullName); //use getline because a name has a whitespace

  std::cout << "Input Address " << std::endl;
  getline(is, address); // use getline because an address has whitespace

  std::cout << "Input city " << std::endl;
  getline(is, city); // use getline because city could have whitespace

  std::cout << "Input state " << std::endl;
  getline(is, state);
  // ERROR HANDLING
  while (flag == false) {
    try {
      isStateOk(flag);
    } catch (const char* isStateOk) {
      std::cout << isStateOk << std::endl;
      getline(is, state); // loop it so you can keep inputting until correct
    }
  }
  // ERROR HANDLING

  flag = false;
  std::cout << "Input zip code " << std::endl;
  is >> zipCode;
  while (flag == false) {
    try {
      error(flag);
    } catch (const char* error) {
      std::cout << error << std::endl;
      is >> zipCode; // loop it so you can keep inputting until correct
    }
  }
  //ERROR HANDLING
  flag = false;
  std::cout << "Input package weight " << std::endl;
  is >> weight;
  while (flag == false) {
    try {
      weighterror(flag);
    } catch (const char* weighterror) {
      std::cout << weighterror << std::endl;
      is >> weight; // loop it so you can keep inputting until correct
    }
  }
  //ERROR HANDLING

  flag = false;
  std::cout << "Input cost per ounce " << std::endl;
  is >> costPerOz;
  while (flag == false) try {
      cpoerror(flag);
    } catch (const char* cpoerror) {
      std::cout << cpoerror << std::endl;
      is >> costPerOz; // loop it so you can keep inputting until correct
    }
}

// Print All Variables
void Package::print(std::ostream& os) const {
  os << "Full Name : " << fullName << std::endl;
  os << "City : " << city << std::endl;
  os << "Address : " << address << std::endl;
  os << "State : " << state << std::endl;
  os << "Zip Code : " << zipCode << std::endl;
  os << "Package Weight : " << weight << std::endl;
  os.precision(2);
  os << "Cost per Oz : " << fixed << costPerOz << std::endl;
}

// OUTPUT AND INPUT ostream and istream
std::istream& operator>>(std::istream is, Package p) {
  p.getInput(is);
  return is;
}

std::ostream& operator<<(std::ostream& os, const Package& b) {
  b.print(os);
  return os;
}