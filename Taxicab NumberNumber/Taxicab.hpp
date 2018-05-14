//
//  Taxicab.hpp
//  Taxicab Numbers
//
//  Created by Crystal Xu on 08/05/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef Taxicab_hpp
#define Taxicab_hpp

#include <stdio.h>

class Taxicab
{
public:
    Taxicab(int _i, int _j):i(_i), j(_j), sum(_i*_i*_i+_j*_j*_j) {}
    ~Taxicab() {}

    int i;
    int j;
    long sum;
    
};

class myComparator
{
public:
    bool operator() (const Taxicab &lhs, const Taxicab &rhs)
    {
        return ( lhs.sum > rhs.sum || (lhs.sum == rhs.sum && lhs.i > rhs.i) );
    }
};

#endif /* Taxicab_hpp */
