//@author lukelmiller
#ifndef DEALERSHIP_H
#define DEALERSHIP_H

#include <string>
#include "Car.h"
using namespace std;

class Dealership
{
public:
    // Constructors and Destructor
    Dealership(const int numCars = 0, const float Balance=0.0);
    Dealership(const Dealership &other);
    ~Dealership();


    // Accessors
    int getNumCars() const;
    float getBalance() const;

    // Mutators
    void setNumCars(const int numCars);
    void setBalance(const float Balance);

    // Useful Methods
    bool loadInfo(const string Filename);
    void Print() const;
    void Print(const int carIndex) const;

    bool remove(const int carIndex);
    bool getLowestPrice(int &carIndex) const;
    bool getLowestMileage(int &carIndex) const;
    bool buyCar(const string Make, const string Model, const int DealerCost);
    bool sellCar(const string Make, const string Model);


private:
    static const int MAXCARS = 12;
    int num_cars;
    float balance;
    Car cars[MAXCARS];

    // Helper Methods
    bool findCar(const string Make, const string Model, int &carIndex) const;
};
#endif
