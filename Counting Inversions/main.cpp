
#include <iostream>
#include "MergeSort.hpp"
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> a{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    Merge *merge = new Merge();
    int res = merge->sort(a);
    for( auto &elem:a )
        std::cout << elem << " ";
    std::cout << std::endl;
    std::cout << res << std::endl;
    return 0;
}
