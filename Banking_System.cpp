#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function prototypes
int saving();
int current();
int debit();
int credit();
long long generate_account_no();
int amount_add(string name, int amount);
int amount_sub(string name, int amount);
void balance_inquiry(const string &name);
void print_account_details(const string &name);

int main()
{
    cout << "                ____Welcome To our Program____" << endl
         << endl;
    cout << "          This program is on based Banking system!!" << endl
         << endl;
    cout << "Rule -- To Exit from the program type any other key except given keys!! " << endl;
    char a;
    cout << "Are you opening an account or making a transaction? : " << endl;
    cout << "Enter O or o for opening an account and T or t for the transaction: ";
    cin >> a;
    if (a == 'O' || a == 'o')
    {
        char b;
        cout << "            -------How can I assist You!!------" << endl
             << endl;
        cout << "Which type of account do you want to open: saving or current?" << endl;
        cout << "Type s or S for saving" << endl;
        cout << "Type c or C for current. " << endl
             << endl;
        cout << "Type your move :  ";
        cin >> b;
        if (b == 's' || b == 'S')
        {
            saving();
            system("pause");
             
        }
        else if (b == 'C' || b == 'c')
        {
            current();
            system("pause");
                                 
        }
        else
        {
            cout << "Invalid input!!" << endl;
            system("pause");
                                 
        }
    }
    else if (a == 'T' || a == 't')
    {
        char c;
        cout << "            -------How can I assist You!!-------" << endl
             << endl;
        cout << "Do you want to debit, credit, check balance, or print account details?  " << endl;
        cout << "Type D or d for debit" << endl;
        cout << "Type C or c for credit" << endl;
        cout << "Type B or b for balance inquiry" << endl;
        cout << "Type P or p for printing account details: " << endl
             << endl;
        cout << "Type your move : ";
        cin >> c;
        if (c == 'd' || c == 'D')
        {
            debit();
            system("pause");
                                 
        }
        else if (c == 'C' || c == 'c')
        {
            credit();
            system("pause");
                                 
        }
        else if (c == 'B' || c == 'b')
        {
            string name;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            balance_inquiry(name);
            system("pause");
                                
        }
        else if (c == 'P' || c == 'p')
        {
            string name;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            print_account_details(name);
            system("pause");
                                
        }
        else
        {
            cout << "Invalid input!!" << endl;
            system("pause");
             
        }
    }
    else
    {
        cout << "Invalid input!!" << endl;
        system("pause");
         
    }
    return 0;
}

int saving()
{
    string name, mobile_no, aadhar_no, father_name, address;
    long long Ac_no1;
    int Balance;
    cout << "Provide some required details Like!!__" << endl;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your father's name: ";
    getline(cin, father_name);
    cout << "Enter your mobile number: ";
    cin >> mobile_no;
    cout << "Enter your Aadhar number: ";
    cin >> aadhar_no;
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter the amount that you want to credit: ";
    cin >> Balance;
    Ac_no1 = generate_account_no();

    ofstream file(name + ".txt");
    if (file.is_open())
    {
        file << "User name: " << name << endl;
        file << "Father's name: " << father_name << endl;
        file << "Mobile number: " << mobile_no << endl;
        file << "Aadhar number: " << aadhar_no << endl;
        file << "Permanent Address: " << address << endl;
        file << "Account number: " << Ac_no1 << endl;
        file << "Total balance: " << Balance << endl;
        file.close();
        cout << "Congratulations!! " << name << " Your saving account has been opened successfully!!" << endl;
        cout << "Your account number is: " << Ac_no1 << endl;
        cout << "Your current balance is: " << Balance << endl;
    }
    else
    {
        cout << "Error: Could not connect to the server." << endl;
    }
    return 0;
}

