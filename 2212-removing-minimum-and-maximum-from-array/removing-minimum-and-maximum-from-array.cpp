class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int upper,lower;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == mn || nums[i] == mx){
                 lower = i;
                 break;
            }
        }
        for(int i=nums.size() - 1;i>=0;i--){
            if(nums[i] == mn || nums[i] == mx){
                 upper = i;
                 break;
            }
        }
        int left = upper + 1;
        int right = nums.size() - lower;
        int total = (lower+1) + (nums.size()-upper);
        return min(total, min(left,right));

    }
};