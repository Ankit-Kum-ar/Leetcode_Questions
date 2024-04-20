/*
    Approach :-
    1. Find the number of level of whole BT.
    2. Apply BFS of recursive method.
    3. Maintain a count variable to track the current level of BFS.
    4. When count become deepest level then add the root->val.
    5. Return the added values of nodes.
*/

class Solution {
public:
    int level (TreeNode* root) {
        if(root == NULL) return 0;
        return (1 + max(level(root->left), level(root->right)));
    }
    void traverse (TreeNode* root, int count, int n, int& sum) {
        if(root == NULL) return;
        if(count == n) {
            sum += root->val;
        }
        traverse(root->left, count + 1, n, sum);
        traverse(root->right, count + 1, n, sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int n = level(root);
        int sum = 0;
        traverse(root, 1, n, sum);
        return sum;
    }
};