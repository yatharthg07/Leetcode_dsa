#define ll long long 
class MinStack {
public:
    stack<ll> st;
    ll min;

    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            min = val;
        } else {
            if(val < min) {
                st.push(2ll * val - min);  
                min = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
       ll top = st.top();
        if(top < min) {
            min = 2ll * min - top;  
        }
        st.pop();
    }
    
    int top() {
        ll top = st.top();
        if(top < min) {

            return min;
        } else {
            return top;
        }
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
