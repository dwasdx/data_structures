//
//  stack array.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef stack_array_hpp
#define stack_array_hpp

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class stackArr {
private:
    vector<int> arr;
public:
    void push(int value) {
        arr.push_back(value);
    }
    int pop() {
        int last = arr[arr.size() - 1];
        arr.pop_back();
        return last;
    }
    int showLast() {
        return arr[arr.size() - 1];
    }
    void display() {
        for (auto i = arr.end() - 1; i + 1 != arr.begin(); i--)
            cout << *i << " ";
        cout << endl;
    }
};

#endif /* stack_array_hpp */
