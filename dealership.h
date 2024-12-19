#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include <string>
#include <vector>
#include "car.h"

using namespace std; 


class Dealership {
  public:
    Dealership();
    Dealership(string name);
    void AddCar(const Car& vehicle);
    void RemoveCar(string carName);
    void SortCar(const Car& vehicle);
    string SearchCar(string carName);
    //string ModifyCarList(string carName);
    void ModifyItem(const Car& vehicle);
    Car FilterOptionsHigh(int Hprice) const;
    Car FilterOptionsLow(int Lprice) const;
    Car GetMaxVal() const; // using Car to easily access the details of the car object.
    Car GetMinVal() const;
    void ReverseSequence(const Car& vehicle);
    Car PrintDisplay() const;
    
  private:
    string userName;
    vector<Car> shoppingList;

};
#endif