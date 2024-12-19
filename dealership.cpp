#include <iostream>
#include <algorithm>
#include "dealership.h"
#include "car.h"
using namespace std;

Dealership::Dealership() {
  userName = "none";
  
}

Dealership::Dealership(string name) {
    userName = name;
}

void Dealership::AddCar(const Car &vehicle) {
  shoppingList.push_back(vehicle);
}

void Dealership::RemoveCar(string carName) {
  bool found = false;

    for (int i = 0; i < shoppingList.size(); i++) {
    if (shoppingList.at(i).GetModel() == carName) {
      //shoppingList.begin() + i is used to erase the index where the element is located.
      shoppingList.erase(shoppingList.begin() + i);
      found = true;
      break;
      cout << endl;
    }
  }

  if(found == false) {
    cout << "Item not found in cart. Nothing removed." << endl;
  }
}

void Dealership::SortCar(const Car &vehicle) {
  // sort the shoppingList in alphabetical order
  sort(shoppingList.begin(), shoppingList.end());
}

string Dealership::SearchCar(string carName) {
  for(int i = 0; i < shoppingList.size(); i++) {
    if(carName == shoppingList.at(i).GetModel()) {
      cout << "Car Found!" << endl;
      cout << "Model: " << shoppingList.at(i).GetModel() << ", Year: " << shoppingList.at(i).GetYear() << ", Price: $" << shoppingList.at(i).GetPrice() << endl;
      return carName;
    }
  }
  cout <<"Car not found" << endl;
  return carName;
}

void Dealership::ModifyItem(const Car& vehicle) {
  bool itemFound = false;

  for(unsigned int i = 0; i < shoppingList.size(); i++){
    //Using pass by reference to get the elements of Car object when modified.
    Car& currCar = shoppingList.at(i);
    //Compares the model of the currCar object with the model of the Car object(vehicle) passed in as a argument.
    if(currCar.GetModel() == vehicle.GetModel()) {
      if(vehicle.GetModel() != "none") {
        currCar.SetModel(vehicle.GetModel());
      }

      if(vehicle.GetPrice() != 0) {
        currCar.SetPrice(vehicle.GetPrice());
      }

      if(vehicle.GetYear() != 0) {
        currCar.SetYear(vehicle.GetYear());
      }

      itemFound = true;
      break;
    }
  }

  if(itemFound == false) {
    cout << "Car not found. Nothing modified." << endl << endl;
  }
}


void Dealership::ReverseSequence(const Car&vehicle) {
   reverse(shoppingList.begin(), shoppingList.end());
}


Car Dealership::GetMaxVal() const {
  if(shoppingList.empty()) {
    cout << "No cars to filter." << endl;
    return Car(); //Returns default car constructor if empty
  } else { 
    Car maxCar = shoppingList.at(0);

    for(int i = 0; i < shoppingList.size(); i++) {
    // Retrieve each car object from the shoppingList
      Car car = shoppingList.at(i);
      if(car.GetPrice() > maxCar.GetPrice()) {
      // Update maxCar if we find a car with a higher price
        maxCar = car;
      }
    }
  return maxCar;
  }
}


Car Dealership::GetMinVal() const {
  if(shoppingList.empty()) {
    cout << "No cars to filter." << endl;
    return Car(); // Return default car obeject if empty
  } else {
    Car minCar = shoppingList.at(0);

    for(int i = 0; i < shoppingList.size(); i++) {
    // Retrieve each car object from the shoppingList once again
      Car car = shoppingList.at(i);
      // Compare the price of the current car with the current minimum car (minCar)
      if(car.GetPrice() < minCar.GetPrice()) {
        minCar = car;
      }
    }
  return minCar;
  }
}

Car Dealership::PrintDisplay() const {
  // Assuming you want to return a Car object, here's an example:
  if (shoppingList.empty()) {
    cout << "No cars in the dealership." << endl;
    return Car();
  } else {
    // Return a car object from your shoppingList
    cout << "CAR LIST:" << endl;
   for (int i = 0; i < shoppingList.size(); i++) {
     cout << "Model: " << shoppingList.at(i).GetModel() << ", Year: " << shoppingList.at(i).GetYear() << ", Price: $" << shoppingList.at(i).GetPrice() << endl;
   }
    // 
    return shoppingList.back();
  }
}

Car Dealership::FilterOptionsHigh(int Hprice) const {

  if(shoppingList.empty()) {
    cout << "No cars to filter." << endl;
    return Car(); //Returns default car object if empty
  } else { 
    
    for(int i = 0; i < shoppingList.size(); i++) {
    //Retrieves the car object at index i from the shoppingList and store/assigns it.
    Car car = shoppingList.at(i);
    if(car.GetPrice() > Hprice){
      cout << "Model: " << shoppingList.at(i).GetModel() << ", Year: " << shoppingList.at(i).GetYear() << ", Price: $" << shoppingList.at(i).GetPrice() << endl;
    } 
    }
  } 
   cout << "No car found" << endl;
    return Car();
}


Car Dealership::FilterOptionsLow(int Lprice) const {

  if(shoppingList.empty()) {
    cout << "No cars to filter." << endl;
    return Car(); //Returns default car object if empty
  } else { 

    for(int i = 0; i < shoppingList.size(); i++) {
    //Retrieves the car object at index i from the shoppingList and store/assigns it.
    Car car = shoppingList.at(i);
    if(car.GetPrice() < Lprice){
      cout << "Model: " << shoppingList.at(i).GetModel() << ", Year: " << shoppingList.at(i).GetYear() << ", Price: $" << shoppingList.at(i).GetPrice() << endl;
    } 
  }
}
  return Car();
}

  




