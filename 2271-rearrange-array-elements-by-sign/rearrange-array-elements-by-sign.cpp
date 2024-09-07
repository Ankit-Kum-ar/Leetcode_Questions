class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int idxOdd = 1;
        int idxEven = 0;
        int n = nums.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++) {
            if(nums[i] > 0) {
                ans[idxEven] = nums[i];
                idxEven += 2;
            }
            else if (nums[i] < 0) {
                ans[idxOdd] = nums[i];
                idxOdd += 2;
            }
        }

        return ans;
    }
};