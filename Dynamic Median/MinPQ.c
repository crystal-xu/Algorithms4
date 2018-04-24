//
//  MinPQ.cpp
//  Dynamic Median
//
//  Created by Crystal Xu on 23/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include "MinPQ.hpp"
#include <vector>

void MinPQ::insert( int x )
{
    pq[++N] = x;
    swim(N);
}

int MinPQ::delMin()
{
    int min = pq[1];
    std::swap(pq[1], pq[N--]);
    sink(1);
    pq[N+1] = 0;
    return min;
}

void MinPQ::swim( int k )
{
    while( k > 1 && pq[k/2] > pq[k] )
    {
        std::swap(pq[k/2], pq[k]);
        k = k/2;
    }
}

void MinPQ::sink(int k)
{
    while( 2 * k <= N )
    {
        int j = 2 * k;
        if( j < N && pq[j] > pq[j+1] )
            j++;
        if( pq[k] <= pq[j] )
            break;
        std::swap(pq[k], pq[j]);
        k = j;
    }
}


