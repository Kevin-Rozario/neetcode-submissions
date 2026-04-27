class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> indices;

        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                indices.push_back(i + 1);
                indices.push_back(j + 1);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return indices;
    }
};
