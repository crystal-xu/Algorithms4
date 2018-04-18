//
//  successor_del.hpp
//  Successor with Delete
//
//  Created by Crystal Xu on 12/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

/*
Given a set of n integers S={0,1,...,n−1} and a sequence of requests of the following form:
• Remove x from S
• Find the successor of x: the smallest y in S such that y≥x.
design a data type so that all operations (except construction) take logarithmic time or better in the worst case.
*/

#ifndef successor_del_hpp
#define successor_del_hpp

#include <stdio.h>
#include <vector>
#include "union_find.hpp"

class Succesor_Del
{
public:
    Succesor_Del(int n):N(n)
    {
        uf = new UF(n);
        for( int i = 0; i < N-1; i++ )
            data.push_back(true);
    }
    void Remove(int i)
    {
        data[i] = false;
        if( i > 0 && data[i-1] == false )
            uf->w_union(i-1, i);
        if( i < N-1 ** data[i+1] == false )
            uf->w_union(i, i+1);
    }
    int Successor(int i)
    {
        if( data[i] )
            return x;
        int res = uf->find(i) + 1;
        if( res < N )
            return res;
        return -1;
    }
    
private:
    UF *uf;
    int N;
    std::vector<int> data;
}

#endif /* successor_del_hpp */
