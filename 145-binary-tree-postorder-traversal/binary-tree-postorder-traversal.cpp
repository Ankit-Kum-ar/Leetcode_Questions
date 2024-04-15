/*
    Approach :- Here we apply another approach. The approach is
    similar to preorder approach of implementing the stack but
    here we apply the pushing statement as left first then right
    and then reverse it => The outcome is postorder Traversal.
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
            if(temp->left != NULL) stk.push(temp->left);
            if(temp->right != NULL) stk.push(temp->right);
        }
        reverse(ans.begin(), ans.end());
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};