/*
    Approach :- If p val and q val mein ek choti hai and ek badi hai
    current root val se then root hi ans hai. If both p and q vals 
    are smaller than root val then it should lie in left subtree and
    same as for right subtree. 
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p->val < root->val and q->val > root->val) return root;
        if(p->val > root->val and q->val < root->val) return root;
        if(p->val == root->val || q->val == root->val) return root;
        if(p->val < root->val and q->val < root->val) return lowestCommonAncestor(root->left, p, q);
         return lowestCommonAncestor(root->right, p, q);
    }
};