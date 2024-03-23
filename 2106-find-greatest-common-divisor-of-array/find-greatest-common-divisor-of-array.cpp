class Solution {
public:
    int hcf(int a, int b) {
        if(b%a == 0) return a;
        else {
            return hcf(b%a, a);
        }
    }
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            mn = min(nums[i],mn);
            mx = max(nums[i],mx);
        }
        return hcf(mn, mx);

        
    }
};