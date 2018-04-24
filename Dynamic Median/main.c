//
//  DynamicMedian.hpp
//  Dynamic Median
//
//  Created by Crystal Xu on 24/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef DynamicMedian_hpp
#define DynamicMedian_hpp

#include <stdio.h>
#include "MaxPQ.hpp"
#include "MinPQ.hpp"

class DynamicMedian
{
public:
    DynamicMedian(int _cap)
    {
        maxHeap = new MaxPQ(_cap);
        minHeap = new MinPQ(_cap);
    }
    ~DynamicMedian()
    {
        delete maxHeap;
        delete minHeap;
    }
    
    void insert(int x);

    int getMedian()
    {
        int len1 = maxHeap->heapSize();
        int len2 = minHeap->heapSize();
        if( len1 == len2 )
            //return ((double)maxHeap->getRoot() + minHeap->getRoot())/2;
            return minHeap->getRoot();
        else if( len1 > len2 )
            return maxHeap->getRoot();
        else
            return minHeap->getRoot();
    }
    int rmMedian()
    {
        int len1 = maxHeap->heapSize();
        int len2 = minHeap->heapSize();
        if( len1 > len2 )
            return maxHeap->delMax();
        else
            return minHeap->delMin();
    }
    
    void balanceHeap();
    
private:
    MaxPQ *maxHeap;
    MinPQ *minHeap;
};

#endif /* DynamicMedian_hpp */
