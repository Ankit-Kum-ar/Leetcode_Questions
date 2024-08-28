class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int i = 0, j = nums.size()-1;

        while(i<=j) {
            if(nums[i] == target && nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
            else if(nums[i] != target) {
                i++;
            }
            else if(nums[j] != target) {
                j--;
            }
        }
        return ans;
    }
};