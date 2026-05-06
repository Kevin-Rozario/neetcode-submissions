class Solution {
   public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char& token : s) {
            if (isdigit(token)) {
                k = k * 10 + (token - '0');
            } else if (token == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (token == ']') {
                int times = countStack.top();
                countStack.pop();
                string prev = stringStack.top();
                stringStack.pop();

                string repeated = "";
                while (times--) repeated += currentString;

                currentString = prev + repeated;
            } else {
                currentString += token;
            }
        }

        return currentString;
    }
};