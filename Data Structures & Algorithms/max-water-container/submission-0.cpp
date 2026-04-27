class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxWaterArea = 0;
        int left = 0, right = heights.size() - 1;

        while (left < right) {
            int width = right - left;
            if (heights[left] >= heights[right]) {
                maxWaterArea = max(maxWaterArea, width * heights[right]);
                right--;
            } else {
                maxWaterArea = max(maxWaterArea, width * heights[left]);
                left++;
            }
        }

        return maxWaterArea;
    }
};
