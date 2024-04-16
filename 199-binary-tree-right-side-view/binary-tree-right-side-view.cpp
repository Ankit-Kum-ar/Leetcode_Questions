/*
    Approach :- In this problem, we have to store all the right
    node values in each level. So for that we make a vector of 
    size of level of tree. After that apply algorithm of preor-
    der which travel as left to right. Also make a level variable
    to check the level of traverse. Then write
    ans[level] = root->val; that makes multiple assignment of 
    value at last, most right node will assign to it.
*/

/*
    Another Approach :- By the level printing of nthlevel algo
    but we have to assign all values of current level to 
    curr index of vector, At last right most value assign to
    current level of vector.
*/

class Solution {
public:
    int level (TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void preorder (TreeNode* root, vector<int>& ans, int level) {
        if(root == NULL) return;
        ans[level] = root->val;
        preorder(root->left, ans, level+1);
        preorder(root->right, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(level(root), 0);
        preorder(root, ans, 0);
        return ans;
    }
};