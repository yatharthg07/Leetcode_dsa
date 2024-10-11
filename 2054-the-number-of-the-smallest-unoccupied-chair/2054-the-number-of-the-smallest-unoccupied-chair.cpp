
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
    int cnt=0;
    int req=0;
    int i=0;
    int j=0;
    while(i!=n && j!=n)
    {
        if(a[i].first<=d[j].first)
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        req=max(req,cnt);
    }
    set<pair<int,int>> mp;
    for(int i=0;i<req;i++)
    {
        mp.insert({0,i});
    }
    unordered_map<int,int> taken;
    i=0;j=0;
    while(i!=n&& j!=n)
    {
        if(a[i].first<d[j].first)
        {
            auto it=mp.lower_bound({0,0});
            int temp=it->second;
            if(a[i].second==targetFriend)
            {
                return temp;
            }
            taken[a[i].second]=temp;
            mp.erase(it);
            mp.insert({1,temp});
            i++;
        }
        else
        {
            int temp=taken[d[j].second];
            auto it=mp.find({1,temp});
            mp.erase(it);
            mp.insert({0,temp});
            j++;
        }
    }
    return taken[targetFriend];

    

        
    }
};