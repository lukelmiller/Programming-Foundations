//@author lukelmiller
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Dealership.h"
#include "Car.h"
using namespace std;

//------------------ Constructors and Destructor -----------------
// Constructor
Dealership::Dealership(const int numCars, const float Balance)
{
    num_cars = numCars;
    balance = Balance;
    cout << "Constructor\n";
}

// Copy Constructor
Dealership::Dealership(const Dealership &Other)
{
    num_cars = Other.num_cars;
    balance = Other.balance;
    for(int i = 0; i < MAXCARS; i++){
        cars[i] = Other.cars[i];
    }
    cout << "Copy constructor\n";

}

// Destructor
Dealership::~Dealership()
{
   cout << "Destructor\n";
}


//------------------------- Accessors ----------------------------
//----------------------------------------------------------------
// Name:  getNumCars
// Parameters:  none
// Returns:  the value of the int num_cars instance variable
//----------------------------------------------------------------
int Dealership::getNumCars() const
{
   cout << "Getting num_cars\n";
   return num_cars;
}

//----------------------------------------------------------------
// Name:  getBalance
// Parameters:  none
// Returns:  the value of the float balance instance variable
//----------------------------------------------------------------
float Dealership::getBalance() const
{
   cout << "Getting balance\n";
   return balance;
}

//-------------------------- Mutators ----------------------------
//----------------------------------------------------------------
// Name:  setNumCars
// Parameters: the number of cars on the lot, const int
// Returns: nothing
//----------------------------------------------------------------
void Dealership::setNumCars(const int numCars)
{
   cout << "Setting num_cars\n";
   num_cars = numCars;
}


//----------------------------------------------------------------
// Name:  setBalance
// Parameters: the amount of money the dealership has in profit
// Returns: nothing
//----------------------------------------------------------------
void Dealership::setBalance(const float Balance)
{
   cout << "Setting balance\n";
   balance = Balance;
}

//----------------------------------------------------------------
// Name:  sellCar
// Purpose:  sell a car to a customer from the inventory
//           Check that we have the car
//           If that is all okay, show the price to the customer.
//           add the price to the balance, and remove the car from the inventory
// Parameters:  The make and model of the car to buy
// Returns:  bool:  true if the sale worked, false otherwise
//----------------------------------------------------------------
bool Dealership::sellCar(const string Make, const string Model){

    bool sell= false;

    int i = 0;
    if(findCar(Make,Model,i)){

           balance += cars[i].getRetailPrice();
           cout<<"This "<< Model <<" costs: $" << cars[i].getRetailPrice();
           remove(i);
           sell = true;
    }

    return sell;
}


//----------------------------------------------------------------
// Name:  buyCar
// Purpose:  buy a car to add to the inventory.
//           Check that it is unique (no matching car),
//           and that we can afford it, and that the lot is not full.
//           If that is all okay, find out the mileage and set the retail
//           price to a 25% markup over the dealer cost.
// Parameters:  The make and model of the car to buy, and the dealer cost
// Returns:  bool:  true if the purchase worked, false otherwise
//----------------------------------------------------------------

bool Dealership::buyCar(const string Make, const string Model, const int DealerCost){
    bool buy = false;

    bool room =false;
    int k = 0;
    bool doup = findCar(Make, Model, k);

    if(num_cars< MAXCARS)
        room = true;

    if(doup == false && room == true && DealerCost <= balance){
        cout<< "How many miles on the car?: ";
        int Milage;
        cin>> Milage;

        cars[num_cars].setDealerCost(DealerCost);
        cars[num_cars].setMake(Make);
        cars[num_cars].setMileage(Milage);
        cars[num_cars].setModel(Model);
        float RetailPrice = (DealerCost*1.25);
        cars[num_cars].setRetailPrice(RetailPrice);
        num_cars++;
        balance -= DealerCost;
        buy = true;





    }

    return buy;

}
//----------------------------------------------------------------
// Name:  getLowestPrice
// Purpose:  find the array index of the car with the lowest retail price
// Parameters:  The car to fill in the location of the lowest retail price car
//              in the cars array
// Returns:  bool:  true if there is a car for sale, false otherwise
//----------------------------------------------------------------
bool Dealership::getLowestPrice(int &carIndex) const{
    bool found = false;
    for(int i = 0; i < num_cars; i++){
        if(cars[i].getRetailPrice() < cars[carIndex].getRetailPrice()){
            carIndex = i;
            found = true;
        }
    }
    return found;

}
//----------------------------------------------------------------
// Name:  getLowestMileage
// Purpose:  find the array index of the car with the lowest mileage
// Parameters:  The car to fill in the location of the lowest mileage car
//              in the cars array
// Returns:  bool:  true if there is a car for sale, false otherwise
//----------------------------------------------------------------
bool Dealership::getLowestMileage(int &carIndex) const{
    bool found = false;
    for(int i = 0; i < num_cars; i++){
        if(cars[i].getMileage() < cars[carIndex].getMileage()){
            carIndex = i;
            found = true;
        }

    }
    return found;
}

//----------------------------------------------------------------
// Name:  loadInfo
// Purpose:  Fill the array of car instances from the file
//           set num_cars to the number of cars in the file/array
// Parameters:  The filename of the file with the car data in it
// Returns:  bool:  true if the file loaded properly,, false otherwise
//----------------------------------------------------------------
bool Dealership::loadInfo(string fileName)
{
    bool Success = false;

    ifstream infile;
    infile.open(fileName.c_str());
    if (infile.fail())
       cout << "Error, could not open: " << fileName << endl;
    else
    {
       // Call Read from the Car class to fill in one car from
       // one line of the file



       while (num_cars < MAXCARS && !infile.eof()){
           Car car;
           car.Read(infile);
           cars[num_cars] = car;
           num_cars++;
       }  // probably need an && in the boolean expression
       num_cars--;

       // close the file
       infile.close();

       Success = true;

    }

    return Success;
}
//----------------------------------------------------------------
// Name: Remove car
// Purpose:  Removes one car and resorts the stack
// Parameters:  the index of the car to remove
// Returns:  nothing
//----------------------------------------------------------------
bool Dealership::remove(const int carIndex){

    if(carIndex == num_cars){
       cars[num_cars].setDealerCost(0.0);
        cars[num_cars].setMake("");
        cars[num_cars].setMileage(0);
        cars[num_cars].setModel("");
        cars[num_cars].setRetailPrice(0.0);
        num_cars--;
    }else{
        for(int i = carIndex; i<num_cars; i++){
            cars[i].setDealerCost(cars[i+1].getDealerCost());
            cars[i].setMake(cars[i+1].getMake());
            cars[i].setMileage(cars[i+1].getMileage());
            cars[i].setModel(cars[i+1].getModel());
            cars[i].setRetailPrice(cars[i+1].getRetailPrice());
        }
        cars[num_cars].setDealerCost(0.0);
        cars[num_cars].setMake("");
        cars[num_cars].setMileage(0);
        cars[num_cars].setModel("");
        cars[num_cars].setRetailPrice(0.0);
        if(num_cars != 0)
            num_cars--;
    }
    return true;


}





//----------------------------------------------------------------
// Name: Print
// Purpose:  Prints one car to the screen by calling Print on it
// Parameters:  the index of the car to print
// Returns:  nothing
//----------------------------------------------------------------
void Dealership::Print(const int carIndex) const
{
   cout << "Printing one car.\n";
   cars[carIndex].Print();

}

//----------------------------------------------------------------
// Name: Print
// Purpose:  Print all the cars to the screen by calling Print on
//           each element of the cars array
// Parameters:  none
// Returns:  nothing
//----------------------------------------------------------------
void Dealership::Print() const
{
   cout << "Printing all cars on the lot.\n\n";

   //num_cars-1;
   for(int i = 0; i < num_cars; i++){
       cout<<"Car #"<< i+1 <<endl;;
       cars[i].Print();
   }
}

//-------------------- Helper Methods ----------------------------
//----------------------------------------------------------------
// Name:  findCar
// Purpose:  Find a matching car in the array
//           downcase both strings prior to matching them
// Parameters: the make and model of the car to search for (const strings)
//             the index i of the matching car(pass by reference)
//             that holds the result, if found
// Returns: bool: true if the car was found, false otherwise
//----------------------------------------------------------------
bool Dealership::findCar(const string Make, const string Model, int &i) const
{
bool Found;
i = 0;

    while ((i<num_cars) && (!(cars[i].IsEqualTo(Make, Model))))
       i++;

    Found = i<num_cars && cars[i].IsEqualTo(Make, Model);

    return Found;
}
