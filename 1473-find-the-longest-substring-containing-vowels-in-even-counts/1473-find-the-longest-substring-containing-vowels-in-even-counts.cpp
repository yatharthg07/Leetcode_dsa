class Solution {
public:
    string utility(vector<int> &v)
    {
        string temp;
        for(auto &it:v)
        {
            it=it%2;
            temp.push_back(it+'0');
        }
        return temp;
    }
    int findTheLongestSubstring(string s) {
        int ans=0;
        string temp;
        unordered_map<string,int> mp;
        vector<int> v(5,0);
        mp[utility(v)]=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')      v[0]++;
            else if(s[i]=='e') v[1]++;
            else if(s[i]=='i') v[2]++;
            else if(s[i]=='o') v[3]++;
            else if(s[i]=='u') v[4]++;
            temp=utility(v);
            if(mp.find(temp)!=mp.end())
            {
                ans=max(ans,i-mp[temp]);
            }
            else
                mp[temp]=i;

        }
        return ans;
    }
};