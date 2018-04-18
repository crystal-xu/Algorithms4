//
//  main.cpp
//  Social Network Connectivity
//
//  Created by Crystal Xu on 12/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

/*
Given a social network containing n members and a log file containing m timestamps at
which times pairs of members formed friendships, design an algorithm to determine the 
earliest time at which all members are connected (i.e., every member is a friend of a
friend of a friend ... of a friend). Assume that the log file is sorted by timestamp 
and that friendship is an equivalence relation. The running time of your algorithm s
hould be mlogn or better and use extra space proportional to n.
*/


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
