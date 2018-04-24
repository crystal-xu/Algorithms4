//
//  DynamicMedian.cpp
//  Dynamic Median
//
//  Created by Crystal Xu on 24/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <stdio.h>
#include "DynamicMedian.hpp"

void DynamicMedian::insert(int x)
{
    if( maxHeap->isEmpty() )
        maxHeap->insert(x);
    else if( minHeap->isEmpty() )
    {
        int tmp = maxHeap->getRoot();
        if( tmp > x)
        {
            maxHeap->setRoot(x);
            minHeap->insert(tmp);
        }
        else {
            minHeap->insert(x);
        }
    }
    else
    {
        int max_r = maxHeap->getRoot();
        if( x <= max_r )
            maxHeap->insert(x);
        else
            minHeap->insert(x);
        balanceHeap();
    }
}

void DynamicMedian::balanceHeap()
{
    int len1 = maxHeap->heapSize();
    int len2 = minHeap->heapSize();
    
    if( std::abs(len1-len2)<=1 )
        return;
    
    if( len1 > len2 )
    {
        int max_r = maxHeap->getRoot();
        maxHeap->delMax();
        minHeap->insert(max_r);
    }
    else
    {
        int min_r = minHeap->getRoot();
        minHeap->delMin();
        maxHeap->insert(min_r);
    }
}
