/*
    Approach :- Toh esme unn nodes ko remove krna hai jo ki range ke
    bahar hai. So for that we use the property of BST that left wale
    root se less honge or right wale higher honge. Toh koi root->left
    value low se chotti hai toh root->left->left ki value bhi usse 
    chotti hi hogi toh uske liye root->left ko root->left->right
    bana denge. That same goes for the root->right. 
    Orr essa bhi ho skta hai ki root->left ki value high se jada
    ho toh uske liye root->left ko root->left->left bana denge 
    same goes for the root->right...
    For the root node we make a dummy node. Or dummy ke left mein
    apni main root ko attach kr denge then helper function ko call
    kr denge...
*/

class Solution {
public:
    void helper (TreeNode* root, int low, int high) {
        if(root == NULL) return;

        // Here we check for the left subtree...
        while(root->left != NULL){
            if(root->left->val < low) {
                root->left = root->left->right;
            }
            else if(root->left->val > high) {
                root->left = root->left->left;
            }
            else break;
        }
        
        // Here we check for the right subtree...
        while(root->right != NULL) {
            if(root->right->val > high) {
                root->right = root->right->left;
            }
            else if(root->right->val < low) {
                root->right = root->right->right;
            }
            else break;
        }
        helper (root->left, low, high);
        helper (root->right, low, high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        helper(dummy, low, high);
        return dummy->left;
    }
};