class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;

            while (!st.empty() && ast < 0 && st.back() > 0) {
                if (abs(ast) > abs(st.back())) {
                    st.pop_back();
                    continue;
                } else if (abs(ast) == abs(st.back())) {
                    st.pop_back();
                    destroyed = true;
                } else {
                    destroyed = true;
                }
                break;
            }

            if (!destroyed) {
                st.push_back(ast);
            }
        }
        return st;
    }
};
