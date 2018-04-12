//
//  main.cpp
//  Stack With Max
//
//  Created by Crystal Xu on 12/04/2018.
//  Copyright © 2018 Crystal Xu. All rights reserved.
//

#include <iostream>
#include <stack>

class StackWithMax
{
public:
    StackWithMax()
    {
    }
    
    void push(int x)
    {
        if( stack1.empty() )
        {
            stack1.push(x);
            stack2.push(x);
        }
        else
        {
            stack1.push(x);
            if( x > stack2.top() )
                stack2.push(x);
            else
                stack2.push(stack2.top());
        }
    }
    
    int pop()
    {
        if( stack1.empty() )
            return -1;
        int top = stack1.top();
        stack1.pop();
        stack2.pop();
        return top;
    }
    
    int peek()
    {
        if( stack1.empty() )
            return -1;
        else
            return stack1.top();
    }
    
    bool empty()
    {
        return (bool)stack1.empty();
    }
    
    int max()
    {
        if( stack2.empty() )
            return -1;
        else
            return stack2.top();
    }
    
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
