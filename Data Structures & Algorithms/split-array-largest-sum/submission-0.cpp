class Solution {
   public:
    bool canSplit(vector<int> nums, int maxSum, int k) {
        int subArray = 0, currentSum = 0;
        for (int& num : nums) {
            if (currentSum + num > maxSum) {
                subArray++;
                currentSum = num;
                continue;
            }
            currentSum += num;
        }

        return subArray + 1 <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int minLargeSum = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, mid, k)) {
                minLargeSum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return minLargeSum;
    }
};