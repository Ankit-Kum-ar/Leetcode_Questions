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