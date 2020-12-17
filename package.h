
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********/

/* @Version 1.0
 * This is an abstract base class, Package
 * that will be instantiated by the derived classes.
 *
 */
#include <string.h>
#include <iostream>
#ifndef PACKAGE_H
#define PACKAGE_H

class Package {
 public:
  //constructors and destructors
  Package() {}
  Package(std::string, std::string, std::string, std::string, double, long int,
          float);
  ~Package(){};

/*****************
 * MEMBER FUNCTIONS
 * *****************/

//virtual function to calculate the package cost.
#ifdef _PUREVIRTUAL
  virtual double calculateCost() const = 0;
#else
  virtual double calculateCost() const { return 0.0; }
#endif

// Setters
  void setAddress(std::string);
  void setWeight(double);
  void setZip(long int);
  void setCostPerOz(float);

  // ERROR HANDLERS
  void isStateOk(bool&);
  void error(bool&);
  void weighterror(bool&);
  void cpoerror(bool&);

  // input and output
  //print and getInput are virtual, because the derived classes will use them.
  virtual void print(std::ostream& os) const;
  virtual void getInput(std::istream& is);
  
  friend std::istream& operator>>(std::istream& is, Package& p);
  friend std::ostream& operator<<(std::ostream& os, Package& b);

 protected:
 //variables
  std::string fullName;
  std::string address;
  std::string city;
  std::string state;
  double weight;
  long int zipCode;
  float costPerOz;
 private:
};

#endif