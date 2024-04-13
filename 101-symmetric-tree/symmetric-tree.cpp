/*
    Approach :- Firstly inverse the left subtree or right. 
    Now apply algorithm of two identical tree checker.
*/

class Solution {
public:
    void inverse(TreeNode*& root) {
        if(root == NULL) return;
        swap(root->left, root->right);
        inverse(root->left);
        inverse(root->right);
    }
    void helper(TreeNode* p, TreeNode* q, bool& flag) {
        if(p == NULL and q == NULL) return;
        if((p != NULL and q == NULL) || (p == NULL and q != NULL)) {
            flag = false;
            return;
        }
        if(p->val != q->val){
            flag = false;
            return;
        }
        

        helper(p->left, q->left, flag);
        helper(p->right, q->right, flag);
    }
    bool isSymmetric(TreeNode* root) {
        inverse(root->right);
        bool flag = true;
        helper(root->left, root->right, flag);
        return flag;
    }
};