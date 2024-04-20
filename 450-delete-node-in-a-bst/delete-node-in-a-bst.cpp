/*
    Algorithm :-
        Case - 1 : zero child
            Direct return NULL.
        Case - 2 : one child
            If there is one child of deleting node then simply 
            replace the delete node to child node or you can say
            return the child node.
        Case - 3 : two child
            Suppose we delete 5 from eg - 1 then we have to replace
            that node value to some other node value that don't
            affect the branching of BST. Therefore we have to find 
            inorder predecessor or successor (actually they applicable only
            those nodes who having both children). Now replace the
            value of delete node to the predecessor node value.
            Now at last we have to remove the predecessor node from
            tree for that apply deleteNode function. The recursion
            work for that aim here we pass the root node and
            pred value as key. 
*/

class Solution {
public:
    TreeNode* iop(TreeNode* root) { // Inorder Predecessor...
        TreeNode* pred = root->left;
        while(pred->right != NULL) {
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) {
            // If delete Node has zero chid then ...
            if(root->left == NULL and root->right == NULL) return NULL;

            // If delete Node has one child then...
            if(root->left == NULL || root->right == NULL) {
                if(root->left != NULL) return root->left;
                else return root->right;
            }

            // IF delete Node has two childs then ...
            if(root->left != NULL and root->right != NULL) {
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else root->left = deleteNode(root->left, key);
        return root;
    }
};