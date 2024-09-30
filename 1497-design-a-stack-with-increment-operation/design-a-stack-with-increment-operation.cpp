class CustomStack {
public:
    int size;
    vector<int> st;
    int maxSize;
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
            return temp;
        }
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,size);i++)
        {
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */