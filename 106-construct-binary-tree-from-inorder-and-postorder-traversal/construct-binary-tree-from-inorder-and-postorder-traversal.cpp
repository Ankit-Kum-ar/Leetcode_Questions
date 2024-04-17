class Solution {
public:
    TreeNode* build(vector<int> post, int postlo, int posthi, vector<int> in, int inlo, int inhi) {
        if(postlo > posthi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        int i = inlo;
        while(i<inhi) {
            if(in[i] == root->val) break;
            i++;
        }
        int leftCounter = i - inlo;
        int rightCounter = inhi - i;
        root->right = build(post, posthi - rightCounter, posthi - 1, in, i+1, inhi);
        root->left = build(post, postlo, posthi - rightCounter - 1, in, inlo, i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(postorder, 0, n-1, inorder, 0, n-1);
    }
};