class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int count=0;
        int maxlen=0;
        while(r<n)
        {
            if(mp.find(fruits[r])==mp.end())
            {
                mp[fruits[r]]=1;
                count++;
            }
            else
            {
                mp[fruits[r]]++;
            }
            if(count>2)
            {
                if(mp[fruits[l]]==1)
                {
                    mp.erase(fruits[l]);
                    count--;
                }
                else
                    mp[fruits[l]]--;  
                l++;      

            }
            maxlen=max(maxlen,r-l+1);
            r++;

            
        }
        return maxlen;
        
    }
};