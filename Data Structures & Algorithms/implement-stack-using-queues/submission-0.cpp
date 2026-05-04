class MyStack {
    vector<int> customQueue;

   public:
    MyStack() {}

    void push(int x) { customQueue.push_back(x); }

    int pop() {
        if (empty()) return -1;
        int result = customQueue[customQueue.size() - 1];
        customQueue.pop_back();
        return result;
    }

    int top() {
        if (empty()) return -1;
        return customQueue[customQueue.size() - 1];
    }

    bool empty() { return customQueue.size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */