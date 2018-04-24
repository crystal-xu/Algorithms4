//
//  MinPQ.hpp
//  Dynamic Median
//
//  Created by Crystal Xu on 23/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef MinPQ_hpp
#define MinPQ_hpp

#include <stdio.h>
#include <vector>

class MinPQ
{
public:
    MinPQ(int capacity): N(0)
    {
        for( int i = 0; i <= capacity; ++i )
            pq.push_back(0);
    }
    
    ~MinPQ() {}
    
    bool isEmpty()
    {
        return N == 0;
    }
    
    void insert( int x );
    
    int delMin();
    
    void swim( int k );
    void sink(int k);
    
    int heapSize() {return N;}
    int getRoot() {return pq[1];}
    
    void setRoot(int x) {pq[1] = x;}    
    
private:
    std::vector<int> pq;
    int N;
};

#endif /* MinPQ_hpp */
