class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tempMap;
        vector<vector<string>> result;

        for (string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            tempMap[sortedStr].push_back(str);
        }

        for (auto& pair : tempMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};
