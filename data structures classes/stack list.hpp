//
//  stack list.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef stack_list_hpp
#define stack_list_hpp

#include <iostream>
using std::cout;
using std::endl;

struct stackNode {
    int data;
    stackNode *next;
};

class stackList {
private:
    stackNode *head, *tail;
public:
    stackList() {
        head = NULL;
        tail = NULL;
    }
    void push(int value) {
        stackNode *temp = new stackNode;
        temp->data = value;
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else {
            temp->next = tail;
            tail = temp;
        }
    }
    int pop() {
        stackNode *last = new stackNode;
        last = tail;
        tail = tail->next;
        int res = last->data;
        delete last;
        return res;
    }
    int showLast() {
        return tail->data;
    }
    void display() {
        stackNode *temp = new stackNode;
        temp = tail;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif /* stack_list_hpp */
