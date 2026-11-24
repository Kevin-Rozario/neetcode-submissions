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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* ptr = root;

        s.push(ptr);
        while (!s.empty()) {
            result.push_back(ptr->val);
            if (ptr->right != nullptr) s.push(ptr->right);
            if (ptr->left != nullptr) s.push(ptr->left);
            ptr = s.top();
            s.pop();
        }

        return result;
    }
};