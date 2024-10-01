class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(256,0);
        for(auto c:magazine)
        {
            hash[c]++;
        }
        for(auto c:ransomNote)
        {
            if(hash[c]==0)
            {
                return false;
            }
            hash[c]--;
        }
        return true;
        
    }
};