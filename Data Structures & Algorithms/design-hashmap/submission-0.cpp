class MyHashMap {
   private:
    int m_size = 1000;
    vector<list<pair<int, int>>> m_buckets;

   public:
    MyHashMap() : m_buckets(m_size) {}

    void put(int key, int value) {
        int index = key % m_size;
        for (auto& pair : m_buckets[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        m_buckets[index].push_back({key, value});
    }

    int get(int key) {
        int index = key % m_size;
        for (auto& pair : m_buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = key % m_size;
        auto& bucket = m_buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */