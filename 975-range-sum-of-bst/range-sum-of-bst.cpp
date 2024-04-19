/**
    Approach :- Approach is simple that apply inorder and check if
    root->val is b/w low and high values so add it.
 */
class Solution {
public:
    void inorder(TreeNode* root, int low, int high, int& sum) {
        if(root == NULL) return;
        inorder(root->left, low, high, sum);
        if(root->val >= low and root->val <= high) {
            sum += root->val;
        }
        inorder(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, low, high, sum);
        return sum;
    }
};