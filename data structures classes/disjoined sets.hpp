//
//  disjoined sets.hpp
//  data structures classes
//
//  Created by Андрей Журавлев on 03/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef disjoined_sets_hpp
#define disjoined_sets_hpp

#include <vector>

class _core_part {
protected:
    std::vector<int> sets;
public:
    _core_part(size_t size) {
        sets.resize(size);
    }
    ~_core_part() {
        sets.clear();
    }
    virtual void create(int x) = 0;
    virtual void make_union(int dest, int src) = 0;
    virtual int find(int x) = 0;
};

class ds_arrays : public _core_part {
public:
    ds_arrays(size_t size) : _core_part(size) {}
    void create(int x) override {
        sets[x] = x;
    }
    void make_union(int dest, int src) override {
        for (int i = 0; i < sets.size(); i++)
        if (sets[i] == sets[src])
            sets[i] = sets[dest];
    }
    int find(int x) override {
        return sets[x];
    }
};

class ds_trees : public ds_arrays {
public:
    ds_trees(size_t size) : ds_arrays(size) {}
    ~ds_trees() {
        sets.clear();
    }
    
    void make_union(int dest, int src) override {
        dest = find(dest);
        src = find(src);
        if (dest == src)
            return;
        else
            sets[src] = dest;
    }
    
    int find(int x) override {
//        return x == sets[x] ? x : find(sets[x]);
        while (sets[x] != x)
            x = sets[x];
        return x;
    }
};


class ds_trees_r : public ds_trees {
protected:
    std::vector<int> rank;
public:
    ds_trees_r(size_t size) : ds_trees(size) {
        rank.resize(size);
    }
    ~ds_trees_r() {
        rank.clear();
    }
    
    void create(int x) override {
        sets[x] = x;
        rank[x] = 0;
    }
    
    void make_union(int dest, int src) override {
        dest = find(dest);
        src = find(src);
        if (dest == src)
            return;
        else if (rank[dest] < rank[src])
            sets[dest] = src;
        else if (rank[src] < rank[dest])
            sets[src] = dest;
        else {
            sets[src] = dest;
            rank[dest]++;
        }
    }
};

class ds_trees_rc: public ds_trees_r {
public:
    ds_trees_rc(size_t size) : ds_trees_r(size) {};
    int find(int x) override {
        int y = x;
        while (sets[x] != x)
            x = sets[x];
        while (sets[y] != y) {
            int temp = y;
            y = sets[y];
            sets[temp] = x;
        }
        return x;
    }
};

clock_t ds_arr_test(int size);
clock_t ds_tree_test(int size);
clock_t ds_tree_r_test(int size);
clock_t ds_tree_rc_test(int size);

template <class T>
clock_t test_size(T *arr, size_t size);
template <class T>
std::vector<clock_t> test_class(T *arr);
void test_all();
void fill_op_queue(std::vector<char> &queue, size_t size);
template<typename T>
void printArr(std::vector<T> arr);



//Алгоритм Kruskal
/*
    есть множество из простых элементов {1...n}
    и есть подмножества из нескольких элементов
    структура предназначена для работы с такими подмножествами
 create(elem) O(1)
 join(elemX, elemY) - объединяет множества из двух меток в одну множества   O(n)
 search(elem) - находит метку множества, к которому принадлежит elem O(1)
 
 
 var2:
 i-ый элемент массива будет корнем элемента i множества (меткой будет сам корень)
 
 create(x)  O(1)
 join(x, y) O(1), если объединяются корни. O(n) в худшем случае (линия) когда объединение в самый нижний элемент
 find(x)    O(n)
 
 
 Эвристика рангов:
 join(x, y) O(log(n))
 find(x)    O(log(n))
 также будет еще массив с высотами деревьев
 
 Эвриситка сжатия ???
 
 
 делать вариант с массивами dumb
        вариант с деревом
        дерево + ранги
        дерево + ранги + pair compression
 
 тесты на массивах размерами {10, 50, 100, 500, 1000, 5000, 10000}
 n операций create()
 n - 1 операций join()
 n - 1 операций find()
 */


#endif /* disjoined_sets_hpp */
