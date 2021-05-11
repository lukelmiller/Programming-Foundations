//@author lukelmiller
#ifndef CAR_H
#define CAR_H

#include <string>
#include <fstream>
using namespace std;

class Car
{
public:
    //Constructors and destructor
    Car();
    Car(const Car& orig);
    ~Car();

    //Accessors
    string getMake() const;
    string getModel() const;
    float getMileage() const;
    float getDealerCost() const;
    float getRetailPrice() const;

    //Mutators
    bool Read (ifstream &Din);

    void setMake(const string Make);
    void setModel(const string Model);
    void setMileage(const float Mileage);
    void setDealerCost(const float Cost);
    void setRetailPrice(const float Price);

    //Other
    void Print() const;
    bool IsEqualTo(const string Make, const string Model) const;

private:
    string make;
    string model;
    float mileage;
    float d_cost;
    float r_price;

    // Helper Methods
    string toLower(const string S) const;
};
#endif
