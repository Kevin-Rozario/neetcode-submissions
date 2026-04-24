class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        int currentSum = 0;
        int subArrayCount = 0;

        for (int num : nums) {
            currentSum += num;
            int diff = currentSum - k;

            if (prefixSum.find(diff) != prefixSum.end()) {
                subArrayCount += prefixSum[diff];
            }

            prefixSum[currentSum]++;
        }

        return subArrayCount;
    }
};
