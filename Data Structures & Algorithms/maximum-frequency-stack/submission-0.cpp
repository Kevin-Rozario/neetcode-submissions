class FreqStack {
    unordered_map<int, int> freqMap;
    unordered_map<int, vector<int>> groupMap;
    int maxFreq;

   public:
    FreqStack() : maxFreq(0) {}

    void push(int val) {
        int f = ++freqMap[val];

        if (f > maxFreq) maxFreq = f;

        groupMap[f].push_back(val);
    }

    int pop() {
        int val = groupMap[maxFreq].back();
        groupMap[maxFreq].pop_back();

        freqMap[val]--;

        if (groupMap[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */