class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n=tasks.size();
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> pq; 
        
        for(auto &it : freq) {
            if(it>0)
                pq.push(it);
        }
        int idlespots= (pq.top()-1)*p;
        int gapp=pq.top()-1;
        pq.pop();
        while(!pq.empty())
        {
            int freqq=pq.top();
            pq.pop();
            idlespots-=min(freqq,gapp);
            if(idlespots<=0)
            {
                return n;
            }
        }
        return idlespots+n;
        
        
    }
};
