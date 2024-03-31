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

    // Approach :- Firstly, I think that swap the values of
    // left and right node values. But this way of thinking
    // is wrong. So later, I think that what happened when
    // I changed the linking of right and left chlid of node.
    // So simply swap the linking of right and left child
    // of the current node. The swapping of address nodes
    // apply at each node of the tree.

    void helper(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};