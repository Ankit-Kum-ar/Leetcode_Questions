class Solution {
public:
    void traversal(TreeNode* root, TreeNode* p, TreeNode* q, bool& f1, bool& f2) {
        if(root == NULL) return;
        if(p->val == root->val) f1 = true;
        if(q->val == root->val) f2 = true;
        traversal(root->left, p, q, f1, f2);
        traversal(root->right, p, q, f1, f2);
    }
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if(root == NULL) return;
        bool f1 = false, f2 = false;
        traversal(root, p, q, f1, f2);
        if(f1 and f2) ans = root;
        helper(root->left, p, q, ans);
        helper(root->right, p, q, ans);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        helper(root, p, q, ans);
        return ans;
    }
};