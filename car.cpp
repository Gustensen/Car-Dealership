#include <iostream>
#include "car.h"
using namespace std;

//class constructor
Car::Car() {
  carModel = "null";
  carYear = 0;
  carPrice = 0;
}
Car::Car(string Cmodel, int Cyear, int Cprice) {
  carModel = Cmodel;
  carYear = Cyear;
  carPrice = Cprice;
}

void Car::SetModel(string Model) {
  carModel = Model;
}

void Car::SetYear(int Year) {
  carYear = Year;
}

void Car::SetPrice(int price) {
  carPrice = price;
}


string Car::GetModel() const{
  return carModel;
}

int Car::GetYear() const{
  return carYear;
}

int Car::GetPrice() const {
  return carPrice;
}

