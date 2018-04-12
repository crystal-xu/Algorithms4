//
//  SocialConn.hpp
//  Social Network Connectivity
//
//  Created by Crystal Xu on 12/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef SocialConn_hpp
#define SocialConn_hpp

#include <stdio.h>
#include <map>
#include <utility>
#include "union_find.hpp"

class SocialNet
{
public:
    SocialNet(int n, std::map<int, std::pair<int, int>> &times):N(n)
    {
        uf = new UF(n);
        timestamps.swap(times);
    }
    
    ~SocialNet()
    {
        delete uf;
    }
    
    int LeastConnTimeS()
    {
        int count = 0;
        for( auto &elem:timestamps )
        {
            int timestamp = elem.first;
            std::pair<int, int> friendship = elem.second;
            int p1 = friendship.first;
            int p2 = friendship.second;
            if( !(uf->connected(p1, p2)) )
            {
                count++;
                uf->w_union(p1, p2);
            }
            if( count == N-1 )
                return timestamp;
        }
        return -1;
    }
    
private:
    int N;
    UF *uf;
    std::map<int, std::pair<int, int>> timestamps;
};

#endif /* SocialConn_hpp */
