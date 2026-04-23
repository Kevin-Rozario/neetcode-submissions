class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;

        for (int num : nums) {
            counter[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (auto& it : counter) {
            freq[it.second].push_back(it.first);
        }

        vector<int> result;
        for (int i = nums.size(); i >= 0; i--) {
            for (int num : freq[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};
