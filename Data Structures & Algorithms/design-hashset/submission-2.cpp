class MyHashSet {
   private:
    int m_size = 1000;
    vector<list<int>> m_customSet;

   public:
    MyHashSet() : m_customSet(m_size) {}

    void add(int key) {
        int index = key % m_size;
        if (!contains(key)) {
            m_customSet[index].push_back(key);
        }
    }

    void remove(int key) {
        int index = key % m_size;
        m_customSet[index].remove(key);
    }

    bool contains(int key) {
        int index = key % m_size;
        auto& bucket = m_customSet[index];
        auto it = find(bucket.begin(), bucket.end(), key);
        return it != bucket.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */