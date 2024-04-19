/**
    Appraoch :- Similar to LC - 1038
 */
class Solution {
public:
    void helper(TreeNode* root, TreeNode*& prev) {
        if(root == NULL) return;
        helper(root->right, prev);
        if (prev == NULL) {
            prev = root;
        }
        else {
            root->val += prev->val;
            prev = root;
        }
        helper(root->left, prev);

    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* prev = NULL;
        helper(root, prev);
        return root;
    }
};