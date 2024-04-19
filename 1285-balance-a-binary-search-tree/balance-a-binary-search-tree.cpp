/**
    Approach :- 
        1. Check the give tree is balanced BST.
        2. If yes then return that root.
        3. Else make a vector to store sorted order using inorder
        traversal.
        4. Build function to build a balanced BST using a sorted
        vector.
        5. Return root.
        6. There would some case where 2. statement would fail due
        to values of nodes. Therefore remove 2nd step....
 */
class Solution {
public:
    // int level (TreeNode* root) { // For level of subtrees
    //     if(root == NULL) return 0;
    //     return (1 + max(level(root->left), level(root->right)));
    // }
    void inorder (TreeNode* root, vector<int>& v) { // Store the sorted order in vector
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    TreeNode* build (TreeNode* root, vector<int>& v, int lo, int hi) { // Form a balanced BST using a sorted vector...
        if(lo > hi) return NULL;
        int mid = lo + (hi - lo)/2;
        root = new TreeNode(v[mid]);
        root->left = build(root, v, lo, mid - 1);
        root->right = build(root, v, mid + 1, hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // int dl = level(root->left);
        // int dr = level(root->right);
        // if(abs(dl - dr) <= 1) return root;
        vector<int> v;
        inorder(root, v);
        int n = v.size();
        return build(root, v, 0, n-1);
    }
};