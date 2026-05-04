class Solution {
   private:
    pair<int, int> popTwo(stack<int>& s) {
        int second = s.top();
        s.pop();
        int first = s.top();
        s.pop();

        return {first, second};
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        pair<int, int> valuePair;

        for (string& token : tokens) {
            if (token == "+") {
                valuePair = popTwo(s);
                s.push(valuePair.first + valuePair.second);
            } else if (token == "-") {
                valuePair = popTwo(s);
                s.push(valuePair.first - valuePair.second);
            } else if (token == "*") {
                valuePair = popTwo(s);
                s.push(valuePair.first * valuePair.second);
            } else if (token == "/") {
                valuePair = popTwo(s);
                s.push(valuePair.first / valuePair.second);
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};
