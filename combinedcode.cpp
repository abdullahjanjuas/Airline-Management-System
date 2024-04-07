#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <string>
#include <regex>
#include <random>
using namespace std;
//globalvariables//
string name, passport;
char gen, DorI, exitChoice;
char Plane[20][8];
int domdestination, intdestination,  domdep, intdep, age, bankdetails, paym;
int flag, temprow, tempcol, seatnum, randnum;
int row, col, time1, dates;
long long cnic, ph_no, acc_num;

void design() {
    cout << "\n\n\n\n\t\t\t***********************************************************************************\n";
    cout << "\t\t\t** _____________________________________________________________________________ **\n";
    cout << "\t\t\t**|                              		                                |**\n";
    cout << "\t\t\t**|                               		                                |**\n";
    cout << "\t\t\t**|                              WELCOME  TO                                    |**\n";
    cout << "\t\t\t**|                                                                             |**\n";
    cout << "\t\t\t**|                       FLIGHT RESERVATION SYSTEM                             |**\n";
    cout << "\t\t\t**|                                                                             |**\n";
    cout << "\t\t\t**|_____________________________________________________________________________|**\n";
    cout << "\t\t\t***********************************************************************************\n\n\n\n";
}

//Username and password
void getUsernameAndPassword(string *user, string *pass) {
    cout << "Enter username:\n";
    cin >> *user;

    cout << "Enter password:\n";
    cin >> *pass;
}

//Domestic booking
void Domesticbooking(){
    flag = 0;
k:
    regex namepattern("[A-Za-z]+");

    while (true) {
        cout << "Enter Name:\n";
        cin >> name;

        if (regex_match(name, namepattern)) {
            cout << "Valid name\n";
            break; // Exit the loop if the input is valid
        } 
        else {
            cout << "Invalid name. Please enter a valid name containing only alphabets.\n";
            // Clear the input buffer to handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }      
l:
    cout << "Enter your age:\n";
    cin >> age;

    if (cin.fail() || age > 99 || age < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a valid age.\n";
        goto l;
    }
c:       
    cout << "Enter CNIC number (without hyphens):\n";
    cin >> cnic;
    if (cin.fail() || cnic <= 1000000000000 || cnic >= 8000000000000) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Entry. Please enter a numeric value.\n";
        goto c;
    }        

    while (true) {
        cout << "Enter your gender (M/F): \n";
        cin >> gen;
        gen = toupper(gen);

        // Check if the input stream enters a failed state
        if (cin.fail() || (gen != 'M' && gen != 'F')) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter 'M' or 'F'. Try Again.\n";
        }
        else if ((gen == 'M' && cnic % 2 == 0) || (gen == 'F' && cnic % 2 != 0)) {
            cout << "Invalid CNIC or Gender. Try Again.\n";
            goto c;
        }
        else if(isdigit(gen) || !isalpha(gen))
            cout << "Invalid input. Please enter 'M' or 'F'. Try Again.\n";                    
        else 
            break;  // Valid input, exit the loop    
    }

m:
    cout << "Enter your phone number: (After +92)\n";
    cin >> ph_no;

    // Validate that the input is a valid numeric value
    if (cin.fail() || ph_no < 3000000000 || ph_no > 3599999999) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid Entry. Please enter a numeric value.\n";
        goto m;
    }    

    cout << "Choose your departure location: \n";
    cout << "1. Karachi\n2. Islamabad\n3. Lahore\n4. Peshawar\n5. Quetta\n";
    cin >> domdep;

    // Validate user input for departure location
    while (cin.fail() || domdep < 1 || domdep > 5) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid Response. Please enter a valid departure location.\n";
        cout << "Choose your departure location: \n";
        cout << "1. Karachi\n2. Islamabad\n3. Lahore\n4. Peshawar\n5. Quetta\n";
        cin >> domdep;
    }

