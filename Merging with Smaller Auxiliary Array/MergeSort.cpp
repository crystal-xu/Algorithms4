//
//
//  MergeSort.cpp
//  Merge Sort
//
//  Created by Crystal Xu on 03/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include "MergeSort.hpp"
#include <vector>
#include <iostream>

void Merge::merge(std::vector<int> &a, std::vector<int> &aux, int lo, int mid, int hi)
{
    for( int k = lo; k <= hi; k++ )
        aux[k] = a[k];
    
    int i = lo, j = mid+1;
    for( int k = lo; k <= hi; k++ )
    {
        if( i > mid )
            a[k] = aux[j++];
        else if( j > hi )
            a[k] = aux[i++];
        else if( aux[j] < aux[i] )
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}
void Merge::sort( std::vector<int> &a, std::vector<int> &aux, int lo, int hi )
{
    if( hi <= lo )
        return;
    int mid = lo + (hi - lo)/2;
    sort(a, aux,  lo, mid);
    sort(a, aux,  mid+1, hi);
    if( a[mid+1] >= a[mid] )
        return;
    merge(a, aux, lo, mid, hi);
    /*for( auto &elem: aux )
     std::cout << elem << " ";
     std::cout << std::endl;
     for( auto &elem: a )
     std::cout << elem << " ";
     std::cout << std::endl;*/
}

void Merge::sort_with_smaller( std::vector<int> &a )
{
    int len = (int)a.size();
    if( a[len/2-1] < a[len/2] )
        return;
    std::vector<int> aux(len/2,0);
    for( int i = 0; i < len/2; i++ )
        std::swap(a[i], aux[i]);
    int i = 0, j = len/2, k = 0;
    for( ; k < len; k++ )
    {
        if( i >= len/2)
            a[k] = a[j++];
        else if( j >= len )
            a[k] = aux[i++];
        else if( aux[i] < a[j] )
            a[k] = aux[i++];
        else
            a[k] = a[j++];
    }
}
