/*
    Approach - 1 :- Make a vector that stores preorder traversal of
    Tree. Then make all node left is null and right should linked
    so that it formed a linked list.

    Approach - 2 :- It is a recursive appraoch in which we flatten
    the left subtree as well as right subtree. After these subtrees
    are flatten then join them in right branch of root.
    The flatten operation in handled by the recursion...
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = NULL;
        root->right = NULL;
        flatten(l);
        flatten(r);
        root->right = l;
        TreeNode* temp = root;
        while(temp->right != NULL) temp = temp->right;
        temp->right = r;
    }
};