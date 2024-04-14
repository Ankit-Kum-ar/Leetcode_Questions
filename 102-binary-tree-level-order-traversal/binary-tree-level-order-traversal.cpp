class Solution {
public:
    int level(TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left) , level(root->right)));
    }
    void helper(TreeNode* root, vector<int>& v, int level, int curr) {
        if(root == NULL){
            return;
        }
        if(curr == level) {
            v.push_back(root->val);
            return;
        }
        helper(root->left, v, level, curr+1);
        helper(root->right, v, level, curr+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = level(root);
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++) {
            vector<int> v;
            helper(root, v, i, 1) ;
            ans.push_back(v);
        }
        return ans;
    }
};