class MyStack {
public:
    queue<int> q;
    MyStack() {
        queue<int> q1;
        q = q1;
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        for(int i=1;i<n;i++) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        int n = q.size();
        for(int i=1;i<n;i++) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int x = q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        if(q.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */