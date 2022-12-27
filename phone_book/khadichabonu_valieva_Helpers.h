/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: <Creating Phone Book using the Doubly Linked List>

*/


#ifndef C_PLUS_PLUS_HELPERS_H
#define C_PLUS_PLUS_HELPERS_H

// #include <windows.h>

#include "khadichabonu_valieva_Contact.h"
#include "khadichabonu_valieva_PhoneBook.h"
#include <iomanip>

void addContact(PhoneBook *phoneBook) {
    Contact newContact = Contact();
    Contact *searchContact;
    string value;

    cout << setw(15) << " " << "Enter Primary Number: ";
    getline(cin, value);
    newContact.set_number_primary(value);

    if (phoneBook->find_contact(newContact, &searchContact)) {
        cout << "Phone number already exists. Try again." << endl;
        return;
    }

    cout << setw(15) << " " << "Enter Contact Name (Format: lastname firstname): ";
    getline(cin, value);
    newContact.set_first_name(value);
    newContact.set_last_name(value);
    

    cout << setw(15) << " " << "Enter Secondary Number:";
    getline(cin, value);
    newContact.set_number_secondary(value);

    cout << setw(15) << " " << "Enter Address Line 1: ";
    getline(cin, value);
    newContact.set_address_1(value);

    cout << setw(15) << " " << "Enter Address Line 2: ";
    getline(cin, value);
    newContact.set_address_2(value);

    cout << setw(15) << " " << "Enter City: ";
    getline(cin, value);
    newContact.set_city(value);

    cout << setw(15) << " " << "Enter State: ";
    getline(cin, value);
    newContact.set_state(value);

    cout << setw(15) << " " << "Enter Zip Code: ";
    getline(cin, value);
    newContact.set_zip(value);

    cout << setw(15) << " " << "Enter Relationship: ";
    getline(cin, value);
    newContact.set_relation_type(value);

    if (!phoneBook->insert(newContact)) {
        cout << "Insertion failed. Try again." << endl;
        return;
    }
}

void removeContact(PhoneBook *phoneBook) {
    
    Contact contactToRemove;
    string value;

    cout << setw(15) << " " << "Enter primary phone number: ";
    getline(cin, value);
    contactToRemove.set_number_primary(value);
    
    cout << setw(15) <<" " << "Contact deleted!" << endl;
    
    if (!phoneBook->remove(contactToRemove)) {
        cout << setw(15) <<" " << "Phone nubmer exists. Try again" << endl;
    }
    
}

void editContact(PhoneBook *phoneBook) {
    Contact tempContact, *searchContact;
    string value;
    
    int option;

    cout << setw(15) << " " << "Enter the contact's primary number: ";
    getline(cin, value);

    tempContact.set_number_primary(value);

    do {
        if (!phoneBook->find_contact(tempContact, &searchContact)) {
            cout << setw(15) << " " << "Phone number does not exist. Try again." << endl;
            return;
        }

        cout << setw(15) << " " << "Choose which information to edit:" << endl;
        cout << setw(20) << " " << "1. Edit Name\n";
        cout << setw(20) << " " << "2. Edit Primary Number\n";
        cout << setw(20) << " " << "3. Edit Secondary Number\n";
        cout << setw(20) << " " << "4. Edit Address Line 1\n";
        cout << setw(20) << " " << "5. Edit Address Line 2\n";
        cout << setw(20) << " " << "6. Edit City\n";
        cout << setw(20) << " " << "7. Edit State\n";
        cout << setw(20) << " " << "8. Edit Zip\n";
        cout << setw(20) << " " << "9. Edit Relationship \n";
        cout << setw(19) << " " << "10. Cancel Operation \n";
        
        cout << setw(15) << " " << "--: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << setw(15) << " " << "Old: " << searchContact->get_last_name() << " " << searchContact->get_first_name() << endl;
                cout << setw(15) << " " << "New: ";
                
                cin >> value;
                searchContact->set_last_name(value);
                
                getline(cin, value);
                searchContact->set_first_name(value);
                break;
            case 2:
                cout << setw(15) << " " << "Old: " << searchContact->get_number_primary() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;
                
                searchContact->set_number_primary(value);
                break;
            case 3:
                cout << setw(15) << " " << "Old: " << searchContact->get_number_secondary() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_number_secondary(value);
                break;
            case 4:
                cout << setw(15) << " " << "Old: " << searchContact->get_address_1() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_address_1(value);
                break;
            case 5:
                cout << setw(15) << " " << "Old: " << searchContact->get_address_2() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_address_2(value);
                break;
            case 6:
                cout << setw(15) << " " << "Old: " << searchContact->get_city() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_city(value);
                break;
            case 7:
                cout << setw(15) << " " << "Old: " << searchContact->get_state() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_state(value);
                break;
            case 8:
                cout << setw(15) << " " << "Old: " << searchContact->get_zip() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_zip(value);
                break;
            case 9:
                cout << setw(15) << " " << "Old: " << searchContact->get_relation_type() << endl;
                cout << setw(15) << " " << "New: ";
                cin >> value;

                searchContact->set_relation_type(value);
                break;
            case 10:
                break;
        }
    } while (option < 1 || option > 11);

    cout << setw(15) << " " << "Changes Saved!" << endl;
}


void listContact(PhoneBook *phoneBook) {
    Contact tempContact, *searchContact;
    string value;

    cout << setw(15) << " " << "Enter primary phone number: ";
    getline(cin, value);
    tempContact.set_number_primary(value);

    if (!phoneBook->find_contact(tempContact, &searchContact)) {
        cout << setw(15) << " " << "Phone numbed does not exist. Try again!" << endl;
        return;
    }

    cout << setw(15) << " " << "First name: " << searchContact->get_first_name() << endl;
    cout << setw(15) << " " << "Last name: " << searchContact->get_last_name() << endl;
    cout << setw(15) << " " << "Primary phone number: " << searchContact->get_number_primary() << endl;
    cout << setw(15) << " " << "Secondary phone number: " << searchContact->get_number_secondary() << endl;
    cout << setw(15) << " " << "Address line 1: " << searchContact->get_address_1() << endl;
    cout << setw(15) << " " << "Address line 2: " << searchContact->get_address_2() << endl;
    cout << setw(15) << " " << "City: " << searchContact->get_city() << endl;
    cout << setw(15) << " " << "State: " << searchContact->get_state() << endl;
    cout << setw(15) << " " << "Zip: " << searchContact->get_zip() << endl;
    cout << setw(15) << " " << "Relation type: " << searchContact->get_relation_type() << endl;
}

#endif
