/**
    Approach :- inorder of BST => sorted values of tree. So hume
    ek BST banana hai jisme right child ho bass toh hume pta hai
    ki right mein root->val se badi value aaegi toh first element 
    should be smallest so that all elements come in right subtree.
 */
class Solution {
public:
    void inorder (TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);

        // Create new BST which having only right subtree.
        TreeNode* Root = new TreeNode(v[0]);
        TreeNode* temp = Root;
        for(int i=1;i<v.size();i++) {
            temp->right = new TreeNode(v[i]);
            temp = temp->right;
        }
        return Root;

    }
};