class MyQueue
{
public:
    MyQueue()
    {
        
    }
    
    void push(int x)
    {
        if( stack1.empty() )
            stack1.push(x);
        else
        {
            while( !stack1.empty()  )
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack1.push(x);
            while( !stack2.empty() )
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
    
    int pop()
    {
        if( stack1.empty() )
            return -1;
        int top = stack1.top();
        stack1.pop();
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
    
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};
