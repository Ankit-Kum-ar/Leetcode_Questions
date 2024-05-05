// Apply Morris Traversal Algorithm ....
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> v;
        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode* pred = curr->left;
                while(pred->right != NULL and pred->right != curr) {
                    pred = pred->right;
                }
                
                if(pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }
                if(pred->right == curr) {
                    pred->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else {
                v.push_back(curr->val);
                curr = curr->right;
            }
        }
        return v;
    }
};