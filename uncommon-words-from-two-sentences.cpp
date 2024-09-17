class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> st;
        vector<string> ans;
        stringstream ss(s1);
        string word;
        while(ss>>word)
        {
            st[word]++;
        }
        stringstream sss(s2);
        while(sss>>word)
        {
            st[word]++;
        }

        for(auto it:st)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};