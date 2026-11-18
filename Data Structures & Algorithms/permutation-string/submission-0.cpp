class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        unordered_map<char, int> count1;
        unordered_map<char, int> count2;

        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i]]++;
            count2[s2[i]]++;
        }

        if (count1 == count2) {
            return true;
        }

        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++) {
            count2[s2[right]]++;

            char leftChar = s2[left];
            count2[leftChar]--;
            if (count2[leftChar] == 0) {
                count2.erase(leftChar);
            }
            left++;

            if (count1 == count2) {
                return true;
            }
        }
        return false;
    }
};
