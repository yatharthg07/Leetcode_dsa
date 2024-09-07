/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QDsFBLGL9MM
    Company Tags  : Facebook
    Leetcode Link : https://leetcode.com/problems/task-scheduler/
    
    Heap based approach : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Heap/Task%20Scheduler.cpp
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        
        if(p == 0)
            return n;
        
        int counter[26] = {0};
        for(char &ch : tasks) {
            counter[ch-'A']++;
        }
        
        sort(begin(counter), end(counter));
        
        int chunks      = counter[25]-1;
        int idolSpots   = chunks*p;
        
        for(int i = 24; i>=0 ; i--) {
            idolSpots -= min(chunks, counter[i]);
        }
        
        if(idolSpots > 0)
            return n + idolSpots;
        
        return n;
    }
};