/**
    Approach :- The approach is simple that we have to find the sum
    of level of elements in BT. Uske liye BFS by recursion method se
    easily saare levels ka sum ek vector mein store kr liya. Then
    jis required kth sum ko return krna hai kr diya....
 */
class Solution {
public:
    int level (TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void helper (TreeNode* root, vector<long long>& v, int levelTree) {
        if(root == NULL) return;
        v[levelTree] += root->val;
        helper(root->left, v, levelTree + 1);
        helper(root->right, v, levelTree + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        int n = level(root);
        if(k > n) return -1;
        int levelTree = 0;
        vector<long long> v(n, 0);
        helper(root, v, levelTree);
        sort(v.begin(), v.end());
        return v[v.size() - k];
    }
};