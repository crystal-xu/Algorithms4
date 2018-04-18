//
//  main.cpp
//  Union Find
//
//  Created by Crystal Xu on 02/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

/*
Add a method 𝚏𝚒𝚗𝚍() to the union-find data type so that 𝚏𝚒𝚗𝚍(𝚒) returns the largest 
element in the connected component containing i. The operations, 𝚞𝚗𝚒𝚘𝚗(), 𝚌𝚘𝚗𝚗𝚎𝚌𝚝𝚎𝚍(),
and 𝚏𝚒𝚗𝚍() should all take logarithmic time or better.
For example, if one of the connected components is {1,2,6,9}, then the 𝚏𝚒𝚗𝚍() method
should return 9 for each of the four elements in the connected components.
*/

#include <iostream>
#include "union_find.hpp"

int main(int argc, const char * argv[]) {
    UF *uf = new UF(10);
    uf->w_union(0, 1);
    uf->w_union(2, 1);
    uf->w_union(3, 1);
    uf->w_union(4, 5);
    int max1 = uf->find(1);
    int max2 = uf->find(5);
    std::cout << max1 << " " << max2 << std::endl;
    return 0;
}
