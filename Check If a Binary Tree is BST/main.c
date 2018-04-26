//
//  main.cpp
//  BST
//
//  Created by Crystal Xu on 09/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>
#include "BST.hpp"

// wrong solution
/*bool IsBST(Node *root)
{
    if( root == NULL )
        return true;
    if( root->left == NULL && root->right == NULL )
        return true;
    if( root->left == NULL && root->right->key > root->key )
        return IsBST(root->right);
    if( root->right == NULL && root->left->key < root->key )
        return IsBST(root->left);
    if( root->key <= root->left->key || root->key >= root->right->key )
        return false;
    if( !IsBST(root->left) )
        return false;
    return IsBST(root->right);
}*/

bool IsBST(Node *root, int min, int max)
{
    if( root == NULL )
        return true;
    if( root->left != NULL && root->left->key >= root->key )
        return false;
    if( root->right != NULL && root->right->key <= root->key )
        return false;
    if( !IsBST(root->left, min, root->key) || !IsBST(root->right, root->key, max))
        return false;
    return true;
}

bool IsBST(Node *root)
{

    return IsBST(root, INT_MIN, INT_MAX);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Node *root = new Node(0,0);
    Node *x1 = new Node(1,1);
    Node *x2 = new Node(2,1);
    Node *x3 = new Node(3,1);
    Node *x4 = new Node(4,1);
    Node *x5 = new Node(5,1);
    root->left = x1;
    root->right = x3;
    x3->left = x2;
    x3->right = x4;
    x4->right = x5;
    bool res = IsBST(x3);
    std::cout << res << std::endl;
    return 0;
}
