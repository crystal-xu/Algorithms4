//
//  main.cpp
//  Shuffling a Link List
//
//  Created by Crystal Xu on 17/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>

struct Node
{
    Node( int x ): val(x) {}
    int val;
    Node *next;
};

void Merge(Node *&lhead, Node *&rhead)
{
    if( lhead == NULL || rhead == NULL )
        return;
    Node *left = lhead;
    Node *right = rhead;
    if( rand()%2 == 0 )
    {
        lhead = rhead;
        right = right->next;
        lhead->next = left;
        left = left->next;
    }
    else
    {
        left = left->next;
        lhead->next = right;
        right = right->next;
    }

    Node *pt = lhead->next;
    while( left != NULL || right != NULL )
    {
        if( left == NULL )
        {
            pt->next = right;
            pt = right;
            right = right->next;
        }
        else if( right == NULL )
        {
            pt->next = left;
            pt = left;
            left = left->next;
        }
        else if( rand() % 2 == 0 )
        {
            pt->next = right;
            right = right->next;
            pt->next->next = left;
            pt = left;
            left = left->next;
        }
        else
        {
            pt->next = left;
            left = left->next;
            pt->next->next = right;
            pt = right;
            right = right->next;
        }
    }
}

void Shuffle( Node *&node )
{
    // divide the link list into two halves
    // p1 moves one step, p2 moves two steps each loop, p3 saves previous node of p1
    if( node == NULL || node->next == NULL )
        return;
    Node *p1 = node, *p2 = node, *p3 = p1;
    while( true )
    {
        if( p1 == NULL || p2 == NULL || p2->next == NULL )
            break;
        p3 = p1;
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p3->next = NULL;
    Shuffle(node);
    Shuffle(p1);
    Merge(node, p1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Node *head = new Node(0);
    Node *pt = head;
    for( int i = 1; i < 10; ++i )
    {
        Node *node = new Node(i);
        pt->next = node;
        pt = node;
    }
    pt->next = NULL;
    Shuffle(head);
    pt = head;
    while( pt )
    {
        std::cout << pt->val << " ";
        pt = pt->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
