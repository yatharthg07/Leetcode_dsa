#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ll ans=0;
        int n=skill.size();
        ll sum=accumulate(skill.begin(),skill.end(),0);
        if(sum%(n/2)!=0)
        {
            return -1;
        }
        ll tar=sum/(n/2);

        unordered_map<int,int> mp;
        for(auto it:skill)
        {
            mp[it]++;
        }
        for(auto it:skill)
        {
            if(mp[it]!=0)
            {
                mp[it]--;
                if(mp.find(tar-it)==mp.end()||mp[tar-it]==0) return -1;
                else{ 
                    mp[tar-it]--;
                    ans+=(it*(tar-it));
                }
            }    
        }
        return ans;

        
    }
};