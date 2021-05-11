//@author lukelmiller
#include <iostream>
#include "Car.h"
using namespace std;

//------------ Constructors & Destructors --------------
Car::Car()
{
    make = "";
    model = "";
    mileage = 0.0;
    d_cost = 0.0;
    r_price = 0.0;
}

Car::Car(const Car &other)
{
    make = other.make;
    model = other.model;
    mileage = other.mileage;
    d_cost = other.d_cost;
    r_price = other.r_price;
}

Car::~Car()
{
}

//----------------------- Accessors --------------------
string Car::getMake() const
{
    return make;
}

string Car::getModel() const
{
    return model;
}

float Car::getMileage() const
{
    return mileage;
}

float Car::getDealerCost() const
{
    return d_cost;
}

float Car::getRetailPrice() const
{
    return r_price;
}


//----------------------- Mutators ---------------------
void Car::setMake(const string Make)
{
    make = Make;
}

void Car::setModel(const string Model)
{
    model = Model;
}

void Car::setMileage(const float Mileage)
{
    mileage = Mileage;
}

void Car::setDealerCost(const float Cost)
{
    d_cost = Cost;
}

void Car::setRetailPrice(const float Price)
{
    r_price = Price;
}

bool Car::Read(ifstream &Din)
{
    Din >> make >> model >> mileage >> d_cost >> r_price;
    return (!Din.fail());
}

//-------------------- Other Methods -------------------
void Car::Print() const
{
    // these two lines print numbers with ',' after 3 digits
    locale mylocale("");
    cout.imbue(mylocale);

    cout << "Make: " << make << endl
    << "Model: " << model << endl
    << "Mileage: " << mileage << endl
    << "Dealer Cost: " << "$" << d_cost << endl
    << "Retail Price: " << "$" << r_price << endl << endl;
}

bool Car::IsEqualTo(const string Make, const string Model) const
{
   return ((toLower(make) == toLower(Make) &&
           toLower(model) == toLower(Model)));

}

//------------------ Private Helper Methods -------------
string Car::toLower (const string S) const
{
string Lower = "";

    for (unsigned int i = 0; i < S.length(); i++)
       Lower += tolower(S[i]);

    return Lower;
}