f:
    // displaying available destination locations//
    cout << "Choose your destination: \n";
    cout << "1. Karachi\n2. Islamabad\n3. Lahore\n4. Peshawar\n5. Quetta\n";
    cin >> domdestination;

   if (cin.fail() || (domdestination < 1 || domdestination > 5)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid destination. Please enter a valid number!\n";
        goto f;

    if (domdep == domdestination) {
        cout << "Choose a valid destination!\n";
        goto f;
    }

    cout << "Available dates: \n";

    switch (domdestination) {
        case 1: {
            cout << "1. 05/01/24\n2. 10/01/24\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available departure times are: \n1. 9:00AM\n2. 5:00PM\n";
            cin >> time1;
            cout << "Ticket price: PKR 30,000";
            break;
        }
        case 2: {
            cout << "1. 07/01/24\n2. 15/01/24\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));
            cout << "Available departure times are: \n1. 10:00AM\n2. 7:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 30,000\n";
            break;
        }
        case 3: {
            cout << "1. 08/01/24\n2. 19/01/24\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available departure times are: \n1. 5:00AM\n2. 9:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 20,000\n";
            break;
        }
        case 4: {
            cout << "1. 04/01/24\n2. 14/01/24\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available departure times are: \n1. 6:00AM\n2. 8:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 35,000\n";
            break;
        }
        case 5: {
            cout << "1. 06/01/24\n2. 18/01/24\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available departure times are: \n1. 8:30AM\n2. 7:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            break;
        }
        default: break;
        }
    }
}

