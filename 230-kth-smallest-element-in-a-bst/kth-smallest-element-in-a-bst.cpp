/*
    Approach :- Inorder traversal in BST leads to sorted array.
    Toh es property se travel in BST then k ko decrement krte
    rhnge. When k become 0 so that root->val is our desired value.
*/

class Solution {
public:
    void inorder (TreeNode* root, int& k, int& n) {
        if(root == NULL) return;
        inorder(root->left, k, n);
        k--;
        if(k == 0) n = root->val;
        inorder(root->right, k, n);
    }
    int kthSmallest(TreeNode* root, int k) {
        int n = INT_MAX;
        inorder(root, k, n);
        return n;
    }
};