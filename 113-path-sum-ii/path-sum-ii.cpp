/*
    Approach :- We have targetSum so we need to find the path
    from root to leaf node so that there sum would equal to 
    targetSum. For that, we traverse each branch of tree and
    traverse from each node of tree. During traversing we 
    subtract our targetSum from root->val then if we get correct
    path then at end targetSum == root->val(current) so it must
    be correct path and we will push it in 2-D vector as such.
    The 2-D vector is call by reference and 1-D vector is call
    by value. 
*/

class Solution {
public:
    void helper (TreeNode* root, int targetSum, vector<int> v, vector<vector<int>>& ans) {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL) {
            if(targetSum == root->val) {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        targetSum -= root->val;
        v.push_back(root->val);
        helper(root->left, targetSum, v, ans);
        helper(root->right, targetSum, v, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, targetSum, v, ans);
        return ans;
    }
};