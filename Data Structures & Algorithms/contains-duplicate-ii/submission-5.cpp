class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            // If the element is already in the set, we found a duplicate within distance k
            if (window.count(nums[i])) return true;

            window.insert(nums[i]);

            // Maintain window size: remove the element that is now more than k steps away
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};
