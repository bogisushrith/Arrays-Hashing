#include <stack>
using namespace std;

class MinStack {
private:
    stack<int>st;
    stack<int>minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty() || minStack.top() >= val)
            minStack.push(val);
    }
    
    void pop() {
        int poppedElement = st.top();
        if(poppedElement == minStack.top())
            minStack.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
