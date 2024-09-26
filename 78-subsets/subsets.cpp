class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalAns, int n, int i) {
        if(i == n) {
            finalAns.push_back(ans);
            return;
        }

        helper(nums,ans,finalAns,n,i+1);
        ans.push_back(nums[i]);
        helper(nums,ans,finalAns,n,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        int n = nums.size();
        helper(nums, ans, finalAns, n, 0);
        return finalAns;
    }
};