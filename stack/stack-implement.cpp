#include <iostream>
#include <stdexcept>

class SimuStack
{
private:
    static const int SIZE = 10;
    int stack[SIZE];
    int top;

public:
    SimuStack() : top(-1) {}

    void push(int val)
    {
        if (top >= SIZE - 1)
            throw std::overflow_error("Stack overflow");
        stack[++top] = val;
        std::cout << "Pushed " << val << " at index " << top << std::endl;
    }

    int pop()
    {
        if (top < 0)
            throw std::underflow_error("Stack underflow");
        std::cout << "Popped " << stack[top] << " from index " << top << std::endl;
        return stack[top--];
    }

    int peek() const
    {
        if (top < 0)
            throw std::underflow_error("Stack empty");
        return stack[top];
    }

    bool empty() const { return top < 0; }
};

int main()
{
    SimuStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}