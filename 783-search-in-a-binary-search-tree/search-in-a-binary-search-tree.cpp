/*
    Algorithm :- Search in BST as if node come at NULL then return
    NULL. If the root->val == val then return root, if current root
    val is greater than val then pass to left subtree and same for 
    goes to the lesser.
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        if(root->val > val) return searchBST (root->left, val);
        return searchBST (root->right, val);
    }
};