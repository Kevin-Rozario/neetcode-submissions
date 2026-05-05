class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> output(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prevIndex = s.top();
                s.pop();
                output[prevIndex] = i - prevIndex;
            }
            s.push(i);
        }
        return output;
    }
};
