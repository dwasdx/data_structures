//
//  disjoined sets.cpp
//  data structures classes
//
//  Created by Андрей Журавлев on 05/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "disjoined sets.hpp"
#include <ctime>
#include <iostream>
#include <random>



clock_t ds_tree_r_test(int size) {
    clock_t total_time = 0;
    for (int n = 0; n < 50; n++) {
        clock_t time_begin = clock();
        ds_trees_r *arr = new ds_trees_r(size);
        for (int i = 0; i < size; i++)
            arr->create(i);
//        int find_op_q = (size - 1) * (size - 1);
        int find_op_q = (size - 1);
        int union_op_q = size - 1;
        while(find_op_q || union_op_q) {
            if (union_op_q) {
                arr->make_union(rand() % size, rand() % size);
                union_op_q--;
            }
            if (find_op_q) {
                arr->find(rand() % size);
                find_op_q--;
            }
        }
        total_time += clock() - time_begin;
        delete arr;
    }
    return total_time / 50;
}

clock_t ds_tree_rc_test(int size) {
    clock_t total_time = 0;
    for (int n = 0; n < 50; n++) {
        clock_t time_begin = clock();
        ds_trees_rc *arr = new ds_trees_rc(size);
        for (int i = 0; i < size; i++)
            arr->create(i);
//        int find_op_q = (size - 1) * (size - 1);
        int find_op_q = (size - 1);

        int union_op_q = size - 1;
        while(find_op_q || union_op_q) {
            if (union_op_q) {
                arr->make_union(rand() % size, rand() % size);
                union_op_q--;
            }
            if (find_op_q) {
                arr->find(rand() % size);
                find_op_q--;
            }
            
        }
        total_time += clock() - time_begin;
        delete arr;
    }
    return total_time / 50;
}

#define QUOTE(name) #name
#define STRING_WRAP(macro) QUOTE(macro)

std::vector<size_t> sizes = {10, 50, 100, 500, 1000, 5000, 10000};

template <class T>
clock_t test_size(T *arr, size_t size) {
//    arr = new T(size);
    std::vector<char> queue;
    clock_t total_time = 0;
    for (int n = 0; n < 50; n++) {
        fill_op_queue(queue, size);
        clock_t begin = clock();
        for (int i = 0; i < size; i++)
            arr->create(i);
        for (int i = 0; i < queue.size(); i++)
            if (queue[i] == 'F')
                arr->find(rand() % size);
            else
                arr->make_union(rand() % size, rand() % size);
        total_time += clock() - begin;
    }
    
    return total_time / 50;
}

template <class T>
std::vector<clock_t> test_class(T *arr) {
    std::vector<clock_t> timings;
    for (auto size = sizes.begin(); size != sizes.end(); size++) {
        arr = new T(*size);
//        std::cout << "size " << *size << std::endl;
        clock_t time = test_size(arr, *size);
        timings.push_back(time);
    }
    return timings;
}

void test_all() {
    std::vector<clock_t> timings;
    ds_arrays *arr;
    timings = test_class(arr);
    for (int i = 0; i < timings.size(); i++) {
        std::cout << "arrays size " << sizes[i] << " for " << timings[i] << std::endl;
    }
    ds_trees *tree;
    timings = test_class(tree);
    for (int i = 0; i < timings.size(); i++) {
        std::cout << "trees size " << sizes[i] << " for " << timings[i] << std::endl;
    }
    ds_trees_r *tree_r;
    timings = test_class(tree_r);
    for (int i = 0; i < timings.size(); i++) {
        std::cout << "trees with rank size " << sizes[i] << " for " << timings[i] << std::endl;
    }
    ds_trees_rc *tree_rc;
    timings = test_class(tree_rc);
    for (int i = 0; i < timings.size(); i++) {
        std::cout << "trees with rank and compr size " << sizes[i] << " for " << timings[i] << std::endl;
    }
}

void fill_op_queue(std::vector<char> &queue, size_t size) {
    queue.clear();
    size_t find_op_q = size - 1, union_op_q = size - 1;
    while (find_op_q || union_op_q)
        if (rand() % 2 == 0 && find_op_q){
            queue.push_back('F');
            find_op_q--;
        } else if (union_op_q) {
            queue.push_back('U');
            union_op_q--;
        }
}

template<typename T>
void printArr(std::vector<T> arr) {
    for (auto i = arr.begin(); i != arr.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
}
