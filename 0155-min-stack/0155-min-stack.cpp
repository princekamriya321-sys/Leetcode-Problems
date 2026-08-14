class MinStack {
public:
stack<int> st;
stack<int> minst;
    MinStack() {   
    }
    
    void push(int value) {
        st.push(value);
        if(minst.size() == 0 || minst.top() > value){
            minst.push(value);
        } else {
            minst.push(minst.top());
        }
    }
    
    void pop() {
        if(st.size() > 0){
            st.pop();
            minst.pop();
        }
    }
    
    int top() {
      return st.top();  
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */