/**
    Approach :-
    1. To find the sum of all left leaf. Maintain a prev TreeNode.
    2. For checking left leaf it should be NULL in left and right.
    3. The above 2. condition also true for right leaf.
    4. To differentitate the left and right, we maintain the prev
    TreeNode. 
    5. The prev node check that current node is connected to a left
    linked of a node.
    6. When it satisfy the condition add that value and return tha 
    ans.
 */
class Solution {
public:
    void preorder (TreeNode* root, TreeNode* prev, int& sum) {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL) {
            if(prev->left == root) sum += root->val;
        }
        prev = root;
        preorder(root->left, prev, sum);
        preorder(root->right, prev, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* prev = root;
        int sum = 0;
        preorder(root, prev, sum);
        return sum;
    }
};