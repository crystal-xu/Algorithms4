//
//  percolation.hpp
//  Percolation
//
//  Created by Crystal Xu on 02/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#ifndef percolation_hpp
#define percolation_hpp

#include <stdio.h>
#include <vector>
#include "union_find.hpp"

class Percolation
{
public:
    Percolation(int n);
    ~Percolation() { delete uf;}
    void open(int row, int col);
    bool isOpen(int row, int col);
    int numberOfOpenSites() {return opensite_cnt;}
    bool percolates() { return uf->connected(0, grids_num + 1); }
    long double counts() { return (long double)numberOfOpenSites()/grids_num; }
    void Construct();
    
private:
    int grid_size;
    int grids_num;
    int opensite_cnt;
    std::vector<bool> sites_table;
    UF *uf;
};


#endif /* percolation_hpp */
