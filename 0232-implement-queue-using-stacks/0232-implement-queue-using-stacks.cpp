class MyQueue {
public:
    MyQueue() {
    }
        stack<int> st1;
        stack<int> st2;
    
    void push(int x) {
       st2.push(x); 
    }
    
    int pop() {
        int val = 0;
        while(st2.size() > 0){
            st1.push(st2.top());
            st2.pop();
        }
        val = st1.top();
        st1.pop();
        while(st1.size()>0){
            st2.push(st1.top());
            st1.pop();
        }
        return val;
    }
    
    int peek() {
          int val = 0;
        while(st2.size() > 0){
            st1.push(st2.top());
            st2.pop();
        }
        val = st1.top();
        while(st1.size()>0){
            st2.push(st1.top());
            st1.pop();
        }
        return val;
    }
    
    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */