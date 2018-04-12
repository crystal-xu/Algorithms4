//
//  union_find.hpp
//  Union Find
//
//  Created by Crystal Xu on 02/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef union_find_hpp
#define union_find_hpp

#include <stdio.h>
#include <vector>

class UF
{
public:
    UF(int N);
    void w_union(int p, int q);
    bool connected(int p, int q) { return root(p) == root(q); };
    int root(int i);
    int find(int i);
    
private:
    std::vector<int> id;
    std::vector<int> sz;
    std::vector<int> large; 
};

#endif /* union_find_hpp */
