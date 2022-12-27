/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: <Creating Phone Book using the Doubly Linked List>

*/


#ifndef Contact_h
#define Contact_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact {
private:
    string first_name;
    string last_name;
    string number_primary;
    string number_secondary;
    string address_1;
    string address_2;
    string city;
    string state;
    string zip;
    string relation_type;

public:
    Contact() {}

    // --- setter and getter for first_name ---
    void set_first_name(string value) {
        this->first_name = value;
    }

    string get_first_name() {
        return this->first_name;
    }

    // --- setter and getter for last_name ---
    void set_last_name(string value) {
        this->last_name = value;
    }

    string get_last_name() {
        return this->last_name;
    }

    // --- setter and getter for number_primary ---
    void set_number_primary(string value) {
        this->number_primary = value;
    }

    string get_number_primary() {
        return this->number_primary;
    }

    // --- setter and getter for number_secondary ---
    void set_number_secondary(string value) {
        this->number_secondary = value;
    }

    string get_number_secondary() {
        return this->number_secondary;
    }

    // --- setter and getter for address_1 ---
    void set_address_1(string value) {
        this->address_1 = value;
    }

    string get_address_1() {
        return this->address_1;
    }

    // --- setter and getter for address_2 ---
    void set_address_2(string value) {
        this->address_2 = value;
    }

    string get_address_2() {
        return this->address_2;
    }

    // --- setter and getter for city ---
    void set_city(string value) {
        this->city = value;
    }

    string get_city() {
        return this->city;
    }

    // --- setter and getter for state ---
    void set_state(string value) {
        this->state = value;
    }

    string get_state() {
        return this->state;
    }

    // --- setter and getter for zip ---
    void set_zip(string value) {
        this->zip = value;
    }

    string get_zip() {
        return this->zip;
    }

    // --- setter and getter for relation_type ---
    void set_relation_type(string value) {
        this->relation_type = value;
    }

    string get_relation_type() {
        return this->relation_type;
    }

    // --- operator overloading for == ---
    bool operator==(const Contact &right_side) const {
        return this->number_primary.compare(right_side.number_primary) == 0;
    }

    // --- operator overloading for != ---
    bool operator!=(const Contact &right_side) const {
        return !(*this == right_side);
    }

    // --- operator overloading for < ---
    bool operator<(const Contact &right_side) const {
        if (this->last_name.compare(right_side.last_name) == 0) {
            return this->first_name.compare(right_side.first_name) == -1;
        }

        return this->last_name.compare(right_side.last_name) == -1;
    }

    // --- operator overloading for > ---
    bool operator>(const Contact &right_side) const {
        return !(*this < right_side);
    }
};

#endif
