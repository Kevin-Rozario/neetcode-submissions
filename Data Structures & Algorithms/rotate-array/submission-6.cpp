class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = k % n;
        if (k == 0) return;

        // Reverse the whole thing: [5, 4, 3, 2, 1]
        reverse(nums.begin(), nums.end());

        // Reverse first k: [4, 5, 3, 2, 1]
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the rest: [4, 5, 1, 2, 3]
        reverse(nums.begin() + k, nums.end());
    }
};