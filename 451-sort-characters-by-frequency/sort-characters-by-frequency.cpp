class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map <char,int> mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        vector<string> bucket(s.size()+1);
        for(auto it:mp)
        {
            int cnt=it.second;
            while(cnt--)
            {
                bucket[it.second].push_back(it.first);
            }
        }
        for(int i=s.size();i>=0;i--)
        {
            if(!bucket[i].empty())
            {
                ans.append(bucket[i]);
            }
        }

        return ans;
        
    }
};