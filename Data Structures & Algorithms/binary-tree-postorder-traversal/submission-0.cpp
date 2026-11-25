/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* ptr = root;
        TreeNode* lastVisited = nullptr;

        while (ptr != nullptr || !s.empty()) {
            if (ptr != nullptr) {
                s.push(ptr);
                ptr = ptr->left;
            } else {
                TreeNode* peekNode = s.top();
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    ptr = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    s.pop();
                }
            }
        }

        return result;
    }
};
