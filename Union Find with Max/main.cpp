//
//  main.cpp
//  Union Find
//
//  Created by Crystal Xu on 02/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

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
