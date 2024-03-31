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
    // First Approach :- Adding the levels of leftSubtree
    // and rightSubtree which gives a result of maximum 
    // diameter. But this appraoch is wrong for some cases.
    // Because in problem it is mentioned that it is not
    // necessary max path always pass through root node.

    // Second Approach :- Now traverse each node of 
    // leftSubtree and rightSubtree. For each node find
    // level of left and right subtree and that root has 
    // maximum level is the diameter of the BT. This appraoch
    // is ensure the problem of root node.


    int mx = INT_MIN;
    int level(TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void display(TreeNode* root) {
        if(root == NULL) return;
        mx = max(mx, (level(root->left) + level(root->right)));
        display(root->left);
        display(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        display(root);
        return mx;
    }
};