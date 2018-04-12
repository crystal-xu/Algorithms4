//
//  union_find.hpp
//  Social Network Connectivity
//
//  Created by Crystal Xu on 12/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef union_find_hpp
#define union_find_hpp

#include <stdio.h>
#include <vector>

class UF
{
public:
    UF(int N)
    {
        for( int i = 0; i < N; i++ )
        {
            id.push_back(i);
            sz.push_back(1);
        }
    }
    void w_union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if( i == j )
            return;
        if( sz[i] < sz[j] )
        {
            id[j] = i;
            sz[i] = sz[i] + sz[j];
        }
        else
        {
            id[i] = j;
            sz[j] = sz[i] + sz[j];
        }
    }
    
    bool connected(int p, int q) { return root(p) == root(q); }
    int root(int i)
    {
        while( i != id[i] )
            i = id[i];
        return i;
    }
    
private:
    std::vector<int> id;
    std::vector<int> sz;
};

#endif /* union_find_hpp */
