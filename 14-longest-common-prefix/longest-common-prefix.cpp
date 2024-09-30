class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        int flag=0;
        while(1)
        {
            if(i==strs[0].length())
            {
                break;
            }                
            char c=strs[0][i];
            for(auto s:strs)
            {
                if(i>=s.length()||s[i]!=c)
                {
                    flag=1;
                    break;
                }    
            }
            if(flag) break;
            ans.push_back(strs[0][i]);
            i++;
        }
        return ans;
        
    }
};