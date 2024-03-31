/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Approach :- Traverse each node of trees and check
    // the values of both trees node. If any of them is 
    // not equal then they are false. Some other case also 
    // include such that if a node is NULL but other tree
    // node has value then they are not identical and false.

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) return true;
        if(p != NULL and q == NULL) return false;
        if(p == NULL and q != NULL) return false;
        if(p->val != q->val) return false;

        bool left =  isSameTree(p->left, q->left);
        if(left == false) return false;

        bool right = isSameTree(p->right, q->right);
        if(right == false) return false;

        return true;

    }
};