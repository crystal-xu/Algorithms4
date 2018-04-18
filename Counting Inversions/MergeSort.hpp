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
    
    int sort( std::vector<int> &a )
    {
        std::vector<int> aux((int)a.size() - 1, 0);
        int res = sort(a, aux, 0, (int)a.size() - 1);
        return res;
    }
    
    void sort_with_smaller( std::vector<int> &a );
    
private:
    int merge(std::vector<int> &a, std::vector<int> &aux, int lo, int mid, int hi);
    int sort( std::vector<int> &a, std::vector<int> &aux, int lo, int hi );
};
#endif /* MergeSort_hpp */
