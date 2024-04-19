/*
    Approach :- Here we know that BST inorder is sorted. Therefore, 
    we traverse from right to left and add prev node val to the
    current node val. At end the appropriate result is get.
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
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* prev = NULL;
        helper(root, prev);
        return root;
    }
};