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

 /*
    Approach :- Apply recusrion to traverse in the tree then
    if any root has encounter whose left and right child
    are NULL then it should be a leaf node therefore return
    at that point. 
    if root become NULL then return without pushing string
    in vector string.

    Remeber don't push those nodes whose only one child is
    NULL bcz they are not the leaf node.
 */
class Solution {
public:
    void helper (TreeNode* root, vector<string>& s, string str) {
        if(root == NULL) return;
        string a = to_string(root->val);
        if(root->left == NULL and root->right == NULL) {
            str += a;
            // str += "->";
            s.push_back(str);
            return;
        }
        helper(root->left,s,str+a+"->");
        helper(root->right,s,str+a+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, ans, "");
        return ans;
    }
};