/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: <Creating Phone Book using the Doubly Linked List>

*/


#include "khadichabonu_valieva_Contact.h"

class Node {
public:
    Contact data;
    Node *next;
    Node *prev;

    Node() {
        data = Contact();
        next = nullptr;
        prev = nullptr;
    }
};
