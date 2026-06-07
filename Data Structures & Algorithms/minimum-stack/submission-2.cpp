class MinStack {
public:

    stack<pair<int,int>> st;

    MinStack() {
    }
    
    void push(int val) {
        int mini = INT_MAX;
        if(!st.empty()) {
            mini = min(st.top().second, val);
        }
        else mini = val;
        st.push({val, mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if(!st.empty()) return st.top().first;
        return -1;     
    }
    
    int getMin() {
        if(!st.empty()) return st.top().second;
        return -1;
    }
};
