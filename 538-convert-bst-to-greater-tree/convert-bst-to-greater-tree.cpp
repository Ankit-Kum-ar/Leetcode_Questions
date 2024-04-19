/**
    Appraoch :- Similar to LC - 1038
 */
class Solution {
public:
    void helper(TreeNode* root, int& sum) { //  Reverse Inorder
        if(root == NULL) return;
        helper(root->right, sum);
        root->val += sum;
        sum = root->val;
        helper(root->left, sum);

    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
};