//
//  singly linked lists.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef singly_linked_lists_hpp
#define singly_linked_lists_hpp

#include <iostream>
using std::cout;
using std::endl;

struct Node {
    int data;
    Node* next;
};

class singlyList {
private:
    Node *head, *tail;
    int length;
public:
    singlyList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    void createNode(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        } else {
            tail->next = temp;
            tail = temp;
        }
        length++;
    }
    void display() {
        Node *temp = new Node;
        temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertBegin(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
        length++;
    }
    void insertEnd(int value) {
        createNode(value);
    }
    void insertParticular(int value, int pos) {
        pos++;
        Node* prev = new Node;
        Node* curr = new Node;
        Node* temp = new Node;
        curr = head;
        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        temp->data = value;
        prev->next = temp;
        temp->next = curr;
        length++;
    }
    void deleteBegin() {
        Node* temp = new Node;
        temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    void deleteEnd() {
        Node* curr = new Node;
        Node* prev = new Node;
        curr = head;
        while (curr != tail) {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = NULL;
        delete curr;
        length--;
    }
    void deletePartcular(int pos) {
        if (pos == 1) {
            deleteBegin();
            return;
        }
        pos++;
        Node *prev = new Node;
        Node *curr = new Node;
        curr = head;
        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        length--;
    }
    int indexOf(int value) {
        Node *curr = new Node;
        curr = head;
        int i = 0;
        while (curr->data != value) {
            if (curr->next == NULL)
                return -1;
            curr = curr->next;
            i++;
        }
        return i;
    }
    int size() {
        return length;
    }
};

#endif /* singly_linked_lists_hpp */
