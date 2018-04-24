//
//  MaxPQ.hpp
//  Dynamic Median
//
//  Created by Crystal Xu on 23/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef MaxPQ_hpp
#define MaxPQ_hpp

#include <stdio.h>
#include <vector>

class MaxPQ
{
public:
    MaxPQ(int capacity): N(0)
    {
        for( int i = 0; i <= capacity; ++i )
            pq.push_back(0);
    }
    
    ~MaxPQ() {}
    
    bool isEmpty()
    {
        return N == 0;
    }
    
    void insert( int x );
    
    int delMax();
    
    void swim( int k );
    void sink(int k);
    
    int heapSize() {return N;}
    
    int getRoot() {return pq[1];}
    
    void setRoot(int x) {pq[1] = x;}
    
private:
    std::vector<int> pq;
    int N;
};
#endif /* MaxPQ_hpp */
