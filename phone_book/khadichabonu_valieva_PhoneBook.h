/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: <Creating Phone Book using the Doubly Linked List>

*/


#ifndef PhoneBook_h
#define PhoneBook_h

#include <iostream>
#include <string>
#include <vector>

#include "khadichabonu_valieva_Node.h"
#include "khadichabonu_valieva_Contact.h"


using std::string;
using namespace std;


class PhoneBook {
private:
    Node *head;
    Node *tail;

    int size;

public:
    PhoneBook() {
        this->head = this->tail = nullptr;
        this->size = 0;
    }

    ~PhoneBook() {
        clear_list();
    }

    bool insert(Contact &item) {
        if (this->head == nullptr) {
            Node *temp = new Node();
            temp->data = item;

            this->head = temp;
            this->tail = temp;
            this->size++;

            return true;
        } else {
            Node *temp = head;

            while (temp != nullptr && item > temp->data)
                temp = temp->next;

            if (temp != nullptr && item == temp->data) {
                return false;
            } else if (temp == this->head) {
                Node *new_node = new Node();
                new_node->data = item;
                new_node->prev = nullptr;
                new_node->next = this->head;

                this->head->prev = new_node;
                this->head = new_node;

                this->size++;
                return true;
            } else if (temp == nullptr) {
                Node *new_node = new Node;
                new_node->data = item;
                new_node->prev = this->tail;

                this->tail->next = new_node;
                this->tail = new_node;

                this->size++;
                return true;
            } else {
                Node *new_node = new Node();
                new_node->data = item;

                Node *pre = temp->prev;

                pre->next = new_node;
                new_node->next = temp;
                temp->prev = new_node;
                new_node->prev = pre;

                this->size++;
                return true;
            }
        }
    }

    bool remove(Contact &item) {
    
    
        if (this->head == nullptr)
            return false;
        else {
            Node *temp = this->head;

            while (temp != nullptr && item != temp->data)
                temp = temp->next;
            
            if (temp != nullptr && item == temp->data)
            {
                if (temp == this->head) {
                    this->head = this->head->next;
                    delete temp;

                    this->head->prev = nullptr;

                    this->size--;
                    return true;
                }
                else if (temp == this->tail) {
                    this->tail = this->tail->prev;
                    delete temp;

                    
                    this->tail->next = nullptr;

                    this->size--;
                    return true;
                }
                else {
                    Node *previous = temp->prev;
                    Node *next = temp->next;

                    delete temp;

                    previous->next = next;
                    next->prev = previous;

                    this->size--;
                    return true;
                }
            }
        }
        
        
        return false;
    }
        

    bool find_contact(Contact &item, Contact **search_ret) {
        
        Node *temp = this->head;
         
         while (temp != nullptr && temp->data != item) {
             temp = temp->next;
         }

         if (temp == nullptr) return false;

         *search_ret = &temp->data;
         return true;
         
    }

    void output_list() {
        Node *temp = this->head;

        cout << setw(15) << " " << "All contacts (" << this->size << "):" << endl;
        cout << setw(15) << " " << "---------------------------------" << endl;
        while (temp != nullptr) {
            cout << setw(15) << " " << "First name: " << temp->data.get_first_name() << endl;
            cout << setw(15) << " " << "Last name: " << temp->data.get_last_name() << endl;
            cout << setw(15) << " " << "Primary phone number: " << temp->data.get_number_primary() << endl;
            cout << setw(15) << " " << "Secondary phone number: " << temp->data.get_number_secondary() << endl;
            cout << setw(15) << " " << "Address line 1: " << temp->data.get_address_1() << endl;
            cout << setw(15) << " " << "Address line 2: " << temp->data.get_address_2() << endl;
            cout << setw(15) << " " << "City: " << temp->data.get_city() << endl;
            cout << setw(15) << " " << "State: " << temp->data.get_state() << endl;
            cout << setw(15) << " " << "Zip: " << temp->data.get_zip() << endl;
            cout << setw(15) << " " << "Relation type: " << temp->data.get_relation_type() << endl;
            cout << setw(15) << " " << "---------------------------------" << endl;

            temp = temp->next;
        }
        cout << endl;
    }


    void clear_list() {
        Node *temp;

        while (this->head != nullptr) {
            temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->tail=nullptr;
        this->size = 0;
        cout << setw(15) << " " << "PhoneBook is cleared!" << endl << endl << endl;
    };
    
      
    
};

#endif

