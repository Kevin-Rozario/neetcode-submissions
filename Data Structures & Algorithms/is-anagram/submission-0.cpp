class Solution {
   public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0;

        while (s[i] != '\0' && t[i] != '\0') {
            if (s[i] != t[i]) return false;
            i++;
        }

        if (s[i] == '\0' && t[i] == '\0') return true;

        return false;
    }
};
