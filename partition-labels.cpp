class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }
        int farthest=mp[s[0]];
        int last=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
             farthest=max(farthest,mp[s[i]]);
            if(i==farthest)
            {
                ans.push_back(i+1-last);
                last=i+1;

                continue;
            }
           


        }
        return ans;
        
    }
};