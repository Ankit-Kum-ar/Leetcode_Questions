/*
    Approach :- Here we apply another approach of Preorder 
    Traversal, therefore we implement the stack to traversal.
*/
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> stk;
        stk.push(root);
        while(stk.size() > 0) {
            TreeNode* temp = stk.top();
            stk.pop();
            ans.push_back(temp->val);
            if(temp->right != NULL) stk.push(temp->right);
            if(temp->left != NULL) stk.push(temp->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};