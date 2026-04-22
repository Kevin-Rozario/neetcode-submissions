class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.resize(nums.size() * 2);

        int size = nums.size();
        int mid = size / 2;

        for (int i = mid; i < size; i++) {
            nums[i] = nums[i - mid];
        }

        return nums;
    }
};