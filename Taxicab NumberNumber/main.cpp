//
//  main.cpp
//  Taxicab Numbers
//
//  Created by Crystal Xu on 08/05/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include "Taxicab.hpp"

void TaxicabNumber( int n )
{
    std::priority_queue<Taxicab, std::vector<Taxicab>, myComparator> pq;
    for( int i = 1; i <= n; i++ )
    {
        pq.push(Taxicab(i, i));
    }
    
    int run = 1;
    Taxicab prev(0, 0);
    while( !pq.empty() )
    {
        Taxicab curr = pq.top();
        pq.pop();
        // current sum is the same as previous sum
        if( prev.sum == curr.sum )
        {
            run++;
            if( run == 2 )
                std::cout << prev.i << "^3 + " << prev.j << "^3 = "
                << curr.i << "^3 + " << curr.j << "^3 " << std::endl;
        }
        else
        {
            if( run > 1 )
                run = 1;
        }
        prev = curr;
        if( curr.j < n )
            pq.push(Taxicab(curr.i, curr.j+1));
    }
}

int main(int argc, const char * argv[]) {

    TaxicabNumber(20);
    return 0;
}
