class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1;
        int mx = 1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>nums[i-1]){
                cnt++;
                
            }
            else {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx,cnt);
        return mx;
    }
};