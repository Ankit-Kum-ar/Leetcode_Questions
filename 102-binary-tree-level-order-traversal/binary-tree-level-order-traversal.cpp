/*
    Approach :- The approach is that firslty find the number of
    levels in the tree. Now we have to traverse each level of 
    tree. Therefore we apply in/pre/post order with a certain
    condition of the nth level that show in code. Such that for
    each level we apply a condition of curr == level. After 
    encounter the desired level we push all elements in the
    vector. Then this vector push in vector of vector.
*/

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