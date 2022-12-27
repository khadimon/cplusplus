/*

Name: <Khadichabonu Valieva>

NetID: <w10118633)

Program Description: <Creating Phone Book using the Doubly Linked List>

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "khadichabonu_valieva_PhoneBook.h"
#include "khadichabonu_valieva_Helpers.h"
#include "khadichabonu_valieva_Contact.h"


void load_book(PhoneBook* b);

using namespace std;

int main()
{
    PhoneBook phoneBook;
    load_book(&phoneBook);
    
    
    int option;
    
    // 30 + 9 + 30
    cout << "---------------------------------------------------------------------" << endl;
    cout << setw(39) <<"MAIN MENU" << endl;
    cout << "---------------------------------------------------------------------" << endl << endl;
    

 
    do {
        cout << "Enter a number to select the command you want to run:\n";
        cout << setw(15) << " " << "1. Add New Contact\n";
        cout << setw(15) << " " << "2. Edit Contact\n";
        cout << setw(15) << " " << "3. Remove Contact\n";
        cout << setw(15) << " " << "4. List Contact\n";
        cout << setw(15) << " " << "5. List All Contacts\n";
        cout << setw(15) << " " << "6. Exit Program \n\n";
        
        cout << "---: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                addContact(&phoneBook);
                cout << "\n";
                break;
            }
            case 2: {
                editContact(&phoneBook);
                cout << "\n";
                break;
            }
            case 3: {
                removeContact(&phoneBook);
                cout << "\n";
                break;
            }
            case 4: {
                listContact(&phoneBook);
                cout << "\n";
                break;
            }
            case 5: {
                phoneBook.output_list();
                cout << "\n";
                break;
            }
            case 6: {
                break;
            }
            default: {
                cout << setw(15) <<" " << "Invalid option. Please, try again!" << endl;
                system("pause");
                break;
            }
        }
                
        cout << endl;
        } while (option != 6);
    
  
    }

void load_book(PhoneBook* b)
{
    ifstream file;
    file.open("/Users/khadichabonuvalieva/Downloads/PhoneBook.csv");

    string line;

    //"Eat" the header row, as that will not
    //be stored in our linked list.
    getline(file, line);

    //Strip and store each phone book entry into
    //a Contact object, and then add it to our Linked List.
    while (getline(file, line))
    {
        Contact c;

        string last_name, first_name, item;
        size_t index_comma;

        //Last Name
        index_comma = line.find(';');
        last_name = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);
        c.set_last_name(last_name);

        //First Name
        index_comma = line.find(';');
        first_name = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_first_name(first_name);

        //Phone Number Primary
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_number_primary(item);

        //Phone Number Secondary
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_number_secondary(item);

        //Address 1
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_address_1(item);

        //Address 2
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_address_2(item);

        //Set City
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_city(item);

        //Set State
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_state(item);

        //Set Zip
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_zip(item);

        //Set Relation
        index_comma = line.find(';');
        item = line.substr(0, index_comma);
        line.erase(0, index_comma + 1);

        c.set_relation_type(item);

        b->insert(c);
    }

    file.close();
}

