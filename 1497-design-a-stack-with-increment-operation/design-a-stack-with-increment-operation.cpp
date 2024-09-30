class CustomStack {
public:
    int size;
    vector<int> st;
    int maxSize;
    unordered_map<int,int> mp;

    CustomStack(int maxSize) {
        this->size=0;
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(size==maxSize)
        {
            return;
        }
        else
        {
            st.push_back(x);
            size++;
        }
    }
    
    int pop() {
        
        if(st.size()==0)
        {
            return -1;
        }
        else{
            int temp=st[size-1];
            st.pop_back();
            size--;
            mp[size-1]+=mp[size];
            temp=temp+mp[size];
            mp[size]=0;
            return temp;
        }
    }
    
    void increment(int k, int val) {
        mp[min(k,size)-1]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */