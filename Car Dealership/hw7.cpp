//@author lukelmiller
#include <iostream>
#include "Car.h"
#include "Dealership.h"
using namespace std;

const char PRINT = '1';
const char CHEAPEST = '2';
const char LOWEST_MILEAGE = '3';
const char BUY = '4';
const char SELL = '5';
const char BALANCE = '6';
const char MY_CHOICE = '7';
const char QUIT = '8';

//------------------------------------------------------
// Name:  Menu
// Purpose:  display the menu of choices to the user
// Parameters: none
// Returns: none
//------------------------------------------------------
void Menu()
{
    cout << endl << "-----Welcome to The Dealership----- "  << endl;
    cout << "Please Choose From the Following Options "     << endl;
    cout << "1. See All Cars"                               << endl
         << "2. See Lowest Price Car"                       <<endl
         << "3. See Lowest Mileage Car"                     << endl
         << "4. Buy a Car to add to the Inventory"          << endl
         << "5. Sell a Car to a Customer"                   << endl
         << "6. See how much Money we have"                 << endl
         << "7. Remove a car from inventory"                          << endl
         << "8. Quit"                                       << endl
         << "Enter your choice: ";
}

//------------------------------------------------------
// Name:  getChoice
// Purpose:  get a (valid) choice from the user
// Parameters: none
// Returns:  a valid selection between PRINT and QUIT
//------------------------------------------------------
char getChoice()
{
char Choice;

   Menu();
   cin >> Choice;
   while (Choice < PRINT || Choice > QUIT)
   {
      cout << "Sorry that is not a valid choice.\n";
      Menu();
      cin >> Choice;
   }
   return Choice;
}

//------------------------------------------------------
// Name:  Sell
// Purpose:  Sell a car to a customer; ask the user
//           what make and model they want to purchase
// Parameters:  The Dealership from which to sell
// Returns:  nothing
//------------------------------------------------------
void Sell (Dealership &Dealer)
{
    string Make, Model;
    cout<< "Which Make?: ";
    cin>> Make;
    cout<< "Which Model?: ";
    cin>> Model;

    if(Dealer.sellCar(Make,Model))
        cout << "\nSOLD\n";
}

//------------------------------------------------------
// Name:  Buy
// Purpose:  Buy a car to add to the inventory
//           Check that we can afford it from money in our balance
//           And that the car isn't already in our inventory
// Parameters:  The Dealership to which to add
// Returns:  nothing
//------------------------------------------------------
void Buy (Dealership &Dealer)
{
    string Make, Model;

    int Cost;
    cout<< "Which Make?: ";
    cin>> Make;
    cout<< "Which Model?: ";
    cin>> Model;
    cout<< "What is the price?: $";
    cin>> Cost;

    if(Dealer.buyCar(Make, Model, Cost))
        cout << "\nCar Bought Successfully\n";


}

int main()
{
    // Declare variables
    Dealership Dealer;
    int carIndex;
    char Choice;

    // The next two lines make numbers appear with ',' between each 3 digits
    locale mylocale("");
    cout.imbue(mylocale);

    // Fill the lot with cars
    if (Dealer.loadInfo("cars.txt"))
    {
        Dealer.setBalance(100000.0);
        cout << "\nThe one and only no-dicker dealership has " << Dealer.getNumCars() << " cars in stock.\n"
             << "We have the world's largest (only) collection of discontinued vehicles.\n"
             << "Good luck finding service on any of these babies!!!\n\n";

        // main loop processing user choices
        Choice = getChoice();
        while (Choice != QUIT)
        {
           switch (Choice)
           {
              case PRINT:{
                  cout<<endl;
                  Dealer.Print();
                    //cout << "Print\n";
              }
                    break;

              case CHEAPEST: {
                  cout<<endl;
                  int index = 0;
                  Dealer.getLowestPrice(index);
                  cout << "Cheapest Car: "; Dealer.Print(index); cout<<endl;

              }
                  break;

              case LOWEST_MILEAGE: {
                  cout<<endl;
                  int index = 0;
                  Dealer.getLowestMileage(index);
                  cout << "Lowest Mileage Car: "; Dealer.Print(index); cout<<endl;

              }
                  break;

              case BUY: {
                  cout<<endl;
                  Buy(Dealer);
              }
                  break;

              case SELL: {
                  cout<<endl;
                  Sell(Dealer);
              }
                  break;

              case BALANCE:  {
                  cout<<endl;
                  float balance = Dealer.getBalance();
                  cout<< "Your Balance is: $"<<balance<<endl;
                  }
                  break;

              case MY_CHOICE: {
                  cout<<endl;
                  int cIndex = 0;
                  cout<<"Which car would you like to remove? Car #";
                  cin>>cIndex;
                  while(cIndex > Dealer.getNumCars() && cIndex < 0){
                    cout<<"Which car would you like to remove? Car #";
                    cin>>cIndex;
                  }
                  if(Dealer.remove(cIndex-1))
                    cout << "\nCar removed.\n";
              }
                  break;

              default:
                  cout << "Not a valid choice.  Should never happen because getChoice does input validation.\n";
           }
           Choice = getChoice();
        }
    }
    else
       cout << "We have no cars to sell.\n";

    cout << " Thank you, come again!" << endl;

    return 0;
}
