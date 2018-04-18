//
//  main.cpp
//  Social Network Connectivity
//
//  Created by Crystal Xu on 12/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//


#include <iostream>
#include <map>
#include "SocialConn.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::map<int, std::pair<int, int>> timestamps{{0, {0,1}},{1, {1,2}}, {5, {2,3}}};
    SocialNet *social = new SocialNet(4, timestamps);
    int time = social->LeastConnTimeS();
    std::cout << time << std::endl;
    return 0;
}
