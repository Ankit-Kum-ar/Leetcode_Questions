/*
    Approach :- The approach is simple that check some certain
    conditions such as write in code that are
    ki node ki value give value se jada hai toh kya kre and vice
    versa and agar left and right child bhi null hai toh add kab
    kre. These things should taken in account to build the
    algorithm.
*/

class Solution {
public:
    void helper(TreeNode* root, int val) {
        if(root == NULL) return;
        if(val < root->val and root->left == NULL) {
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
            return;
        }
        else if(val > root->val and root->right == NULL) {
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
            return;
        }
        if(val > root->val) helper(root->right, val);
        if(val < root->val) helper(root->left, val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            root = temp;
            return root;
        }
        helper(root, val);
        return root;
    }
};