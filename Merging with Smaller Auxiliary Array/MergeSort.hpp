//
//  MergeSort.hpp
//  Merge Sort
//
//  Created by Crystal Xu on 03/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <vector>

class Merge
{
public:
    Merge() {}
    ~Merge() {}
    
    void sort( std::vector<int> &a )
    {
        std::vector<int> aux((int)a.size() - 1, 0);
        sort(a, aux, 0, (int)a.size() - 1);
    }
    
    void sort_with_smaller( std::vector<int> &a );
    
private:
    void merge(std::vector<int> &a, std::vector<int> &aux, int lo, int mid, int hi);
    void sort( std::vector<int> &a, std::vector<int> &aux, int lo, int hi );
};
#endif /* MergeSort_hpp */
