#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

bool withdraw(char Title[], int Account_Number, double amount); 
void populate();
void display_ledger();

struct Account {
    char Title[20];
    int Account_Number;
    bool Premium_Account;
    double Balance;
    Account* Next;
};

Account** Ledger = new Account*[8]{0}; 

int main() {

    populate();

    char tayyab[] = "Tayyab";
    char alex[] = "Alex";
    char jeff[] = "Jeff";
    char xavier[] = "Xavier";
    withdraw(tayyab, 1, 80);
    withdraw(alex, 2, 48.5);
    withdraw(jeff, 3, 65.5);
    withdraw(xavier, 4, 87.6);

    display_ledger();

    return 0;
}


bool withdraw(char Title[], int Account_Number, double amount) {

    int c = 0;

    while (Ledger[c] != NULL) {

        if (Account_Number == Ledger[c]->Account_Number) {
            if (strcmp(Title, Ledger[c]->Title) == 0) {

                if (Ledger[c]->Premium_Account) {

                    if (Ledger[c]->Balance >= amount) {
                        Ledger[c]->Balance -= amount;
                        return true;
                    }
                    return false;
                }

                else {

                    double total = amount + (amount * 0.03);

                    if (Ledger[c]->Balance >= total) {
                        Ledger[c]->Balance -= total;
                        return true;
                    }
                    return false;
                }
            }
            else if (Ledger[c]->Next != NULL &&
                     strcmp(Title, Ledger[c]->Next->Title) == 0) {

                if (Ledger[c]->Premium_Account) {

                    double total = amount + (amount * 0.02);

                    if (Ledger[c]->Balance >= total) {
                        Ledger[c]->Balance -= total;
                        return true;
                    }
                    return false;
                }

                else {

                    double total = amount + (amount * 0.05);

                    if (Ledger[c]->Balance >= total) {
                        Ledger[c]->Balance -= total;
                        return true;
                    }
                    return false;
                }
            }

            else
                return false;
        }

        c++;
    }

    return false;
}



void populate() {

    int auto_id = 1;

    Ledger[0] = new Account;
    strcpy(Ledger[0]->Title, "Tayyab");
    Ledger[0]->Account_Number = auto_id++;
    Ledger[0]->Premium_Account = true;
    Ledger[0]->Balance = 100;
    Ledger[0]->Next = NULL;


    Ledger[1] = new Account;
    strcpy(Ledger[1]->Title, "Alex");
    Ledger[1]->Account_Number = auto_id++;
    Ledger[1]->Premium_Account = false;
    Ledger[1]->Balance = 100;
    Ledger[1]->Next = NULL;

    Ledger[2] = new Account;
    strcpy(Ledger[2]->Title, "Jeff");
    Ledger[2]->Account_Number = auto_id++;
    Ledger[2]->Premium_Account = false;
    Ledger[2]->Balance = 100;

    Ledger[2]->Next = new Account;
    strcpy(Ledger[2]->Next->Title, "Tayyab");
    Ledger[2]->Next->Account_Number = Ledger[2]->Account_Number;
    Ledger[2]->Next->Premium_Account = false;
    Ledger[2]->Next->Balance = 100;
    Ledger[2]->Next->Next = NULL;

    Ledger[3] = new Account;
    strcpy(Ledger[3]->Title, "Xavier");
    Ledger[3]->Account_Number = auto_id++;
    Ledger[3]->Premium_Account = false;
    Ledger[3]->Balance = 100;
    Ledger[3]->Next = NULL;


    Ledger[4] = new Account;
    strcpy(Ledger[4]->Title, "Xavier");
    Ledger[4]->Account_Number = auto_id++;
    Ledger[4]->Premium_Account = true;
    Ledger[4]->Balance = 100;
    Ledger[4]->Next = NULL;


    Ledger[5] = NULL;
}



void display_ledger() {

    int c = 0;

    while (Ledger[c] != NULL) {
        if (Ledger[c+1] != NULL &&
            strcmp(Ledger[c]->Title, Ledger[c+1]->Title) == 0) {

            cout << "Title: " << Ledger[c]->Title << " (Dual)" << '\n';

            cout << "Account # "
                 << Ledger[c]->Account_Number
                 << "\t\t"
                 << Ledger[c+1]->Account_Number << '\n';

            cout << "Type: "
                 << (Ledger[c]->Premium_Account ? "Premium" : "Standard")
                 << "\t\t"
                 << (Ledger[c+1]->Premium_Account ? "Premium" : "Standard")
                 << '\n';

            cout << "Balance: $"
                 << fixed << setprecision(2)
                 << Ledger[c]->Balance
                 << "\t\t$"
                 << Ledger[c+1]->Balance << "\n\n";

            c += 2;
        }

        else if (Ledger[c]->Next != NULL) {

            cout << "Title: "
                 << Ledger[c]->Title
                 << "\t\t"
                 << Ledger[c]->Next->Title
                 << " (Shared)\n";

            cout << "Account # "
                 << Ledger[c]->Account_Number << '\n';

            cout << "Type: "
                 << (Ledger[c]->Premium_Account ? "Premium" : "Standard")
                 << '\n';

            cout << "Balance: $"
                 << fixed << setprecision(2)
                 << Ledger[c]->Balance << "\n\n";

            c++;
        }
        else {

            cout << "Title: " << Ledger[c]->Title << '\n';
            cout << "Account # " << Ledger[c]->Account_Number << '\n';

            cout << "Type: "
                 << (Ledger[c]->Premium_Account ? "Premium" : "Standard")
                 << '\n';

            cout << "Balance: $"
                 << fixed << setprecision(2)
                 << Ledger[c]->Balance << "\n\n";

            c++;
        }
    }
}

