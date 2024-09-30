class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(256, 0);
        

        for (char c : s) {
            freq[c]++;
        }
        
        int ans = 0;
        bool hasOdd = false;
        

        for (int count : freq) {
            if (count % 2 == 0) {

                ans += count;
            } else {

                ans += count - 1;
                hasOdd = true;
            }
        }
        
       
        if (hasOdd) {
            ans += 1;
        }
        
        return ans;
    }
};
