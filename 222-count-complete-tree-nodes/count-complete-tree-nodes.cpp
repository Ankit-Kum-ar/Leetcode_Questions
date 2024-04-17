class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        stack<TreeNode*> stk;
        int count = 0;
        stk.push(root);
        while(stk.size() > 0) {
            TreeNode* temp = stk.top();
            stk.pop();
            count++;
            if(temp->left != NULL) stk.push(temp->left);
            if(temp->right != NULL) stk.push(temp->right);
        }
        return count;
    }
};