/*
    Approach :- Firstly consider a stack that has initially 
    root value in it. Now iterate a loop in which if current-
    node is not empty then push current node to stack and 
    make current node to node ka left node.
    Else pop out the top node from stack and print or store 
    that after make current node to node ka right node.
*/
class Solution {
public:
    void traversal (TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(stk.size() > 0 || node != NULL) {
            if(node != NULL) {
                stk.push(node);
                node = node->left;
            }
            else {
                TreeNode* temp = stk.top();
                stk.pop();
                ans.push_back(temp->val);
                node = temp->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};