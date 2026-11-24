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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* ptr = root;

        while (ptr != nullptr || !s.empty()) {
            while (ptr != nullptr) {
                s.push(ptr);
                ptr = ptr->left;
            }

            ptr = s.top();
            result.push_back(ptr->val);
            s.pop();
            ptr = ptr->right;
        }

        return result;
    }
};