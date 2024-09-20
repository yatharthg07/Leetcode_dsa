class Solution {
public:
    bool ispal(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return s;
        
        int maxPalindromeLength = 0;
        
        // Check for the longest palindrome starting from index 0
        for (int i = n - 1; i >= 0; i--) {
            if (s[0] == s[i] && ispal(s, 0, i)) {
                maxPalindromeLength = i + 1;
                break;
            }
        }
        
        // If the entire string is a palindrome, return it as is
        if (maxPalindromeLength == n) {
            return s;
        }
        
        // Reverse the remaining suffix and add it to the front
        string suffix = s.substr(maxPalindromeLength);
        reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
};
