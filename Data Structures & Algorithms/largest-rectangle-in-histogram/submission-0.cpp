class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int n = heights.size(), maxArea = 0, startIndex = 0;

        for (int i = 0; i < n; i++) {
            startIndex = i;
            if (s.empty()) {
                s.push({i, heights[i]});
            }

            while (!s.empty() && s.top().second > heights[i]) {
                auto [index, height] = s.top();
                s.pop();

                maxArea = max(maxArea, height * (i - index));
                startIndex = index;
            }

            s.push({startIndex, heights[i]});
        }

        while (!s.empty()) {
            auto [index, height] = s.top();
            maxArea = max(maxArea, height * (n - index));
            s.pop();
        }

        return maxArea;
    }
};
