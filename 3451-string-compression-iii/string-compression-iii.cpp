class Solution {
public:
    string compressedString(string word) {
        int i=1;
        int cnt=1;
        char last=word[0];
        string ans;
        while(i<word.length()){
            if(word[i]==last && cnt<9){
                cnt++;
            }
            else{
                ans+=to_string(cnt);
                ans.push_back(last);
                cnt=1;
                last=word[i];
            }
            i++;
        }
        ans+=to_string(cnt);
        ans.push_back(last);

        return ans;

        
    }
};