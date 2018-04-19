//
//  main.cpp
//  Selection in Two Sorted Arrays
//
//  Created by Crystal Xu on 19/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>
#include <vector>

// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/
int findKthSmallest(std::vector<int> &A, int start1, int end1, std::vector<int> &B, int start2, int end2, int k)
{
    int mid1 = start1+(end1-start1)/2;
    int mid2 = start2+(end2-start2)/2;
    if( start1 > end1 )
        return B[mid2];
    if( start2 > end2 )
        return A[mid1];
    if( mid1 + mid2 < k )
    {
        if( A[mid1] < A[mid2] )
            return findKthSmallest(A, mid1+1, end1, B, start2, end2, k);
        else
            return findKthSmallest(A, start1, end1, B, mid2+1, end2, k);
    }
    else
    {
        if( A[mid1] < A[mid2] )
            return findKthSmallest(A, start1, end1, B, start2, mid2-1, k);
        else
            return findKthSmallest(A, start1, mid1-1, B, start2, end2, k);
    }
}

// https://articles.leetcode.com/find-k-th-smallest-element-in-union-of/
int findKthSmallest2(std::vector<int> &A, int start1, int end1, std::vector<int> &B, int start2, int end2, int k)
{
    int len1 = end1 - start1;
    int len2 = end2 - start2;
    int i = start1 + (int)(double)(len1/(len1+len2)*(k-1));
    int j = start2 + k - 1 - i;
    
    int Ai = i == end1 ? INT_MAX:A[i];
    int Bj = j == end2 ? INT_MAX:B[j];
    int Ai1 = i == 0 ? INT_MIN:A[i-1];
    int Bj1 = j == 0? INT_MIN:B[j-1];
    if( Ai < Bj && Ai > Bj1 )
        return Ai;
    else if( Bj < Ai && Bj > Ai1 )
        return Bj;
    if( Ai < Bj )
        return findKthSmallest(A, i+1, end1, B, start2, j, k);
    else
        return findKthSmallest(A, start1, i, B, j+1, end2, k);
}

int findKthSmallest(std::vector<int> &A, std::vector<int> &B, int k)
{
    int len1 = (int)A.size();
    int len2 = (int)B.size();
    if( len1 + len2 < k )
        return -1;
    int res = findKthSmallest(A, 0, len1-1, B, 0, len2-1,k);
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<int> A{2,3,4,6,7,9,11};
    std::vector<int> B{1,1,4,8,10};
    int k = 5;
    int res = findKthSmallest(A, B, k);
    std::cout << res << std::endl;
    return 0;
}
