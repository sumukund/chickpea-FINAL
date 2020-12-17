
/**********
 * SUDARSNA MUKUND
 * CET 2300
 * Object Oriented Programming
 * FINAL PROJECT
 * Dec 13 2020
 * *********/

/* @Version 1.0
 * Package. Driver Program
 */



#include <iostream>
#include <vector>
#include <iterator>
#include "overnightpackage.cpp"
#include "overnightpackage.h"
#include "package.cpp"
#include "package.h"
#include "twodayshipping.cpp"
#include "twodayshipping.h"

using namespace std;

int main() {

     // Create a few Packages
  vector<Package *>  Packages;
   vector<Package *>::iterator it;
      
   Packages.push_back(new TwoDayShipping);
   Packages.push_back(new TwoDayShipping);
   Packages.push_back(new OvernightPackage);
   Packages.push_back(new OvernightPackage);
   /*
     Display Package Info
   */
 double sum;
   cout << "\n\t\tPACKAGE INFORMATION. Press enter to continue ........" << endl;
   for (it = Packages.begin(); it < Packages.end(); ++it) {
     (*it)->getInput(cin);
     sum += (*it)->calculateCost();
     (*it)->print(cout);
     sum += (*it)->calculateCost();
   }
   
  return 0;

}