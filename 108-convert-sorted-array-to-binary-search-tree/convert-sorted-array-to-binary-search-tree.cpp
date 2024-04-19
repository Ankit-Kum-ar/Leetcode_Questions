/**
    Approach :- The middle element of array is root of BST. Bcz BST
    is sorted in inorder traversal. For the left and right apply
    recursion so that it form subtrees
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