//
//  main.cpp
//  Merge With Small
//
//  Created by Crystal Xu on 16/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>
#include "MergeSort.hpp"
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> a{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    Merge *merge = new Merge();
    merge->sort_with_smaller(a);
    for( auto &elem:a )
        std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}
