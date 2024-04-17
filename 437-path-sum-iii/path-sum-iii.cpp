/*
    Approach :- The approach is same as per the Path Sum II
    Here we only pass each node to helper function by using
    any traversal algorithm.
*/
class Solution {
public:
    void helper (TreeNode* root, long long targetSum, int& sum) {
        if(root == NULL) return;
        if(targetSum == (long long)root->val) {
            sum += 1;
            // return;
        }
        targetSum -= root->val;
        helper(root->left, targetSum, sum);
        helper(root->right, targetSum, sum);
    }
    void traversal(TreeNode* root, long long targetSum, int& sum) {
        if(root == NULL) return;
        helper(root, targetSum, sum);
        traversal(root->left, targetSum, sum);
        traversal(root->right, targetSum, sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        traversal(root, (long long)targetSum, sum);
        return sum;
        
    }
};