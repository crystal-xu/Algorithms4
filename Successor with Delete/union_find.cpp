//
//  union_find.cpp
//  Union Find
//
//  Created by Crystal Xu on 02/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include "union_find.hpp"
#include <vector>

UF::UF( int N )
{
    for( int i = 0; i < N; i++ )
    {
        id.push_back(i);
        sz.push_back(1);
        large.push_back(i);
    }
}

int UF::root( int i )
{
    while( i != id[i] )
        i = id[i];
    return i;
}

void UF::w_union( int p, int q )
{
    int i = root(p);
    int j = root(q);
    if( i == j)
        return;
    int max1 = large[i];
    int max2 = large[j];
    if( sz[i] < sz[j] )
    {
        id[i] = j;
        sz[j] += sz[i];
        if( max1 > max2 )
            large[j] = max1;
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
        if( max2 > max1 )
            large[i] = max2;
    }
}

//returns the largest element in the connected component containing i
int UF::find(int i)
{
    int Root = root(i);
    return large[Root];
}
