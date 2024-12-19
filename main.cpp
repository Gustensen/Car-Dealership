

#include <iostream>
//#include "car.cpp"
using namespace std;
#include "dealership.h"
// Group #2 "Toyota Dealership"
// Date Created: 11/08/2024
// Authors: Vikash Gangabissoon , Taron Robinson, Gustensen Dabresil, Kevin Robinson

void Menu(char option, Dealership &checkOut) {  
  //[Taron, Kevin] Purpose: To create a menu prompts for the user to select,
  // using a switch statment, within a do while loop, so the program wouldn't
  // end until the user selects exit option.
  string carName;
  int filterOption;
  int year;
  int price;
  do {
  cout << "**********************************" << endl;
  cout << "MAIN MENU" << endl;
  cout << "a - Add Car" << endl;
  cout << "b - Remove Car" << endl;
  cout << "c - Min/Max Value Car" << endl;
  cout << "d - Reverse List" << endl;
  cout << "e - Sort List" << endl;
  cout << "f - Search Cars" << endl;
  cout << "g - Modify Car" << endl;
  cout << "h - View Cars" << endl;
  cout << "i - Filter Options" << endl;
  cout << "q - Exit" << endl << endl;

  cout << "Enter your choice: ";

    cin >> option;
  switch(option) {
      case 'a': {
        cout << "**********************************" << endl;
        cout << "Enter the name of the car: ";
        cin.ignore();
        getline(cin, carName);
        cout << "Enter the year of the car: ";
        cin >> year;
        cout << "Enter the price of the car: ";
        cin >> price;
        // Create and add the car to the dealership
        Car vehicle(carName, year, price);
        checkOut.AddCar(vehicle);
        cout << "Car added successfully!" << endl;
        break;
     }
      case 'b': {
        cout << "**********************************" << endl;
        cout << "Enter the name of the car you wish to remove: " << endl;
        cin.ignore();
        getline(cin, carName);
        checkOut.RemoveCar(carName);
        cout << "Car removed successfully!" << endl;
        break;
     }
      case 'c':
        cout << "**********************************" << endl;
        cout << "Minimum Value (1)" << endl;
        cout << "Maximum Value (2)" << endl;
        cout << "Enter 1 or 2: ";
        cin >> filterOption;
        if(filterOption == 1) {
          // minCar object retrieves the car with the minimum price
          Car minCar = checkOut.GetMinVal();
          cout << "Car with the minimum price:" << endl;
          cout << "Model: " << minCar.GetModel() << ", Year: " << minCar.GetYear() << ", Price: $" << 
          minCar.GetPrice() << endl;
        } else if (filterOption == 2) {
          // maxCar object retrieves the car with the maximum price
          Car maxCar = checkOut.GetMaxVal();
          cout << "Car with the maximum price:" << endl;
          cout << "Model: " << maxCar.GetModel() << ", Year: " << maxCar.GetYear() << ", Price: $" << 
          maxCar.GetPrice() << endl;
        } else {
          cout << "Invalid input. Please enter 1 or 2." << endl;
        }
        
        break;
      case 'd':
        cout << "**********************************" << endl;
        checkOut.ReverseSequence(checkOut.PrintDisplay());
        break;
      case 'e':
        cout << "**********************************" << endl;
        checkOut.SortCar(checkOut.PrintDisplay());
        break;
      case 'f':
        cout << "**********************************" << endl;
        cout << "Enter the name of the car to search for: ";
        cin.ignore();
        getline(cin, carName);
        checkOut.SearchCar(carName);
        break;
      case 'g': {
        cout << "**********************************" << endl;
        cout << "What Car do you want to modify?: ";
        cin.ignore();
        getline(cin, carName);
        cout << "What is the new year of the car?" << endl;
        cin >> year;
        cout << "Enter new price: " << endl;
        cin >> price;
       // checkOut.ModifyCarList(carName);
        Car modify;
        modify.SetModel(carName);
        modify.SetYear(year);
        modify.SetPrice(price);
        checkOut.ModifyItem(modify);
        break;
      }
      case 'h':
        cout << "**********************************" << endl;
        checkOut.PrintDisplay();
        break; 
      case 'i':
        cout << "**********************************" << endl;
        cout << "Cars above certain price (1)" << endl;
        cout << "Cars below certain price (2)" << endl;
        cout << "Enter 1 or 2: ";
        cin >> filterOption;
        if(filterOption == 1) {
          cout << "Enter car price: ";
          cin >> price;
          // minCar object retrieves the cars with the lowest prices
          Car minCar = checkOut.FilterOptionsHigh(price);
          
        } else if (filterOption == 2) {
          cout << "Car price: ";
          cin >> price;
          // maxCar object retrieves the cars with the highest prices
          Car maxCar = checkOut.FilterOptionsLow(price);
        } else {
            cout << "Invalid input. Please enter 1 or 2." << endl;
        }
      break;
      case 'q':
        cout << "**********************************" << endl;
        cout << "See you next time!" << endl;
        break;
      default:
        cout << "**********************************" << endl;
        cout << "This is an invalid option." << endl;
        break;

    }

  } while(option != 'q');
  
  
}
int main() { 
  // [Vikash] Purpose: Welcome screen to the program 
  // follwed menu function
  char selectOption = '\0';
  string inputName;
  
  cout << "Welcome to the Toyota Dealership!" <<endl;
  cout << "By: Vikash Gangabissoon" << endl;
  cout << "Taron Robinson" <<endl;
  cout << "Gustensen Dabresil" << endl;
  cout << "Kevin Robinson" << endl << endl;

 // Menu(selectOption);

  cout << "Welcome To A Dealership" << endl;
  cout << "What is your name? ";
  getline(cin, inputName);

  Dealership checkOut(inputName);

  Menu(selectOption, checkOut);

  
}
