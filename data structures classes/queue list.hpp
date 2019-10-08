//
//  queve list.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef queue_list_hpp
#define queue_list_hpp

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

struct queueNode {
    int data;
    queueNode *next;
};

class queueList {
private:
    queueNode *head, *tail;
    int length;
public:
    queueList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    void display() {
        if (head == NULL && tail == NULL)
            return;
        queueNode *curr = new queueNode;
        curr = tail;
        while (curr->next != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << curr->data;
        cout << endl;
    }
    void insert(int value) {
        queueNode *temp = new queueNode;
        temp->data = value;
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        } else {
            temp->next = tail;
            tail = temp;
        }
        length++;
    }
    int deleteFirst() {
        queueNode *curr = new queueNode;
        queueNode *first = new queueNode;
        curr = tail;
        while (curr->next != head) {
            curr = curr->next;
        }
        first = curr->next;
        curr->next = NULL;
        int res = first->data;
        delete first;
        return res;
    }
    int getFirst() {
        return head->data;
    }
    int getLast() {
        return tail->data;
    }
    void clear() {
        queueNode *curr = new queueNode;
        curr = tail;
        while (curr->next != NULL) {
            queueNode *prev = curr;
            delete prev;
            curr = curr->next;
            tail = curr;
        }
        tail = NULL;
        head = NULL;
    }
};

class queueArr {
private:
    vector<int> arr;
public:
    void insert(int value) {
        arr.push_back(value);
    }
    int deleteFirst() {
        int res = arr[0];
        arr.erase(arr.begin());
        return res;
    }
    int getFirst() {
        return arr[0];
    }
    int getLast() {
        return arr[arr.size() - 1];
    }
    void clear() {
        arr.clear();
    }
    void display() {
        for (auto i = arr.end() - 1; i + 1 != arr.begin(); i--)
            cout << *i << " ";
        cout << endl;
    }
};

#endif /* queve_list_hpp */
