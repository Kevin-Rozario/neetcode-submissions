class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int counter = 1, value = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (counter == 0 && nums[i] != value) {
                value = nums[i];
                counter = 1;
            } else if (nums[i] != value) {
                counter--;
            } else {
                counter++;
            }
        }
        return value;
    }
};