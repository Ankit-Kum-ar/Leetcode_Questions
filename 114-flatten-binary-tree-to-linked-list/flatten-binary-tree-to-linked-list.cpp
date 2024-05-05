/*
    Approach - 1 :- Make a vector that stores preorder traversal of
    Tree. Then make all node left is null and right should linked
    so that it formed a linked list.
*/
class Solution {
public:
    // Preorder Traversal that store in vector 'v'.
    void preorderTraversal (TreeNode* root, vector<TreeNode*>& v) {
        if(root == NULL) return;
        v.push_back(root);
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        vector<TreeNode*> v;
        preorderTraversal(root, v);

        // Now change the linking of Tree using vector 'v'.
        for(int i=0;i<v.size()-1;i++) {
            root->right = v[i+1];
            root->left = NULL;
            root = root->right;
        }
    }
};