int current()
{
    string name, mobile_no, aadhar_no, father_name, address;
    long long Ac_no1;
    int Balance;
    cout << "Provide some required details like!!__ " << endl;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your father's name: ";
    getline(cin, father_name);
    cout << "Enter your mobile number: ";
    cin >> mobile_no;
    cout << "Enter your Aadhar number: ";
    cin >> aadhar_no;
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter the amount that you want to credit: ";
    cin >> Balance;

    if (Balance > 10000)
    {
        Ac_no1 = generate_account_no();

        ofstream file(name + ".txt");
        if (file.is_open())
        {
            file << "User name: " << name << endl;
            file << "Father's name: " << father_name << endl;
            file << "Mobile number: " << mobile_no << endl;
            file << "Aadhar number: " << aadhar_no << endl;
            file << "Permanent Address: " << address << endl;
            file << "Account number: " << Ac_no1 << endl;
            file << "Total balance: " << Balance << endl;
            file.close();
            cout << "Congratulations!! " << name << " Your current account has been opened successfully!!" << endl;
            cout << "Your account number is: " << Ac_no1 << endl;
            cout << "Your current balance is: " << Balance << endl;
        }
        else
        {
            cout << "Error: Could not connect to the server." << endl;
            cout << "Please try again later!" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Insufficient balance to open a current account!!" << endl;
        return 1;
    }
    return 0;
}

long long generate_account_no()
{
    srand(static_cast<unsigned int>(time(0)));
    long long a = 0;
    for (int i = 0; i < 14; i++)
    {
        int t = rand() % 10;
        a = a * 10 + t;
    }
    return a;
}
int credit()
{
    string Ac, name;
    cout << "Enter your name : ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your account number : ";
    cin >> Ac;

    ifstream file(name + ".txt");
    if (!file.is_open())
    {
        cout << "Error: No account exists with the provided details." << endl;
        return -1;
    }

    string line;
    bool accountFound = false;
    while (getline(file, line))
    {
        // cout << "Debug: Reading line: " << line << endl;
        if (line.find("Account number: " + Ac) != string::npos)
        {
            accountFound = true;
            break;
        }
    }
    file.close();

    if (!accountFound)
    {
        cout << "Error: Account number does not match our records." << endl;
        return -1;
    }

    int amount = 0;
    cout << "Enter the amount that you want to credit: ";
    cin >> amount;

    int newBalance = amount_add(name, amount);
    if (newBalance != -1)
    {
        cout << "Your new balance is : " << newBalance << endl;
    }

    return 0;
}

int debit()
{
    string Ac, name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your account number: ";
    cin >> Ac;

    ifstream file(name + ".txt");
    if (!file.is_open())
    {
        cout << "Error: No account exists with the provided details." << endl;
        return -1;
    }

    string line;
    bool accountFound = false;
    while (getline(file, line))
    {
        // cout << "Debug: Reading line: " << line << endl;
        if (line.find("Account number: " + Ac) != string::npos)
        {
            accountFound = true;
            break;
        }
    }
    file.close();

    if (!accountFound)
    {
        cout << "Error: Account number does not match our records." << endl;
        return -1;
    }

    int amount = 0;
    cout << "Enter the amount that you want to debit : ";
    cin >> amount;

    int newBalance = amount_sub(name, amount);
    if (newBalance != -1)
    {
        cout << "Your new balance is: " << newBalance << endl;
    }

    return 0;
}

int amount_add(string name, int amount)
{
    vector<string> lines;
    string fileName = name + ".txt";
    ifstream file(fileName);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();

        if (!lines.empty())
        {
            int balance = 0;
            // Find the line with "Total balance" and extract the balance value
            for (const auto &l : lines)
            {
                if (l.find("Total balance: ") != string::npos)
                {
                    try
                    {
                        balance = stoi(l.substr(l.find(": ") + 2));
                    }
                    catch (const invalid_argument &e)
                    {
                        cout << "Error: Could not parse balance from file." << endl;
                        return -1;
                    }
                    break;
                }
            }

            balance += amount;

            // Update the balance in the vector
            for (auto &l : lines)
            {
                if (l.find("Total balance: ") != string::npos)
                {
                    l = "Total balance: " + to_string(balance);
                    break;
                }
            }

            ofstream outFile(fileName);
            if (outFile.is_open())
            {
                for (const auto &l : lines)
                {
                    outFile << l << endl;
                }
                outFile.close();
                cout << "Amount added successfully!!" << endl;
                return balance;
            }
            else
            {
                cout << "Error: Could not open file for writing." << endl;
                return -1;
            }
        }
        else
        {
            cout << "Error: File is empty or balance could not be read." << endl;
            return -1;
        }
    }
    else
    {
        cout << "Error: Could not open file for reading. Check file path and permissions." << endl;
        return -1;
    }
}

int amount_sub(string name, int amount)
{
    vector<string> lines;
    string fileName = name + ".txt";
    ifstream file(fileName);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();

        if (!lines.empty())
        {
            int balance = 0;
            // Find the line with "Total balance" and extract the balance value
            for (const auto &l : lines)
            {
                if (l.find("Total balance: ") != string::npos)
                {
                    try
                    {
                        balance = stoi(l.substr(l.find(": ") + 2));
                    }
                    catch (const invalid_argument &e)
                    {
                        cout << "Error: Could not parse balance from file." << endl;
                        return -1;
                    }
                    break;
                }
            }
            if (amount < balance)
                balance -= amount;
            else
            {
                cout << "Oops!! Insufficient balance!!" << endl;
                cout << "Your current balance is : " << balance << endl;
                return -1;
            }

            // Update the balance in the vector
            for (auto &l : lines)
            {
                if (l.find("Total balance: ") != string::npos)
                {
                    l = "Total balance: " + to_string(balance);
                    break;
                }
            }

            ofstream outFile(fileName);
            if (outFile.is_open())
            {
                for (const auto &l : lines)
                {
                    outFile << l << endl;
                }
                outFile.close();
                cout << "Amount deducted successfully!!" << endl;
                return balance;
            }
            else
            {
                cout << "Error: Could not open file for writing." << endl;
                return -1;
            }
        }
        else
        {
            cout << "Error: File is empty or balance could not be read." << endl;
            return -1;
        }
    }
    else
    {
        cout << "Error: Could not open file for reading. Check file path and permissions." << endl;
        return -1;
    }
}

void balance_inquiry(const string &name)
{
    ifstream file(name + ".txt");
    if (!file.is_open())
    {
        cout << "Error: Could not open file for balance inquiry." << endl;
        return;
    }

    string line;
    bool balanceFound = false;
    
    while (getline(file, line))
    {
        // Check if the line contains "Total balance :"
        size_t pos = line.find("Total balance: ");
        // cout << "DEBUG LINE: " << line << endl;
        if (pos != string::npos)
        {
            // Extract the balance value
            string balance = line.substr(pos + 15); // 16 is the length of "Total balance :"
            cout << "Your current balance is: " << balance << endl;
            balanceFound = true;
            break;
        }
    }
    file.close();

    if (!balanceFound)
    {
        cout << "Error: Balance not found." << endl;
    }
}

void print_account_details(const string &name)
{
    ifstream file(name + ".txt");
    if (!file.is_open())
    {
        cout << "Error: Could not open file for printing account details." << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
