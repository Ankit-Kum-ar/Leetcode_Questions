class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int> nums, vector<int> ans, int n, int idx){
        if(idx == n){
            result.push_back(ans);
            return;
        }
        helper(nums, ans, n, idx+1);
        ans.push_back(nums[idx]);
        helper(nums, ans, n, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        helper(nums, ans, n, 0);
        return result;
    }
};