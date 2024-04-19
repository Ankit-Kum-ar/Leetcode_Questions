/**
    Approach :- Apply inorder to store ascending orders of vectors
    after that join both vectors and sort that. Return vector ....
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        inorder(root1, v1);
        inorder(root2, v2);

        for(int i=0;i<v2.size();i++) v1.push_back(v2[i]);
        sort(v1.begin(), v1.end());
        return v1;
    }
};