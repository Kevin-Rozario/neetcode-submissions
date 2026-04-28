class Solution {
   public:
    int trap(vector<int>& heights) {
        // Method 1 -  TC: O(N), SC: O(N) [Approach: Hashmap like]
        // int n = heights.size();
        // if (n <= 2) return 0;

        // vector<int> leftMax(n);
        // vector<int> rightMax(n);

        // leftMax[0] = heights[0];
        // for (int i = 1; i < n; i++) {
        //     leftMax[i] = max(leftMax[i - 1], heights[i]);
        // }

        // rightMax[n - 1] = heights[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //     rightMax[i] = max(rightMax[i + 1], heights[i]);
        // }

        // int totalWater = 0;
        // for (int i = 0; i < n; i++) {
        //     totalWater += min(leftMax[i], rightMax[i]) - heights[i];
        // }

        // return totalWater;

        // -------------------------------------------

        // Method 2 - TC: O(N) SC: O(1) [Approach: Two pointers]
        int n = heights.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (heights[left] < heights[right]) {
                if (heights[left] >= leftMax) {
                    leftMax = heights[left];
                } else {
                    totalWater += leftMax - heights[left];
                }
                left++;
            } else {
                if (heights[right] >= rightMax) {
                    rightMax = heights[right];
                } else {
                    totalWater += rightMax - heights[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};
