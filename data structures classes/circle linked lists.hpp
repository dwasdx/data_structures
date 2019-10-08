//
//  circle linked lists.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef circle_linked_lists_hpp
#define circle_linked_lists_hpp

#include <iostream>
using std::cout;
using std::endl;

class singlyCircleList {
private:
    Node *head, *tail;
    int length;
public:
    singlyCircleList() {
        head = NULL;
        tail = NULL;
        length = 0;
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
        tail->next = head;
        length++;
    }
    void insertEnd(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            tail->next = head;
            temp = NULL;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        length++;
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
        tail->next = head;
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
        prev->next = head;
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
            if (i > length)
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

class doubleCircleList {
private:
    doubleNode *head, *tail;
    int length;
public:
    doubleCircleList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    void display() {
        doubleNode *temp=new doubleNode;
        temp=head;
        while(temp!=tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << endl;
    }
    void insertBegin(int value) {
        doubleNode *temp = new doubleNode;
        temp->data = value;
        temp->next = head;
        temp->prev = tail;
        head = temp;
        length++;
    }
    void insertEnd(int value) {
        doubleNode *temp = new doubleNode;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            head->next = tail;
            head->prev = tail;
            tail->next = head;
            tail->prev = head;
            temp = NULL;
        }
        else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            tail->next = head;
            head->prev = tail;
        }
        length++;
    }
    void insertParticular(int value, int pos) {
        pos++;
        doubleNode* prev = new doubleNode;
        doubleNode* curr = new doubleNode;
        doubleNode* temp = new doubleNode;
        if (pos < length / 2) {
            curr = head;
            for (int i = 1; i < pos; i++) {
                prev = curr;
                curr = curr->next;
            }
            temp->data = value;
            prev->next = temp;
            temp->next = curr;
            temp->prev = prev;
            curr->prev = temp;
        } else {
            curr = tail;
            for (int i = length; i > pos; i--) {
                prev = curr;
                curr = curr->prev;
            }
            temp->data = value;
            prev->prev = temp;
            temp->next = curr;
            temp->prev = curr;
            curr->next = temp;
        }
        length++;
    }
    void deleteBegin() {
        doubleNode* temp = new doubleNode;
        temp = head;
        head = head->next;
        head->prev = tail;
        delete temp;
        length--;
    }
    void deleteEnd() {
        doubleNode* temp = new doubleNode;
        temp = tail;
        tail = tail->prev;
        tail->next = head;
        delete temp;
        length--;
    }
    void deleteParticular(int pos) {
        if (pos == 1) {
            deleteBegin();
            return;
        }
        pos++;
        doubleNode *prev = new doubleNode;
        doubleNode *curr = new doubleNode;
//        doubleNode *temp = new doubleNode;
        if (pos < length / 2) {
            curr = head;
            for (int i = 1; i < pos; i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            curr->next->prev = prev;
            delete curr;
        } else {
            curr = tail;
            for (int i = length; i > pos; i--) {
                prev = curr;
                curr = curr->prev;
            }
            prev->prev = curr->prev;
            curr->prev->next = prev;
            delete curr;
        }
        length--;
    }
    int size() {
        return length;
    }
};

#endif /* circle_linked_lists_hpp */
