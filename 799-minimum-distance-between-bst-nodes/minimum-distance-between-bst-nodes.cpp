/**
    Approach :- Sabse phle BST mein inorder se sorting array aata hai
    yeh sochna hota hai. Toh esme hum ek prev and current root ki
    values ka difference lenge and inorder right to left chalega
    jisse high difference phle assign hoga and lowest difference
    end mein assign hoga kuki right to left BST decreasing order mein
    sort hota hai. At the end we got our minimum difference.
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
    int minDiffInBST(TreeNode* root) {
        int d = INT_MAX;
        TreeNode* prev = NULL;
        reverseInorder(root, prev, d);
        return d;
    }
};