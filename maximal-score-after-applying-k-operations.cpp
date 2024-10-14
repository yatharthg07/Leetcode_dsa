class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(begin(nums), end(nums));
        long long score=0;
        while(!pq.empty() && k!=0)
        {
            int val=pq.top();
            pq.pop();
            score+=val;
            pq.push((ceil(val/3.0)));
            k--;
        }
        return score;

        
    }
};