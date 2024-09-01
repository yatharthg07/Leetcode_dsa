class StockSpanner {
public:
    stack<pair<int,int>> st;
    int cnt;
    StockSpanner() {
        
    }
    
    int next(int price) {
        cnt=1;
        while(!st.empty() && st.top().first<=price)
        {
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return cnt;             
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */