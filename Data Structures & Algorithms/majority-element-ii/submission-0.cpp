class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        long long cand1 = LLONG_MIN, cand2 = LLONG_MIN;
        int count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        int n = nums.size();
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == cand1)
                count1++;
            else if (num == cand2)
                count2++;
        }

        if (count1 > n / 3) result.push_back((int)cand1);
        if (count2 > n / 3) result.push_back((int)cand2);

        return result;
    }
};
