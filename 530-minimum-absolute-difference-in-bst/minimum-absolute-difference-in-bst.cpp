/**
    Approach :- Similar to LC - 783
 */
class Solution {
public:
    void reverseInorder (TreeNode* root, TreeNode*& prev, int& d) {
        if(root == NULL) return;
        reverseInorder(root->right, prev, d);
        if(prev == NULL){
            prev = root;
        }
        else {
            int diff = abs(root->val - prev->val);
            d = min(diff, d);
            prev->val = root->val;
        }
        reverseInorder(root->left, prev, d);
    }
    int getMinimumDifference(TreeNode* root) {
        int d = INT_MAX;
        TreeNode* prev = NULL;
        reverseInorder(root, prev, d);
        return d;
    }
};