// Approach is same as Path Sum - 1

class Solution {
public:
    void helper(TreeNode* root, int targetSum, bool& flag) {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL) {
            if(targetSum == root->val) {
                flag = true;
                return;
            }
        }
        targetSum -= root->val;
        helper(root->left, targetSum, flag);
        helper(root->right, targetSum, flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        helper(root, targetSum, flag);
        return flag;
    }
};