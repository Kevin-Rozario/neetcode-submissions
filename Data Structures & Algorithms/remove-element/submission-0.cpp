class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = 0;

        while (i < nums.size()) {
            if (nums[i] != val) {
                nums[k++] = nums[i++];
            } else {
                i++;
            }
        }

        nums.resize(nums.size() - (nums.size() - k));

        return k;
    }
};