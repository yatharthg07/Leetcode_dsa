class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> word;
        for(auto it:wordList)
        {
            word.insert(it);
        }
        int cnt=0;
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        int ans=0;
        int flag=0;
        while(!q.empty())
        {
            pair<string, int> front = q.front();
            string s=front.first;
            int lvl=front.second;
            q.pop();
            for(int i=0;i<front.first.length();i++)
            {
                for (char letter = 'a'; letter <= 'z'; ++letter) {
                    
                    string t=s;
                    t[i]=letter;

                    if(word.find(t)!=word.end())
                    {
                        word.erase(t); 
                        if(t==endWord)
                        {
                            ans=lvl+2;
                            flag=1;
                            break;
                        }
                        q.push({t,lvl+1});
                    }
                    
                }
                if(flag) break;
            }
            if(flag) break;


        }

        return ans;
        
    }
};