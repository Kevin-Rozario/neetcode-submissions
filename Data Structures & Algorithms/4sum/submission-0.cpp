class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> quadruplets;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip i duplicates

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip j duplicates

                int p = j + 1, q = n - 1;
                while (p < q) {
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[p], nums[q]});

                        while (p < q && nums[p] == nums[p + 1]) p++;
                        while (p < q && nums[q] == nums[q - 1]) q--;
                        p++;
                        q--;
                    } else if (sum < target)
                        p++;
                    else
                        q--;
                }
            }
        }
        return quadruplets;
    }
};
