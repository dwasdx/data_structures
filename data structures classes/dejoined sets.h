//
//  dejoined sets.h
//  data structures classes
//
//  Created by Андрей Журавлев on 02/10/2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

//разделенные множества
#ifndef dejoined_sets_h
#define dejoined_sets_h
#include <vector>

class dsArrays {
private:
    std::vector<int> arr;
    
};


#endif /* dejoined_sets_h */

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