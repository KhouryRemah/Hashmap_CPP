#include <iostream>
#include "HashMap.h"
//#include "RTNode.h"

//#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

void testHashMap1() {
    HashMap<int, int> map;
    map.print();
    map.insert(1, 1);
    map.print();
    map.insert(2, 1);
    map.print();
    map.insert(3, 1);
    map.print();
    map.insert(4, 1);
    map.print();
    map.insert(5, 1);
    map.print();
    map.insert(6, 1);
    map.print();
    map.insert(7, 1);
    map.print();
    map.insert(8, 1);
    map.print();
    map.insert(9, 1);
    map.print();
    map.insert(10, 1);
    map.print();
    map.insert(11, 1);
    map.print();
    map.insert(12, 1);
    map.print();
    map.insert(13, 1);
    map.print();
    map.insert(14, 1);
    map.print();
    map.insert(15, 1);
    map.print();

    map.insert(16, 1);
    map.print();
    map.remove(16);
    map.print();
    map.remove(15);
    map.print();
    map.remove(14);
    map.print();
    map.remove(13);
    map.print();
    map.remove(12);
    map.print();
    map.remove(11);
    map.print();
    map.remove(10);
    map.print();
    map.remove(9);
    map.print();
    map.remove(8);
    map.print();
    map.remove(7);
    map.print();
    map.remove(6);
    map.print();
    map.remove(5);
    map.print();
    map.remove(4);
    map.print();
    map.remove(3);
    map.print();
    map.remove(2);
    map.print();
    map.remove(1);
    map.print();
    std::cout << "---------------" << std::endl;

    map.insert(1, 4);
    assert(map.exist(1));
    assert(!map.exist(2));
    map.insert(1, 2);
    map.print();
    map.remove(2);
    assert(map.get(1) == 4);

}

void     testHashMap2() {
    HashMap<int, int> map;
    map.print();
    map.insert(1, 1);
    map.print();
    map.insert(4, 1);
    map.print();
    map.insert(7, 1);
    map.print();
    map.insert(10, 1);
    map.print();

}


int main(int argc, const char** argv) {
    testHashMap1();
    testHashMap2();
    return 0;
}

