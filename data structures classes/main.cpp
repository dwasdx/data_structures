//
//  main.cpp
//  data structures classes
//
//  Created by Андрей Журавлев on 01/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "singly linked lists.hpp"
#include "double linked lists.hpp"
#include "circle linked lists.hpp"
#include "stack list.hpp"
#include "stack array.hpp"
#include "queue list.hpp"
#include "disjoined sets.hpp"


int main(int argc, const char * argv[]) {
    srand(time(NULL));
    cout << "Default tests" << endl;
    test_all();
}
