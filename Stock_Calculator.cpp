#include <iostream>
using namespace std;
int main(){
    cout<<"Student ID: 25132743d"<<'\n';
    cout<<"Student Name: Arham KAJANI"<<'\n';
//Declare all variables in one go:
    int user_input;
    double dividend_yield;
    double Dividend_per_share;
    double Price_per_share;
    double Dividend_payout_ratio;
    double Earnings_per_share;
    double Total_dividend_amount;
    double Number_of_shares;
    double Capital_gains_yield;
    double Selling_price;
    double Purchase_price;
//Introduce temp variables so easier to display in switches.
    double temp;
    double temp_2;
    double temp_3;
    double temp_4;
    cout<<'\n';
    do{
        cout<<"Simple Stock Calculator"<<'\n';
        cout<<"1- Calculate Dividend Yield(Dividend Yield (%) = (Dividend per Share / Price per Share) * 100)"<<'\n';
        cout<<"2- Calculate Dividend Payout Ratio(Payout Ratio (%) = (Dividend per Share / Earnings per Share) * 100"<<'\n';
        cout<<"3- Calculate Total Dividend Amount(Total Dividend = Dividend per Share * Number of Shares)"<<'\n';
        cout<<"4- Calculate Total Capital Gains Yield(((Selling Price - Purchase Price)/Purchase Price)*100)"<<'\n';
        cout<<"Enter your choice(1-4) or press 5 to exit: ";
        cin>>user_input;
        switch(user_input){               
            case 1:
                cout<<"Enter the dividend per share: ";
                cin>>Dividend_per_share;
                cout<<"Enter the price per share: ";
                cin>>Price_per_share;   
                temp = (Dividend_per_share/Price_per_share) * 100;
                cout<<"Dividend Yield = "<<temp<<"%"<<'\n';       
                break;
            case 2:
                cout<<"Enter the dividend per share: " ;
                cin>>Dividend_per_share;
                cout<<"Enter the earnings per share: ";
                cin>>Earnings_per_share;
                temp_2= (Dividend_per_share/Earnings_per_share) *100;
                cout << "Dividend Payout Ratio = "<<temp_2<<'\n';
                break;
            case 3:
                cout<<"Enter the dividend per share: ";
                cin>>Dividend_per_share;
                cout<<"Enter the no. of shares: ";
                cin>>Number_of_shares;
                temp_3= Dividend_per_share * Number_of_shares;
                cout<<"Total Dividend Amount= "<<temp_3<<'\n';
                break;
            case 4:
                cout<<"Enter Selling price: ";
                cin>>Selling_price;
                cout<< "Enter Purchase price: ";
                cin>>Purchase_price;
                temp_4 = ((Selling_price - Purchase_price)/Purchase_price) *100;
                cout<< "Capital Gains Yield= "<<temp_4<<"%"<<'\n';
                break;
            default:
//Have to display menu again and ask valid input.
                cout<<"Enter valid choices (1-4)!"<<'\n';
                cout<<'\n';
                break;
// 5 is the exit siwtch displayed as the last option.
            case 5:
                cout<<"Programme Exited";
                break;

        }
//Only ask for input again if user_input != 5.
    }while( user_input!= 5);
    return 0;


}