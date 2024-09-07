class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) {
                pq.push(count);
            }
        }

        int t = 0;
        queue<pair<int, int>> q; 

        while (!pq.empty() || !q.empty()) {

            if (!q.empty() && q.front().first == t) {
                pq.push(q.front().second);
                q.pop();
            }
            
            if (!pq.empty()) {
                int remainingFreq = pq.top();
                pq.pop();
                if (remainingFreq > 1) {
                    q.push({t + n + 1, remainingFreq - 1}); 
                }
            }
            
            t++; 
        }

        return t;
    }
};
