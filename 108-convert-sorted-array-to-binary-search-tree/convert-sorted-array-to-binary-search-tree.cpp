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
    TreeNode* helper(int lo, int hi, vector<int>& arr) {
        if(lo > hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(lo, mid-1, arr);
        root->right = helper(mid+1, hi, arr);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n-1, nums);
    }
};