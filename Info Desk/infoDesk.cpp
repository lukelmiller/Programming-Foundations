//@author lukelmiller
#include <fstream>
#include <iostream>
#include <iomanip>
#include "infoDesk.h"
using namespace std;


//---------- Constructors and Destructors -------------------
//-----------------------------------------------------------
// Name:  Default Constructor
// Sets all the entries in the information table to the empty
// string and sets the number of entries equal to 0.
//-----------------------------------------------------------
infoDesk::infoDesk()
{
    cout << "Default Constructor\n";
    numentries = 0;
    for(int i =0; i<MAX; i++){
       licenseArray[i]= "";        // Array that holds the License number
        companyArray[i] = "";        // Array that holds the Company Name
        webArray[i] = "";
    }


}

//-----------------------------------------------------------
// Name:  Copy Constructor
// Sets all the entries in the information table to the matching
// values in the infoDesk object passed in as a parameter.
// Automatically called when passing an object by value
// or creating an object to be a copy of an existing object
//-----------------------------------------------------------
infoDesk::infoDesk(const infoDesk &Other)
{
    for(int i =0; i<MAX; i++){
       licenseArray[i]= Other.licenseArray[i];        // Array that holds the License number
        companyArray[i] = Other.companyArray[i];       // Array that holds the Company Name
        webArray[i] = Other.webArray[i];
    }
    cout << "Copy Constructor\n";
}

//-----------------------------------------------------------
// Name:  Destructor
// This does nothing since there is no dynamic memory.
//-----------------------------------------------------------
infoDesk::~infoDesk()
{
   cout << "Destructor\n";
}


//------------------ Mutators -------------------
//-----------------------------------------------------------
// Name: LoadFile
// Purpose: Fills in the information table with addresses
// from the filename passed as an arg.
// Arguments: The filename of the file.
// Return:	True if the file opened successfully and
//   the table was successfully
//   populated. False otherwise.
//-----------------------------------------------------------
bool infoDesk::LoadFile(const string filename){
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail())
        return false;

    for (int i = 0; i < MAX; i++){
        if(infile.fail()!= true){
            string look ="";
            infile >> look;
            if(look == "")
                break;
            licenseArray[i]= look;
            infile >> companyArray[i];
            infile >> webArray[i];
            numentries++;

        }

    }
    //cout<<"NUMENTRIES"<<numentries;
    infile.close();
    return true;
}


//-----------------------------------------------------------
// Purpose: Add Company to the information table (based on the
//  arguments passed).
// Arguments: License Number (pass by value string), Company
//    Name (pass by value string) and Web Address
// This function only adds companies to the information table
// if the license number and web address are valid.
// Returns: True if the company information was successfully added, and
//  false otherwise.
//-----------------------------------------------------------
bool infoDesk::AddCompany(string lNum, string name, string website){
    if (ValidLicense(lNum)==true && ValidWeb(website)==true && numentries < MAX){
        //numentries++;
        licenseArray[numentries]= lNum;
        companyArray[numentries] = name;
        webArray[numentries] = website;
        numentries++;
        return true;
    }
    else{
        return false;
    }


}
//-----------------------------------------------------------
// Name:  Delete Last
// Purpose: Deletes the last entry in the table
// Arguments: None
// Returns : Bool - true if successfully deleted
//-----------------------------------------------------------
bool infoDesk::DeleteLast(){
    if(numentries != 0){
        numentries--;
    }
    //numentries--;
    licenseArray[numentries] = "";
    companyArray[numentries] = "";
    webArray[numentries] = "";
    //numentries--;

    return true;
}
//------------------ Accessors -------------------
//-----------------------------------------------------------
// Name:  SearchCompany
// Purpose: Search for the company name using given License number
// Arguments: A License number (pass by value string)
// Returns:   A string which is either a company name or the string "nonexistent".
//-----------------------------------------------------------
string infoDesk::SearchCompany(string search) const{
    for(int i =0; i<MAX; i++){
        if (licenseArray[i]== search)
            return companyArray[i];
    }
    return "nonexistent";
}

//-----------------------------------------------------------
// Name:  ValidLicense
// Purpose: Checks License number format.
// In our case, License number is composed of 8 characters(digits and capital letters)
// and last 4 characters should be digits.
// Arguments: String (pass by value)
// Returns:   true if the arguments is in the proper format
//   and false otherwise.
//-----------------------------------------------------------
bool infoDesk::ValidLicense(string testy) const{
    int test1 = 0;
   int tlength = testy.length();

    for (int i = 4; i< tlength; i++){
        char c =testy[i];
        int x = (int)c - 48;
        if ((x>= 0) && (x<=9)){
            test1++;
        }
    }
    if(testy.length()==VIN_LENGTH && test1 == 4){
        return true;

    }
    else{
        return false;
    }

}
//-----------------------------------------------------------
// Name:  ValidWeb
// Purpose: Checks to make sure the argument is in the format of a
// 	 web address.  That is the string should look like
//        www.*.xyz where * can be any number of letters or
//  characters, and x, y, and z are letters.
// Arguments: A string (pass by value)
// Returns  : true if the argument is in the proper web address
// 	   format and false otherwise.
//-----------------------------------------------------------
bool infoDesk::ValidWeb(string testy) const{
    int test1 = 0;
    int test2 = 0;
    int tlength = testy.length();
    for (int i = 0; i< 3; i++){
        char c =testy[i];
        if (c == 'w'){
            test1++;
        }
    }
    for (int i = (tlength-3); i< tlength; i++){
        char c =testy[i];
        if (isalpha(c)){
            test2++;
        }
    }
    if(test2 == 3 && test1 == 3){
        return true;

    }
    else{
        return false;
    }
}



//-----------------------------------------------------------
// Name:  Print
// Purpose: Prints out the contents of the information table
// 	 to the screen.
// Arguments: None
// Returns : void
//-----------------------------------------------------------
void infoDesk::Print() const{
    for(int i =0; i<MAX; i++){
        cout<< licenseArray[i]<<"   ";
        cout<< companyArray[i]<<"   ";
        cout<< webArray[i]<< endl;
    }
}
