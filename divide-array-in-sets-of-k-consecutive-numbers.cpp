class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
        {
            return false;
        }
        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());
        for(auto it:hand)
        {
            mp[it]++;
        }
        for(auto it:hand)
        {
            if(mp[it]>0)
            {
                for(int i=0;i<groupSize;i++)
                {
                    if(mp.find(it+i)==mp.end()||mp[it+i]<=0)
                    {
                        return false;
                    }
                    mp[it+i]--;
                }
            }
        }
        return true;
        
    }
};