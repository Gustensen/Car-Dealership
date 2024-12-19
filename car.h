#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>

using namespace std; 

// [Vikash, Gustensen] Purpose: definition for the Car class, along with its member 
// variables and functions declarations, based on the menu prompts

class Car {
  public:
    Car();
   // Car(string Cmodel, int Cyear, double Cmileage, string CusedOrNew);
    Car(string Cmodel, int Cyear, int Cprice);
    // Car(string Cmodel);
    void SetModel(string model);
    void SetYear(int year);
    void SetPrice(int price);
  //void SetMileage(int mileage);
  //void SetUsedOrNew (string usedOrNew);
    string GetModel() const;
    int GetYear() const;
    int GetPrice() const;
  //int GetMileage() const;
  //string GetUsedOrNew() const;
  //void Print();
  bool operator<(const Car & other) const {
    if (carYear < other.carYear) {
      return true;
    } else if (carYear == other.carYear && carModel < other.carModel) {
      return true;
    } else {
      return false;
    }
    // Overloaded '<' operator to compare two Car objects.
// - First compares the 'carYear' of both cars. If the current car's year is less, it returns true.
// - If the 'carYear' is the same, it then compares the 'carModel' lexicographically (alphabetically).
// - If both 'carYear' and 'carModel' are equal, it returns false, indicating the cars are not "less than" each other.




  }
  private:
    vector<Car> cars;
    string carModel;
    int carYear;
    int carPrice;
};
#endif 