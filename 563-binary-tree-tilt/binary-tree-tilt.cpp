/*
    Approach :- We have to find the sum of left subtree and right
    subtree of each node, therefore we used a helper function to
    visit every node and for every node we use traverse function
    that gives the sum of left and right subtree.
*/

class Solution {
public:
    int traverse(TreeNode* root) {
        if(root == NULL) return 0;
        return (root->val + traverse(root->left) + traverse(root->right));
    }
    void helper(TreeNode* root, int& finalSum) {
        if(root == NULL) return;
        int l = traverse(root->left);
        int r = traverse(root->right);
        finalSum += abs(l - r);
        helper(root->left, finalSum);
        helper(root->right, finalSum);
    }
    int findTilt(TreeNode* root) {
        int finalSum = 0;
        helper(root, finalSum);
        return finalSum;

    }
};