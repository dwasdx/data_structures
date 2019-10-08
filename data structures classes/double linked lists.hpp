//
//  double linked lists.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef double_linked_lists_hpp
#define double_linked_lists_hpp

#include <iostream>
using std::cout;
using std::endl;

struct doubleNode {
    int data;
    doubleNode *next;
    doubleNode *prev;
};

class doubleList {
private:
    doubleNode *head, *tail;
    int length;
public:
    doubleList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    void createNode(int value) {
        doubleNode *temp = new doubleNode;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        length++;
    }
    void display() {
        doubleNode *temp=new doubleNode;
        temp=head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertBegin(int value) {
        doubleNode *temp = new doubleNode;
        temp->data = value;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        length++;
    }
    void insertEnd(int value) {
        createNode(value);
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
        head->prev = NULL;
        delete temp;
        length--;
    }
    void deleteEnd() {
        doubleNode* temp = new doubleNode;
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
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
#endif /* double_linked_lists_hpp */
