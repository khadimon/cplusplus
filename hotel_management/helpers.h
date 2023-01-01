//
//  helpers.h
//  hotel_management#
//
//  Created by Khadichabonu Valieva on 28/12/22.
//

#ifndef helpers_h
#define helpers_h

#include <iomanip>

using namespace std;


void displayMainMenu()
    {
    cout << "\n   Enter a number to select the command you want to run:\n";
    cout << setw(15) << " " << "1. Room Reservation\n";
    cout << setw(15) << " " << "2. Food Order\n";
    cout << setw(15) << " " << "3. Sales and Collection\n";
    cout << setw(15) << " " << "4. Exit\n";
    }

void displayFoodMenu()
    {
        cout << setw(15) << " " << "Choose from the food options:\n";
        cout << setw(18) << " " << "1. Pizza\n";
        cout << setw(18) << " " << "2. Burger\n";
        cout << setw(18) << " " << "3. Noodles\n";
        cout << setw(18) << " " << "4. Shakes\n";
        cout << setw(18) << " " << "5. Sushi-rolls\n";
    }

#endif /* helpers_h */
