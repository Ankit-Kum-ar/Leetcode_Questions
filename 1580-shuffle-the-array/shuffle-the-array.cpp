class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i = 0, j = n;
        int cnt = 0;
        while(j < nums.size()) {
            if(cnt % 2 == 0) {
                ans.push_back(nums[i]);
                i++;
            }
            else {
                ans.push_back(nums[j]);
                j++;
            }
            cnt++;
        }
        return ans;
    }
};