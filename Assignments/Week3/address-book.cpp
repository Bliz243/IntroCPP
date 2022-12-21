#include <iostream>
#include <string>

using namespace std;

// Maximum number of pages
#define PAGES 50

// Regions in Denmark
enum Region
{
    UNDEFINED,
    HOVEDSTADEN,
    MIDTJILLAND,
    NORDTJILLAND,
    SJAELLAND,
    SYDDANMARK
};

struct page
{
    string firstName;
    string midName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    unsigned int houseNumber;
    unsigned int zipCode;
    Region region;
};

/**
 * Return a string representation of the given region
 */
string regionToText(Region region)
{
    switch (region)
    {
    case UNDEFINED:
        return "Unknown";
    case HOVEDSTADEN:
        return "Hovedstaden";
    case MIDTJILLAND:
        return "Midtjylland";
    case NORDTJILLAND:
        return "Nordjylland";
    case SJAELLAND:
        return "Sjaelland";
    case SYDDANMARK:
        return "Syddanmark";
    default:
        return "Invalid";
    }
}

/**
 * Identifies the region represented by a string
 */
Region textToRegion(string name)
{
    if (name == "Hovedstaden")
        return HOVEDSTADEN;
    if (name == "Midtjylland")
        return MIDTJILLAND;
    if (name == "Nordjylland")
        return NORDTJILLAND;
    if (name == "Sjaelland")
        return SJAELLAND;
    if (name == "Syddanmark")
        return SYDDANMARK;
    else
        return UNDEFINED;
}

/**
 * Returns true if all fields in the page are empty, otherwise false
 */
bool isEmpty(page p)
{
    if (p.region == UNDEFINED && p.firstName == "" && p.midName == "" && p.lastName == "" && p.phoneNumber == "" && p.streetAddress == "" && p.houseNumber == 0 && p.zipCode == 0)
        return true;
    else
        return false;
}

/**
 * Stores contact information in the specified page, if empty
 */
void add(page addressBook[], unsigned int p, string firstName, string midName, string lastName, string phoneNumber, string streetAddress, unsigned int houseNumber, unsigned int zipCode, Region region)
{
    // Ensure that the page exists
    if (p < PAGES)
        // Ensure that the page is empty
        if (isEmpty(addressBook[p]))
        {
            {
                addressBook[p].firstName = firstName;
                addressBook[p].midName = midName;
                addressBook[p].lastName = lastName;
                addressBook[p].phoneNumber = phoneNumber;
                addressBook[p].streetAddress = streetAddress;
                addressBook[p].houseNumber = houseNumber;
                addressBook[p].zipCode = zipCode;
                addressBook[p].region = region;
            }
        }
}

/**
 * Clears the contents of the specified page
 */
void clr(page addressBook[], unsigned int p)
{
    // Ensure that the page exists
    if (p < PAGES)
    {
        addressBook[p].firstName = "";
        addressBook[p].midName = "";
        addressBook[p].lastName = "";
        addressBook[p].phoneNumber = "";
        addressBook[p].streetAddress = "";
        addressBook[p].houseNumber = 0;
        addressBook[p].zipCode = 0;
        addressBook[p].region = UNDEFINED;
    }
}

/**
 * Returns the contents of the specified page
 */
void query(page addressBook[], unsigned int p)
{
    // Ensure that the page exists
    if (p < PAGES)
        // Ensure that the page is not empty
        if (!isEmpty(addressBook[p]))
        {
            {
                cout << addressBook[p].firstName << ",";
                cout << addressBook[p].midName << ",";
                cout << addressBook[p].lastName << ",";
                cout << addressBook[p].phoneNumber << ",";
                cout << addressBook[p].streetAddress << ",";
                cout << addressBook[p].houseNumber << ",";
                cout << addressBook[p].zipCode << ",";
                cout << regionToText(addressBook[p].region);
                cout << endl;
            }
        }
}

int main(void)
{
    string action; // Will contain the user-supplied command
    string firstName;
    string midName;
    string lastName;
    string phoneNumber;
    string streetAddress;
    unsigned int houseNumber;
    unsigned int zipCode;
    string regionName;
    unsigned int p; // Will contain the page number
    page addressBook[PAGES];

    // Initialize address book
    for (int i=0; i < PAGES; i++){
        clr(addressBook, p);
    }

    while (true)
    {
        cin >> action;
        if (action == "add")
        {
            cin >> p;
            cin >> firstName;
            cin >> midName;
            cin >> lastName;
            cin >> phoneNumber;
            cin >> streetAddress;
            cin >> houseNumber;
            cin >> zipCode;
            cin >> regionName;
            add(addressBook, p-1, firstName, midName, lastName, phoneNumber, streetAddress, houseNumber, zipCode, textToRegion(regionName));
        }
        else if (action == "clr")
        {
            cin >> p;
            clr(addressBook, p-1);
        }
        else if (action == "qry")
        {
            cin >> p;
            query(addressBook, p-1);
        }
        else if (action == "quit")
        {
            return 0;
        }
        else
        {
            cout << "ERROR: invalid command" << endl;
            return 1;
        }
    }
}
