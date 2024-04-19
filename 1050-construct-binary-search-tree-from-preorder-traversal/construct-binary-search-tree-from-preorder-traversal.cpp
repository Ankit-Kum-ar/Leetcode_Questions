/**
    Approach :- The approach is we have preorder of a tree then 
    I know that BST is sorted in inorder traversal so fir 
    ek vector liya 'v' then usko sorted of given vector kr diya
    Now preorder a pehla elment hamesha root hota hai so uss root
    ko sorted ke andar search kiya now ek idx aa jaega uss idx se
    leftCount mtlb left length of vector and rightCount nikal lo 
    of "v" ka. Ab preorder hota hai => root left right Toh root ke
    baad left hoga to 'prelo+1' se le kr 'prelo+1+leftCount' tak 
    humra left subtree hoga. 
    Similarly goes for the right subtree as write in code. 
 */
class Solution {
public:
    TreeNode* build (vector<int>& preorder, int prelo, int prehi, vector<int>& v, int lo, int hi) {
        if(prelo > prehi || lo > hi) return NULL;
        TreeNode* root = new TreeNode(preorder[prelo]);
        int idxvRoot = lo;
        while(idxvRoot < hi) {
            if(v[idxvRoot] == root->val) break;
            idxvRoot++;
        }
        // int i = 1; int j = prehi;
        // while(i < prehi){
        //     if(preorder[i] == v[idxvRoot - 1]) break;
        //     i++;
        // }
        // while(j > prelo) {
        //     if(preorder[j] == v[idxvRoot + 1]) break;
        //     j--;
        // }
        int leftCount = (idxvRoot - 1) - lo;
        int rightCount = hi - (idxvRoot + 1);
        root->left = build(preorder, prelo + 1, prelo + 1 + leftCount, v, lo, idxvRoot - 1);
        root->right = build(preorder, prelo + 1 + leftCount + 1, prelo + 1 + leftCount + 1 + rightCount, v, idxvRoot + 1, hi);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            v[i] = preorder[i];
        }
        sort(v.begin(), v.end());
        TreeNode* root = build(preorder, 0, n-1, v, 0, n-1);
        return root;
    }
};

/*
    Approach :- ek dusri approach bhi hai ki preorder ke elements
    pr for loop chla kr insert method call krte rho toh BST ban jaaega
    or usme extra vector lena ni pdega.
*/