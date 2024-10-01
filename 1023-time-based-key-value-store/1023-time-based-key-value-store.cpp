class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {

        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        const auto &v=mp[key];
        if(v.empty())
        {
            return "";
        }
        int l=0;
        int r=v.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[mid].first<=timestamp)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(ans==-1) return "";
        return v[ans].second;

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */