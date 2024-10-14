class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        string temp;
        for(int i=0;i<searchWord.length();i++)
        {
            vector<string> t;
            temp.push_back(searchWord[i]);
            auto it=lower_bound(products.begin(),products.end(),temp);
            int cnt=3;
            while(cnt!=0 && it!=products.end() && ((*it).substr(0,i+1)==temp))
            {
                t.push_back(*it);
                it++;
                cnt--;
            }
            ans.push_back(t);
        }
        return ans;

    }
};