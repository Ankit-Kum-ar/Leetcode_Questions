/*  Approach :- Find the levels for each node of right and left.
    Then check if difference of levels is not greater than 1.
    If it is greater than 1 then return false. Now traverse in 
    whole tree and check each right and left levels difference.
*/

class Solution {
public:
    int level (TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void helper(TreeNode* root, bool& flag) {
        if(root == NULL) {
            // flag = true;
            return;
        }
        int l = level(root->left);
        int r = level(root->right);
        if(abs(l-r) > 1) {
            flag = false;
            return;
        }
        helper(root->left, flag);
        helper(root->right, flag);

    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        helper(root, flag);
        return flag;
    }
};