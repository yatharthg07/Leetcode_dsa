class KthLargest {
public:
    int maxk;
    priority_queue<int,vector<int>,greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        maxk=k;
        for(auto it:nums)
        {
            minheap.push(it);
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }
        
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>maxk){
            minheap.pop();
        }
        
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */