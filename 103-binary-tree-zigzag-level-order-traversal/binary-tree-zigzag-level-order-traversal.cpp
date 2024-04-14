/*
    Approach :- The Approach of this que is similar to Leetcode
    que - 102. Here we just simply apply to different direction 
    according to even and odd type of value of 'i'.
*/

class Solution {
public:
    int level(TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left) , level(root->right)));
    }
    void helperLeft(TreeNode* root, vector<int>& v, int level, int curr) {
        if(root == NULL){
            return;
        }
        if(curr == level) {
            v.push_back(root->val);
            return;
        }
        helperLeft(root->left, v, level, curr+1);
        helperLeft(root->right, v, level, curr+1);

    }
    void helperRight(TreeNode* root, vector<int>& v, int level, int curr) {
        if(root == NULL){
            return;
        }
        if(curr == level) {
            v.push_back(root->val);
            return;
        }
        helperRight(root->right, v, level, curr+1);
        helperRight(root->left, v, level, curr+1);

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = level(root);
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++) {
            vector<int> v;
            if(i%2 == 0) helperRight(root, v, i, 1) ;
            else helperLeft(root, v, i, 1) ;
            ans.push_back(v);
        }
        return ans;
    }
};