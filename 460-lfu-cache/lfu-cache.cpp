class LFUCache {
private:
    int cap;
    int size;
    int minFreq;
    unordered_map<int, list<vector<int>>::iterator> mp; // key -> iterator to the list containing {key, value, freq}
    unordered_map<int, list<vector<int>>> freq; // freq -> list of vectors {key, value, freq}

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        minFreq = 0;
    }

    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);

        int value = vec[1];
        int f = vec[2];

        // Remove from current frequency list
        freq[f].erase(mp[key]);
        if (freq[f].empty()) {
            freq.erase(f);
            if (minFreq == f) {
                minFreq++;
            }
        }

        // Increase frequency and add to the new frequency list
        f++;
        freq[f].push_front({key, value, f});
        mp[key] = freq[f].begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        auto &vec = *(mp[key]);
        int value = vec[1];

        makeMostFrequentlyUsed(key);

        return value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mp.find(key) != mp.end()) {
            // Key already exists, update the value and make it most frequently used
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        } else {
            if (size == cap) {
                // Evict the least frequently used key (and least recently used if tied)
                auto &listToEvict = freq[minFreq];
                int keyToEvict = listToEvict.back()[0];
                listToEvict.pop_back();
                if (listToEvict.empty()) {
                    freq.erase(minFreq);
                }
                mp.erase(keyToEvict);
                size--;
            }

            // Insert the new key-value pair with frequency 1
            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
            minFreq = 1; // Reset minFreq to 1 since we added a new key
            size++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
