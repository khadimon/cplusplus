/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: < The runtime analysis of Linked List vs Trie data structure >

*/

#ifndef LinkedList_h
#define LinkedList_h

using namespace std;

class Node {
public:
    string value;
    Node *next;

    Node(string value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(string word) {
        if (head == nullptr) {
            head = new Node(word);
            tail = head;
            return;
        }

        Node *new_node = new Node(word);
        tail->next = new_node;
        tail = tail->next;
//        Node *temp = head;
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//
//        temp->next = new_node;
    }

    bool search(string word) {
        if (head == nullptr) return false;

        Node *temp = head;
        while (temp != nullptr) {
            if (temp->value == word) return true;
            temp = temp->next;
        }

        return false;
    }
};



#endif /* LinkedList_h */
