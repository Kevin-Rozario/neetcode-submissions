class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            auto it = numMap.find(diff);
            if (it != numMap.end()) {
                result.push_back(it->second);
                result.push_back(i);
            }
            numMap[nums[i]] = i;
        }

        return result;
    }
};
