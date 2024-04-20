/**
    Approach :- 
        1. Find all level sum using BFS by recursion. 
        2. All level sum are stored in a vector "v".
        3. After storing values find out the maximum sum from vector.
        4. When maximum element get then return corresponding 
        (index + 1).
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
    int maxLevelSum(TreeNode* root) {
        int n = level(root);
        vector<long long> v(n ,0);
        helper(root, v, 0);
        long long ans = INT_MIN;
        int idx = -1;
        for(int i=0;i<n;i++) {
            if(ans < v[i]) {
                ans = v[i];
                idx = i;
            }
        }
        return (idx + 1);
    }
};