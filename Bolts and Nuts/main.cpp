//
//  main.cpp
//  Nuts and Bolts
//
//  Created by Crystal Xu on 18/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>
#include <vector>


int Partition(std::vector<int> &arr, int pivot, int lo, int hi)
{
    int i = lo - 1, j = hi + 1;
    while(true)
    {
        while(arr[++i] < pivot)
        {
            if(i == hi)
                break;
        }
        while(arr[--j] > pivot)
        {
            if(j == lo)
                break;
        }
        if(i >= j)
            break;
        std::swap(arr[i], arr[j]);
    }
    return i;
}

void sort(std::vector<int> &bolts, std::vector<int> &nuts, int lo, int hi)
{
    if( lo >= hi )
        return;
    
    // use bolts[lo] as pivot for sorting nuts, returning pivot value
    // then use nuts[pivot](boundry point) as pivot for sorting bolts
    int pos = Partition(nuts, bolts[lo], lo, hi);
    Partition(bolts, nuts[pos], lo, hi);
    // recursion
    sort(bolts, nuts, lo, pos-1);
    sort(bolts, nuts, pos+1, hi);
}

void sort(std::vector<int> &bolts, std::vector<int> &nuts)
{
    int len = (int)bolts.size();
    sort(bolts, nuts, 0, len-1);
}
int main(int argc, const char * argv[]) {
    std::vector<int> bolts{5,4,3,2,1};
    std::vector<int> nuts{1,2,3,4,5};
    sort(bolts, nuts);
    for(auto &elem:bolts)
        std::cout << elem << " ";
    std::cout << std::endl;
    for(auto &elem:nuts)
        std::cout << elem << " ";
    std::cout << std::endl;
    return 0;
}