//International booking
void Internationalbooking(){
    int i;
    flag = 1;
n:
    regex namepattern("[A-Za-z]+");
    while (true) {
        cout << "Enter Name:\n";
        cin >> name;
        if (regex_match(name, namepattern)) {
            cout << "Valid name\n";
            break; }// Exit the loop if the input is valid
        else {
            cout << "Invalid name. Please enter a valid name containing only alphabets.\n";
            // Clear the input buffer to handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }    
o:
    cout << "Enter your age:\n";
    cin >> age;

    if (cin.fail() || age > 99 || age < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a valid age.\n";
        goto o;
    }

p:
    regex passportpattern("[A-Z]{2}[0-9]{7}");
    while (true) {
        cout << "Enter Passport Number:\n";
        cin >> passport;
        if (regex_match(passport, passportpattern)) {
            cout << "Valid passport number\n";
            break;} // Exit the loop if the input is valid
        else {
            cout << "Invalid passport number. Please try again.\n";
            // Clear the input buffer to handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
x:
    cout << "Enter CNIC number (without hyphens):\n";
    cin >> cnic;
    if (cin.fail() || cnic <= 1000000000000 || cnic >= 8000000000000) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Entry. Please enter a numeric value.\n";
        goto x;
    }

    while (true) {
        cout << "Enter your gender (M/F): \n";
        cin >> gen;
        gen = toupper(gen);        
        if ((gen == 'M' && cnic % 2 == 0) || (gen == 'F' && cnic % 2 != 0)) {
            cout << "Invalid CNIC or Gender. Try Again.\n";
            goto x;}
        
        else if (cin.fail() || (gen != 'M' && gen != 'F')) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter 'M' or 'F'. Try Again.\n";
        }
        else if(isdigit(gen) || !isalpha(gen))
            cout << "Invalid input. Please enter 'M' or 'F'. Try Again.\n";                    
        else 
            break;  // Valid input, exit the loop    
    }


q:
    cout << "Enter your phone number: (After +92)\n";
    cin >> ph_no;
    if (cin.fail() || ph_no < 3000000000 || ph_no > 3599999999) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid Entry. Please enter a numeric value.\n";
        goto q;
    }    

    cout << "Choose your departure location: \n";
    cout << "1. Karachi\n2. Islamabad\n3. Lahore\n";
    cin >> intdep;

    // Validate user input for departure location
    while (cin.fail() || intdep < 1 || intdep > 3) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid Response. Please enter a valid departure location.\n";
        cout << "Choose your departure location: \n";
        cout << "1. Karachi\n2. Islamabad\n3. Lahore\n";
        cin >> intdep;
    }

j:
    // Displaying available destination locations//
    cout << "Choose your destination: \n";
    cout << "1. Turkey\n2. Saudi Arabia\n3. England\n4. Argentina\n5. India\n";
    cin >> intdestination;

    // Validate user input for destination location
    while (cin.fail() || intdestination < 1 || intdestination > 5) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid Response. Please enter a valid destination.\n";
        cout << "Choose your destination: \n";
        cout << "1. Turkey\n2. Saudi Arabia\n3. England\n4. Argentina\n5. India\n";
        cin >> intdestination;
    }

    cout << "Available dates: \n";
    switch (intdestination) {
        case 1: {
            cout << "1. 05/01/23\n2. 10/01/23\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available times: \n1. 9:00AM\n2. 5:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 100,000\n";
            break;
        }
        case 2: {
            cout << "1. 07/01/23\n2. 15/01/23\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available times: \n1. 10:00AM\n2. 7:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 120,000\n";
            break;
        }
        case 3: {
            cout << "1. 08/01/23\n2. 19/01/23\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available times: \n1. 5:00AM\n2. 9:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 150,000\n";
            break;
        }
        case 4: {
            cout << "1. 04/01/23\n2. 14/01/23\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available times: \n1. 6:00AM\n2. 8:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 200,000\n";
            break;
        }
        case 5: {
            cout << "1. 06/01/23\n2. 18/01/23\n";
            do {
                cout << "Enter your choice for date: ";
                cin >> dates;

                if (cin.fail() || (dates != 1 && dates != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for date.\n";
                }
            } while (cin.fail() || (dates != 1 && dates != 2));

            cout << "Available times: \n1. 8:30AM\n2. 7:00PM\n";
            do {
                cout << "Enter your choice for departure time: ";
                cin >> time1;

                if (cin.fail() || (time1 != 1 && time1 != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid choice for departure time.\n";
                }
            } while (cin.fail() || (time1 != 1 && time1 != 2));
            cout << "Ticket price: PKR 130,000\n";
            break;
        }
        default: break;
    }
}
// Function to view a booked ticket
void viewTicket(string *user, string *pass) {
    string directoryPath = "C:/Users/hp/Desktop/Final Project/";
    string nameOfFile = *user + *pass + ".txt";

    // Concatenate the directory path with the modified file name and extension
    string filePath = directoryPath + nameOfFile;

    ifstream file(filePath);

    if (!file.is_open()) // Condition to check whether the file exists
    {
        cout << "Nothing to see here!" << endl;
    } 
    else 
    {
        string show;

        while (getline(file, show)) // Reads content from the file line by line
        {
            cout << show << endl;
        }
    }
}

// function to cancel ticket
void cancelTicket(string *user, string *pass) 
{
    string onepath = *user + *pass + ".txt";
    const char* directoryPath = "C:/Users/hp/Desktop/Final Project/";
    const char* nameOfFile = onepath.c_str();  // Convert C++ string to C-string

    // Concatenate the directory path with the modified file name and extension
    char filePath[200];
    sprintf(filePath, "%s%s", directoryPath, nameOfFile);

    if (remove(filePath) == 0)  // remove returns 0 if successful
    { 
        cout << "\n Your ticket has been CANCELLED. ";
        cout << "Contact Head Office for refund queries! \n\n";
    } 
    else 
    {
        cout << "\n NO TICKET has been reserved on this account. \n\n";
    }
}

//Seat details
void seatdetails() {    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++) {
            Plane[i][j] = '_';
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 3; j < 5; j++) {
            Plane[i][j] = ' ';
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 5; j < 8; j++) {
            Plane[i][j] = '_';
        }
    }
    // Randomly booking seats for a more realistic simulation
    int randrow;
    int randcol = 2;

    for (int i = 0; i < 20; i++) {
        randrow = rand() % 20;
        randcol = rand() % 8;
        if (randcol != 3 && randcol != 4 && randcol != 5) {
            Plane[randrow][randcol] = 'B';
        }
    }
}

//Display Seats
void displayseats() {
    cout << "\nSeats available are: \n\n";
    cout << "   1 2 3     4 5 6\n";
    int i, j;
    for (i = 0; i < 20; i++) {
        if (i <= 9)
            cout << i + 1 << " ";
        else if (i > 9)
            cout << i + 1 << " ";
        for (j = 0; j < 8; j++)
            cout << Plane[i][j] << " ";
        cout << "\n";
    }
}

