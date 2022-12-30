//
//  main.cpp
//  hotel_management
//
//  includes information of hotel items, rooms, ordered food, number of rooms allocated to them, sales and remaining food stocks, total collection of the day
//

#include <iostream>
#include <iomanip>
#include "helpers.h"

using namespace std;



int main(int argc, const char * argv[])
{
    int quant, choice;
    
    //Quantity
    int qRooms=0, qPizza=0, qBurger=0, qNoodles=0, qShakes=0, qSushi=0;
    //Sold
    int soldRooms=0, soldPizza=0, soldBurger=0, soldNoodles=0, soldShake=0, soldSushi=0;
    //Price
    int priceRooms=140, pricePizza=4.99, priceBurger=3.99, priceNoodles=2.99, priceShake=1.99, priceSushi=5.99;
    //Total price of items
    int totalRooms=0, totalPizza=0, totalBurger=0, totalNoodles=0, totalShake=0, totalSushi=0;
    
    cout << "---------------------------------------------------------------------" << endl;
    cout << setw(45) <<"HOTEL INFORMATION" << endl;
    cout << "---------------------------------------------------------------------" << endl << endl;
   
    cout << "   Number of rooms available: ";
   
    while (true)
      {
          cin >> qRooms;
          if (cin)
              break;

            cin.clear();
            cin.ignore();
          cout << "   Invalid input. Try again, please!\n\n";
          cout << "   Number of rooms available: ";
      }
    
    cout << "\n\t  Quantity of food items available:  \n";
    cout << "  Quantity of pizza: ";
    cin >> qPizza;
    cout << "  Quantity of burgers: ";
    cin >> qBurger;
    cout << "  Quantity of noodles: ";
    cin >> qNoodles;
    cout << "  Quantity of shakes: ";
    cin >> qShakes;
    cout << "  Quantity of sushi: ";
    cin >> qSushi;
    
    
    cout << "\n\n---------------------------------------------------------------------" << endl;
    cout << setw(40) <<"MAIN MENU" << endl;
    cout << "---------------------------------------------------------------------" << endl << endl;
    
    m:
    displayMainMenu();

    cout << "   ---: ";
    cin >> choice;
    cin.ignore();
    cout << endl;
    
    switch (choice)
    {
        case 1:
        {
            cout << setw(15) << " " << "Enter the number of rooms to reserve: ";
            cin >> quant;
            
            if (qRooms-soldRooms>=quant)
            {
                soldRooms += quant;
                totalRooms += quant*priceRooms;
                cout << setw(15) << " " << "Message: " << quant << " room(s) have been alloted to you!\n\n";
            }
            else
            {
                cout << setw(15) << " " << "Message: Sorry! Only " << qRooms-soldRooms << " room(s) available.\n\n";
            }
            break;
        }
        case 2:
        {
        m1:
            displayFoodMenu();
            
            int food_choice;
            cout << setw(20) << "---: ";
            cin>>food_choice;
            cin.ignore();
            cout << endl;
            
            
            switch(food_choice)
            {
                case 1:
                {
                    cout << setw(18) << " " << "Enter the number of pizza serving(s) to order: ";
                    cin >> quant;
                    
                    if (qPizza-soldPizza>=quant)
                    {
                        soldPizza +=quant;
                        totalPizza += quant*pricePizza;
                        cout << setw(18) << " " << "Message: " << quant << " pizza serving(s) got successfully ordered!\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    else
                    {
                        cout << setw(18) << " " << "Message: Sorry! Only " << qPizza-soldPizza << " pizza serving(s) available.\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << " " << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout << setw(18) << " " << "Enter the number of burgers to order: ";
                    cin >> quant;
                    if (qBurger-soldBurger>=quant)
                    {
                        soldBurger +=quant;
                        totalBurger += quant*priceBurger;
                        cout << setw(18) << " " << "Message: " << quant << " burger(s) got successfully ordered!\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    else
                    {
                        cout << setw(18) << " " << "Message: Sorry! Only " << qBurger-soldBurger << " burger(s) available.\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    break;
                }
                case 3:
                {
                    cout << setw(18) << " " << "Enter the number of noodle serving(s) to order: ";
                    cin >> quant;
                    
                    if (qNoodles-soldNoodles>=quant)
                    {
                        soldNoodles +=quant;
                        totalNoodles += quant*priceNoodles;
                        cout << setw(18) << " " << "Message: " << quant << " noodle serving(s) got successfully ordered!\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    else
                    {
                        cout << setw(18) << " " << "Message: Sorry! Only " << qNoodles-soldNoodles << " noodle servings(s) available.\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    break;
                }
                case 4:
                {
                    cout << setw(18) << " " << "Enter the number of shakes to order: ";
                    cin >> quant;
                    
                    if (qShakes-soldShake>=quant)
                    {
                        soldShake +=quant;
                        totalShake += quant*priceShake;
                        cout << setw(18) << " " << "Message: " << quant << " shake(s) got successfully ordered!\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    else
                    {
                        cout << setw(18) << " " << "Message: Sorry! Only " << qShakes-soldShake << " room(s) are available.\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    break;
                }
                    case 5:
                {
                    cout << setw(18) << " " << "Enter the number of sushi servings to order: ";
                    cin >> quant;
                    
                    if (qSushi-soldSushi>=quant)
                    {
                        soldSushi +=quant;
                        totalSushi += quant*priceSushi;
                        cout << setw(18) << " " << "Message: " << quant << " sushi serving(s) got successfully ordered!\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    else
                    {
                        cout << setw(18) << " " << "Message: Sorry! Only " << qSushi-soldSushi << " sushi serving(s) available.\n\n";
                        cout << setw(18) << " " << "Would you like something else? Press 1 for 'yes' and 2 for 'no'\n";
                    
                        int yes_no;
                        cout << setw(20) << "---: ";
                        cin>> yes_no;
                        cin.ignore();
                        cout << endl;
                        
                        switch(yes_no)
                        {
                            case 1: {
                                goto m1;
                                break;}
                            case 2:{
                                cout << setw(18) << " " << "Thank you for your purchase!\n";
                                break;}
                            default: {
                                cout << setw(18) << " " << "Invalid option. Try again!\n\n";
                                goto m;
                                break;}
                        }
                    }
                    break;
                }
                default:
                {
                    cout << setw(18) << " " << "Invalid option. Try again!";
                    break;
                }
                    
               
                    
            }
            break;
        }
        case 3:{
            cout << setw(20) << " " << "Details of Room Sales and Collection\n";
            cout << setw(15) << " " << "Initial number of rooms: " << qRooms << endl;
            cout << setw(15) << " " << "Number of rooms reserved: " << soldRooms << endl;
            cout << setw(15) << " " << "Remaining number of rooms available: " << qRooms-soldRooms << endl;
            cout << setw(15) << " " << "Total profit from room reservations: $" << totalRooms << endl;
            cout << endl << endl;
            
            cout << setw(20) << " " << "Details of Food Sales and Collection\n";
            cout << setw(15) << " " << "Initial number of pizza: " << qPizza << endl;
            cout << setw(15) << " " << "Number of piza ordered: " << soldPizza << endl;
            cout << setw(15) << " " << "Remaining number of pizza available: " << qPizza-soldPizza << endl;
            cout << setw(15) << " " << "Total profit from pizza sales: $" << totalPizza << endl;
            cout << endl;
            
            cout << setw(15) << " " << "Initial number of burgers: " << qBurger << endl;
            cout << setw(15) << " " << "Number of burgers ordered: " << soldBurger << endl;
            cout << setw(15) << " " << "Remaining number of burgers available: " << qBurger-soldBurger << endl;
            cout << setw(15) << " " << "Total profit from burger sales: $" << totalBurger << endl;
            cout << endl;
            
            cout << setw(15) << " " << "Initial number of noodles: " << qNoodles << endl;
            cout << setw(15) << " " << "Number of noodles ordered: " << soldNoodles << endl;
            cout << setw(15) << " " << "Remaining number of noodles available: " << qNoodles-soldNoodles << endl;
            cout << setw(15) << " " << "Total profit from noodle sales: $" << totalNoodles << endl;
            cout << endl;
            
            cout << setw(15) << " " << "Initial number of shakes: " << qShakes << endl;
            cout << setw(15) << " " << "Number of shakes ordered: " << soldShake << endl;
            cout << setw(15) << " " << "Remaining number of shakes available: " << qShakes-soldShake << endl;
            cout << setw(15) << " " << "Total profit from shake sales: $" << totalShake << endl;
            cout << endl;
            
            cout << setw(15) << " " << "Initial number of sushi: " << qSushi << endl;
            cout << setw(15) << " " << "Number of sushi ordered: " << soldSushi << endl;
            cout << setw(15) << " " << "Remaining number of sushi available: " << qSushi-soldSushi << endl;
            cout << setw(15) << " " << "Total profit from sushi sales: $" << totalSushi << endl;
            cout << endl;
            
            cout << setw(15) << " " << "Total profit from food sales: $" << totalPizza + totalBurger + totalNoodles + totalShake + totalSushi << endl;
            cout << setw(15) << " " << "Total profit: $" << totalRooms + totalPizza + totalBurger + totalNoodles + totalShake + totalSushi  << endl;

            cout << endl;

            
            break;
        }
        case 4:
        {
            cout << endl;
            exit(0);
        }
            
        default:
        {
            cout << setw(15) <<" " << "Invalid option. Please, try again!" << endl;
            break;
        }
    }
    cout << endl;
    goto m;
    
  
    
    
    
    return 0;
}


