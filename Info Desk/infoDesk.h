//@author lukelmiller
#include <string>
using namespace std;
class infoDesk
{
	public:
        // Constructors and Destructors
		infoDesk();                         // Default Constructor
		infoDesk(const infoDesk& Other);    // Copy Constructor
		~infoDesk();                        // Destructor


        // Mutators
		bool LoadFile(const string Filename);
		bool AddCompany(const string License, const string Company, const string Web);
                bool DeleteLast();

        // Accessors
		string SearchCompany(const string query) const;

        // Other Methods
        void Print() const;
		bool ValidWeb(const string query) const;
		bool ValidLicense(const string query) const;


	private:
		static const int MAX = 6;        // Capacity of the table
		static const int VIN_LENGTH = 8; // Number of chars in a valid license

		int numentries;		             // Current number of entries in the lookup table
		string licenseArray[MAX];        // Array that holds the License number
		string companyArray[MAX];        // Array that holds the Company Name
		string webArray[MAX];            // Array that holds the web URLs
};
