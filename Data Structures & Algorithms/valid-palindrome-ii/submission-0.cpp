class Solution {
   private:
    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

   public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return isPal(s, left + 1, right) || isPal(s, left, right - 1);
            }
            left++, right--;
        }
        return true;
    }
};