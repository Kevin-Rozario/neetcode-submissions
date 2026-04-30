class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0, maxFreq = 0, maxLength = 0;
        unordered_map<char, int> count;

        for (int right = 0; right < s.size(); right++) {
            // Add current character to map
            count[s[right]]++;

            // Track the most frequent character in the current window
            maxFreq = max(maxFreq, count[s[right]]);

            // If window size - maxFreq > k, the window is invalid
            while ((right - left + 1) - maxFreq > k) {
                count[s[left]]--;
                left++;
            }

            // Update the result
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
