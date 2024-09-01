class StockSpanner {
public:
    stack<pair<int,int>> st;
    int cnt;
    StockSpanner() {
        
    }
    
    int next(int price) {
        cnt=0;
        while(!st.empty() && st.top().first<=price)
        {
            cnt+=st.top().second;
            st.pop();
            cnt++;
        }
        st.push({price,cnt});
        return cnt+1;             
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */