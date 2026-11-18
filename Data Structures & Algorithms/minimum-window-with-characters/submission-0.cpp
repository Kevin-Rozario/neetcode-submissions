class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> needMap;
        for (char c : t) {
            needMap[c]++;
        }

        int left = 0;
        int startIdx = 0;
        int haveCount = 0;
        int needCount = t.length();
        int minWindowSize = INT_MAX;

        for (int right = 0; right < s.length(); right++) {
            char rightChar = s[right];

            if (needMap.find(rightChar) != needMap.end()) {
                if (needMap[rightChar] > 0) {
                    haveCount++;
                }
                needMap[rightChar]--;
            }

            while (haveCount == needCount) {
                if (right - left + 1 < minWindowSize) {
                    minWindowSize = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                if (needMap.find(leftChar) != needMap.end()) {
                    needMap[leftChar]++;
                    if (needMap[leftChar] > 0) {
                        haveCount--;
                    }
                }
                left++;
            }
        }

        return minWindowSize == INT_MAX ? "" : s.substr(startIdx, minWindowSize);
    }
};
