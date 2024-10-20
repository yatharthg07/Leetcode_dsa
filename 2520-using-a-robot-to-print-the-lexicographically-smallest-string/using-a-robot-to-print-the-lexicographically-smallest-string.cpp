class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);  // Frequency of each character (a-z)
        for (char c : s) {
            freq[c - 'a']++;  // Count the occurrences of each character
        }
        
        stack<char> st;
        string ans;
        char minChar = 'a';  // Smallest character we need to consider for popping
        
        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;  // Reduce frequency as this character is processed
            
            // Update minChar to the smallest remaining character in `freq`
            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
                minChar++;
            }
            
            // Pop from stack while the top character is <= minChar
            while (!st.empty() && st.top() <= minChar) {
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        // Pop remaining characters from the stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
