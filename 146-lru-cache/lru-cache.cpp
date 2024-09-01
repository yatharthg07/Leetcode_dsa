class LRUCache {
public:
    int capacity;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    LRUCache(int capacity) {
        this->capacity=capacity;
        
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;          
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key]->second=value;
            l.splice(l.begin(),l,mp[key]);
            return;
        }
        if(mp.size()==capacity)
        {
            int delkey=l.back().first;
            l.pop_back();
            mp.erase(delkey);
        }
        l.push_front({key,value});
        mp[key]=l.begin();

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */