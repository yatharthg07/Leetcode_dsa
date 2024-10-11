
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n=times.size();

    vector<pair<int,int>> a(n);
    vector<pair<int,int>> d(n);
    for(int i=0;i<n;i++)
    {
        a[i]={times[i][0],i};
        d[i]={times[i][1],i};
    }
    sort(a.begin(),a.end());
    sort(d.begin(),d.end());
    int i=0;
    int j=0;
    set<int> s;
    unordered_map<int,int> taken;
    int chair=0;
    while(i!=n && j!=n)
    {
        if(a[i].first<d[j].first)
        {
            if(s.empty())
            {
                taken[a[i].second]=chair++;
            }
            else
            {
                taken[a[i].second]=*s.begin();
                s.erase(s.begin());
            }
            i++;
        }
        else
        {
            s.insert(taken[d[j].second]);
            j++;
        }
    }
    return taken[targetFriend];
    

        
    }
};