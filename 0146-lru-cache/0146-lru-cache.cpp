class LRUCache {
public:
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        lru.erase(mp[key].second);
        lru.push_front(key);

        mp[key].second = lru.begin();

        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key].second);
        }
        else if (mp.size() == cap) {
            int old = lru.back();
            lru.pop_back();
            mp.erase(old);
        }

        lru.push_front(key);
        mp[key] = {value, lru.begin()};
    }
};