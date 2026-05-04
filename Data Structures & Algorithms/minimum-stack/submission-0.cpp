class MinStack {
    stack<pair<int, int>> s;

   public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
            return;
        }

        pair<int, int> p = s.top();
        int minValue = (val < p.second) ? val : p.second;
        s.push({val, minValue});
    }

    void pop() { return s.pop(); }

    int top() { return s.top().first; }

    int getMin() { return s.top().second; }
};