void seatnumber() {
    while (1) {
    t:
    cout << "Which seat do you want to Book?\n";
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> col;

    // Validate user input for row and column
    while (cin.fail() || row > 20 || col > 6 || row < 1 || col < 1) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid input. Please enter valid values for row and column.\n";
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
    }

        temprow=row;
        tempcol=col;

        if (col <= 3) {
            if (Plane[row - 1][col - 1] != 'B') {
                cout << "Seat Confirmed." << endl;
                break;
            }
        } 
        else if (col > 3) {
            if (row <= 9) {
                if (Plane[row - 1][col + 1] != 'B') {
                    cout << "Seat Confirmed." << endl;
                    break;
                }
            } 
            else if (row > 9) {
                if (Plane[row - 1][col + 1] != 'B') {
                    cout << "Seat Confirmed." << endl;
                    break;
                }
            }
        }
        cout << "Sorry this seat is Already Booked\n";
        cout << "Please select another seat." << endl;
    }
}

//Pay details
void paydetails() {
r:
    cout << "Choose payment method:\n";
    cout << "1. Credit card\n2. Bank Transfer\n3. Easypaisa\n4. Jazzcash\n5. Sadapay\n";
    cin >> paym;

    if (cin.fail() || paym < 1 || paym > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Response. Please enter a number between 1 and 5.\n";
        goto r;
    }

    switch (paym) {
        case 1: {
            cout << "Enter card Number:\n";
            cin >> acc_num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid card number. Please enter a valid number.\n";
                goto r;
            }
            break;
        }
        case 2: {
        s:
            cout << "Bank Name:\n";
            cout << "1. HBL\n2. UBL\n3. Askari\n4. NBL\n5. AlFalah\n6. BOP\n7. HabibMetro\n";
            cin >> bankdetails;

            if (cin.fail() || bankdetails < 1 || bankdetails > 7) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Response. Please enter a number between 1 and 7.\n";
                goto s;
            }
            v:
            cout << "Enter account number:\n";
            cin >> acc_num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid account number. Please enter a valid number.\n";
                goto v;
            }
            break;
        }
        case 3: {
            cout << "Enter EasyPaisa Account Number (Mobile Number):\n";
            cin >> acc_num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid account number. Please enter a valid number.\n";
                goto r;
            }
            break;
        }
        case 4: {
            cout << "Enter JazzCash Account Number (Mobile Number):\n";
            cin >> acc_num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid account number. Please enter a valid number.\n";
                goto r;
            }
            break;
        }
        case 5: {
            cout << "Enter SADA PAY Account Number:\n";
            cin >> acc_num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid account number. Please enter a valid number.\n";
                goto r;
            }
            break;
        }
    }
}

//Display Ticket
void displayticket() {
    temprow = row;
    tempcol = col;

    random_device rd;
    mt19937 gn(rd());
    uniform_int_distribution<int> distribution(10000, 99999);
    randnum = distribution(gn);

    cout << "********************************************";
    cout << "********************************************\n";
    cout << "\t\t\t\t\t\tTicket Number : " << randnum << "\n";
    cout << "NAME: " << name << "\n";
    cout << "CNIC: " << cnic << "\n";
    
    // If the user is Booking an international flight
    if (flag == 1) {
        cout << "PASSPORT NO: " << passport << "\n";
    }
    
    cout << "GENDER: " << gen << "\n";
    cout << "AGE: " << age << "\n";
    cout << "PHONE NO: 0" << ph_no << "\n";
    seatnum = 6 * (temprow - 1) + tempcol;
    cout << "SEAT NO: " << seatnum << "\n";
    cout << "DEPARTURE: ";

    if (flag == 0) {
        switch (domdep) {
            case 1: cout << "KARACHI\n"; break;
            case 2: cout << "ISLAMABAD\n"; break;
            case 3: cout << "LAHORE\n"; break;
            case 4: cout << "PESHAWAR\n"; break;
            case 5: cout << "QUETTA\n"; break;
            default: break;
        }
    }

    if (flag == 1) {
        switch (intdep) {
            case 1: cout << "KARACHI\n"; break;
            case 2: cout << "ISLAMABAD\n"; break;
            case 3: cout << "LAHORE\n"; break;
            default: break;
        }
    }

    cout << "DESTINATION: ";

    if (flag == 0) {
        switch (domdestination) {
            case 1: cout << "KARACHI\n"; break;
            case 2: cout << "ISLAMABAD\n"; break;
            case 3: cout << "LAHORE\n"; break;
            case 4: cout << "PESHAWAR\n"; break;
            case 5: cout << "QUETTA\n"; break;
            default: break;
        }
    }

    if (flag == 1) {
        switch (intdestination) {
            case 1: cout << "TURKEY\n"; break;
            case 2: cout << "SAUDI ARABIA\n"; break;
            case 3: cout << "ENGLAND\n"; break;
            case 4: cout << "ARGENTINA\n"; break;
            case 5: cout << "ENGLAND\n"; break;
            default: break;
        }
    }

    cout << "DATE AND TIME: ";
    
    if (flag == 0) {
        switch (domdestination) {
            case 1: {
                switch (time1) {
                    case 1: cout << "05/01/24 - 9:00 AM\n"; break;
                    case 2: cout << "10/01/24 - 5:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 2: {
                switch (time1) {
                    case 1: cout << "07/01/24 - 10:00 AM\n"; break;
                    case 2: cout << "15/01/24 - 7:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 3: {
                switch (time1) {
                    case 1: cout << "08/01/24 - 5:00 AM\n"; break;
                    case 2: cout << "19/01/24 - 9:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 4: {
                switch (time1) {
                    case 1: cout << "04/01/24 - 6:00 AM\n"; break;
                    case 2: cout << "14/01/24 - 8:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 5: {
                switch (time1) {
                    case 1: cout << "06/01/24 - 8:30 AM\n"; break;
                    case 2: cout << "18/01/24 - 7:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            default: break;
        }
    }

    if (flag == 1) {
        switch (intdestination) {
            case 1: {
                switch (time1) {
                    case 1: cout << "05/01/24 - 9:00 AM\n"; break;
                    case 2: cout << "10/01/24 - 5:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 2: {
                switch (time1) {
                    case 1: cout << "07/01/24 - 10:00 AM\n"; break;
                    case 2: cout << "15/01/24 - 7:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 3: {
                switch (time1) {
                    case 1: cout << "08/01/24 - 5:00 AM\n"; break;
                    case 2: cout << "19/01/24 - 9:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 4: {
                switch (time1) {
                    case 1: cout << "04/01/24 - 6:00 AM\n"; break;
                    case 2: cout << "14/01/24 - 8:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            case 5: {
                switch (time1) {
                    case 1: cout << "06/01/24 - 8:30 AM\n"; break;
                    case 2: cout << "18/01/24 - 7:00 PM\n"; break;
                    default: break;
                }
                break;
            }
            default: break;
        }
    }

    cout << "TICKET PRICE: ";
    
    if (flag == 0) {
        switch (domdestination) {
            case 1: cout << "PKR 30,000\n"; break;
            case 2: cout << "PKR 30,000\n"; break;
            case 3: cout << "PKR 20,000\n"; break;
            case 4: cout << "PKR 35,000\n"; break;
            case 5: cout << "PKR 25,000\n"; break;
            default: break;
        }
    }

    if (flag == 1) {
        switch (intdestination) {
            case 1: cout << "PKR 100,000\n"; break;
            case 2: cout << "PKR 120,000\n"; break;
            case 3: cout << "PKR 150,000\n"; break;
            case 4: cout << "PKR 200,000\n"; break;
            case 5: cout << "PKR 110,000\n"; break;
            default: break;
        }
    }

    cout << "PAID THROUGH: ";
    
    switch (paym) {
        case 1: cout << "CREDIT CARD\n"; break;
        case 2: cout << "BANK TRANSFER\n"; break;
        case 3: cout << "EASYPAISA\n"; break;
        case 4: cout << "JAZZCASH\n"; break;
        case 5: cout << "SADAPAY\n"; break;
        default: break;
    }

    cout << "****************************************************************************************\n";
}

//File Handling
void save_data_into_file(string *user, string *pass)
{
    // Specify the directory path where you want to save the file
    string directoryPath = "C:/Users/hp/Desktop/Final Project/";
    string nameOfFile = *user + *pass + ".txt";

    // Concatenate the directory path with the modified file name and extension
    string filePath = directoryPath + nameOfFile;

    ofstream outFile(filePath, ios::app); 

    if (outFile.is_open()) 
    {        
        outFile << "********************************************";
        outFile << "********************************************\n";
        outFile << "\t\t\t\t\t\tTicket Number : " << randnum << "\n";
        outFile << "NAME: " << name << "\n";
        outFile << "CNIC: " << cnic << "\n";
        outFile << "PASSPORT NO: " << passport << "\n";
        outFile << "GENDER: " << gen << "\n";
        outFile << "AGE: " << age << "\n";
        outFile << "PHONE NO: 0" << ph_no << "\n";
        seatnum = 6 * (temprow - 1) + tempcol;
        outFile << "SEAT NO: " << seatnum << "\n";
        outFile << "DEPARTURE: ";

        if (flag == 0) {
            switch (domdep) {
                case 1: outFile << "KARACHI\n"; break;
                case 2: outFile << "ISLAMABAD\n"; break;
                case 3: outFile << "LAHORE\n"; break;
                case 4: outFile << "PESHAWAR\n"; break;
                case 5: outFile << "QUETTA\n"; break;
                default: break;
            }
        }

        if (flag == 1) {
            switch (intdep) {
                case 1: outFile << "KARACHI\n"; break;
                case 2: outFile << "ISLAMABAD\n"; break;
                case 3: outFile << "LAHORE\n"; break;
                default: break;
            }
        }

        outFile << "DESTINATION: ";

        if (flag == 0) {
            switch (domdestination) {
                case 1: outFile << "KARACHI\n"; break;
                case 2: outFile << "ISLAMABAD\n"; break;
                case 3: outFile << "LAHORE\n"; break;
                case 4: outFile << "PESHAWAR\n"; break;
                case 5: outFile << "QUETTA\n"; break;
                default: break;
            }
        }

        if (flag == 1) {
            switch (intdestination) {
                case 1: outFile << "TURKEY\n"; break;
                case 2: outFile << "SAUDI ARABIA\n"; break;
                case 3: outFile << "ENGLAND\n"; break;
                case 4: outFile << "ARGENTINA\n"; break;
                case 5: outFile << "ENGLAND\n"; break;
                default: break;
            }
        }

        outFile << "DATE AND TIME: ";
    
        if (flag == 0) {
            switch (domdestination) {
                case 1: {
                    switch (time1) {
                    case 1: outFile << "05/01/24 - 9:00 AM\n"; break;
                    case 2: outFile << "10/01/24 - 5:00 PM\n"; break;
                    default: break;
                }
                break;
            }
                case 2: {
                    switch (time1) {
                        case 1: outFile << "07/01/24 - 10:00 AM\n"; break;
                        case 2: outFile << "15/01/24 - 7:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                case 3: {
                    switch (time1) {
                        case 1: outFile << "08/01/24 - 5:00 AM\n"; break;
                        case 2: outFile << "19/01/24 - 9:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                case 4: {
                    switch (time1) {
                        case 1: outFile << "04/01/24 - 6:00 AM\n"; break;
                        case 2: outFile << "14/01/24 - 8:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                case 5: {
                    switch (time1) {
                        case 1: outFile << "06/01/24 - 8:30 AM\n"; break;
                        case 2: outFile << "18/01/24 - 7:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                default: break;
            }
        }

        if (flag == 1) {
            switch (intdestination) {
                case 1: {
                    switch (time1) {
                        case 1: outFile << "05/01/24 - 9:00 AM\n"; break;
                        case 2: outFile << "10/01/24 - 5:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                case 2: {
                    switch (time1) {
                        case 1: outFile << "07/01/24 - 10:00 AM\n"; break;
                        case 2: outFile << "15/01/24 - 7:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                case 3: {
                    switch (time1) {
                        case 1: outFile << "08/01/24 - 5:00 AM\n"; break;
                        case 2: outFile << "19/01/24 - 9:00 PM\n"; break;
                        default: break;
                    }   
                    break;
                }
                case 4: {
                    switch (time1) {
                        case 1: outFile << "04/01/24 - 6:00 AM\n"; break;
                        case 2: outFile << "14/01/24 - 8:00 PM\n"; break;
                        default: break;
                    }   
                    break;
                }
                case 5: {
                    switch (time1) {
                        case 1: outFile << "06/01/24 - 8:30 AM\n"; break;
                        case 2: outFile << "18/01/24 - 7:00 PM\n"; break;
                        default: break;
                    }
                    break;
                }
                default: break;
            }
        }

        outFile << "TICKET PRICE: ";
    
        if (flag == 0) {
            switch (domdestination) {
                case 1: outFile << "PKR 30,000\n"; break;
                case 2: outFile << "PKR 30,000\n"; break;
                case 3: outFile << "PKR 20,000\n"; break;
                case 4: outFile << "PKR 35,000\n"; break;
                case 5: outFile << "PKR 25,000\n"; break;
                default: break;
            }
        }

        if (flag == 1) {
            switch (intdestination) {
                case 1: outFile << "PKR 100,000\n"; break;
                case 2: outFile << "PKR 120,000\n"; break;
                case 3: outFile << "PKR 150,000\n"; break;
                case 4: outFile << "PKR 200,000\n"; break;
                case 5: outFile << "PKR 110,000\n"; break;
                default: break;
            }
        }

        outFile << "PAID THROUGH: ";
    
        switch (paym) {
            case 1: outFile << "CREDIT CARD\n"; break;
            case 2: outFile << "BANK TRANSFER\n"; break;
            case 3: outFile << "EASYPAISA\n"; break;
            case 4: outFile << "JAZZCASH\n"; break;
            case 5: outFile << "SADAPAY\n"; break;
            default: break;
        }   

        outFile << "****************************************************************************************\n";

        outFile.close();
    } 

    else 
    {
        cerr << "Failed to open file: " << filePath << endl;
    }
}

//

//Main Function
//(&user,&pass)
//(string *user, string *pass)
int main() 
{    
    system("cls");
    string user, pass;
a:
    design();
    getUsernameAndPassword(&user,&pass);

    for (;;) {
    cout << "\t\t\tTo book a Domestic flight (Enter D)\n";
    cout << "\t\t\tTo book an International flight (Enter I)\n";
    cout << "\t\t\tTo Cancel a flight (Enter C)\n";
    cout << "\t\t\tTo View your ticket (Enter V)\n";

    cin >> DorI;
    DorI = toupper(DorI);

    // Check if the input stream enters a failed state
    if (cin.fail()) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
        cout << "Invalid input. Please enter a valid character. Try Again.\n";
    } 
    else {
        if (DorI == 'D') {
            Domesticbooking();
            break;
        } else if (DorI == 'I') {
            Internationalbooking();
            break;
        } else if (DorI == 'V') {
            viewTicket(&user,&pass);
            goto b;
            break;
        } else if (DorI == 'C') {
            cancelTicket(&user,&pass);
            goto b;
            break;
        } else 
            cout << "Please choose from the available options\n";
        break;        
    }
}

    seatdetails();
    displayseats();
    seatnumber();
    paydetails();
    displayticket();	
    save_data_into_file(&user,&pass);
b:
    
    // Get user input for exit choice
    do {        
        cout << "\nDo you want to exit? (Y/N)\n";
        cin >> exitChoice;
        exitChoice = toupper(exitChoice);

        if (exitChoice == 'Y') {
            cout << "\n\tHave a Safe Journey! \n\n\n\n"; break;
        }
        else if (exitChoice == 'N') 
            goto a;
        else if(isdigit(exitChoice) || !isalpha(exitChoice))
            cout << "Invalid Entry! Select Again! ";
        else 
            cout << "Invalid Entry! Select Again! ";
        
        // Clear any input errors and ignore invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (exitChoice != 'Y' && exitChoice != 'N');

    return 0;
}