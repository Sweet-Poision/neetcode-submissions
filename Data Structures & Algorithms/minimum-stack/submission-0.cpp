class MinStack {
private:
    vector<long long> st;
    long long mini;

public:
    MinStack() {}
    
    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push_back(val);
        } else {
            if (val < mini) {
                st.push_back(2LL * val - mini);
                mini = val;
            } else {
                st.push_back(val);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long top_val = st.back();
        st.pop_back();
        
        if (top_val < mini) {
            mini = 2LL * mini - top_val;
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        
        long long top_val = st.back();
        if (top_val < mini) {
            return mini;
        }
        return top_val;
    }
    
    int getMin() {
        return mini;
    }
};