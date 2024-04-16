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
    int level (TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void preorder (TreeNode* root, vector<int>& ans, int curr, int n) {
        if(root == NULL) return;
        if(curr == n) ans[0] = root->val;
        preorder(root->right, ans, curr+1, n);
        preorder(root->left, ans, curr+1, n);
    }
    int findBottomLeftValue(TreeNode* root) {
        int n = level(root);
        vector<int> ans(1, 0);
        preorder(root, ans, 1, n);
        return ans[0];
    }
};