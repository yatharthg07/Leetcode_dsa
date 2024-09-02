class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, pair<int, list<pair<int,int>>::iterator>> mp; // {key: {frequency, iterator in freq list}}
    unordered_map<int, list<pair<int,int>>> freq; // {freq: list of {key, value}}

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        // Get current frequency and the iterator of the key
        int currentFreq = mp[key].first;
        auto node = mp[key].second;
        int value = node->second;

        // Remove the key from the current frequency list
        freq[currentFreq].erase(node);
        if (freq[currentFreq].empty()) {
            freq.erase(currentFreq);
            if (minFreq == currentFreq) {
                minFreq++;
            }
        }

        // Increase frequency and add to the new list
        freq[currentFreq + 1].push_front({key, value});
        mp[key] = {currentFreq + 1, freq[currentFreq + 1].begin()};

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mp.find(key) != mp.end()) {
            // Key exists, update the value and frequency
            mp[key].second->second = value;
            get(key); // This will handle the frequency increment
            return;
        }

        if (mp.size() == capacity) {
            // Evict the least frequently used key
            auto nodeToEvict = freq[minFreq].back();
            int evictKey = nodeToEvict.first;
            freq[minFreq].pop_back();
            if (freq[minFreq].empty()) freq.erase(minFreq);
            mp.erase(evictKey);
        }

        // Insert the new key-value pair with frequency 1
        freq[1].push_front({key, value});
        mp[key] = {1, freq[1].begin()};
        minFreq = 1; // Reset minFreq to 1 since we're adding a new key
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
