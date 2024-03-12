class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n < 3){
            return max(nums[0], nums[1]);
        }
        sort(nums.begin(),nums.end());
        int count = 1;
        for(int i=0;i<n-1;i++){
            if(nums[i] != nums[i+1]){
                count++;
            }
        }
        if(count<=2){
            int mx = INT_MIN;
            for(int i=0;i<n;i++){
                 mx = max(mx, nums[i]);
            }
            return mx;
        }
        int mx = INT_MIN, secondMx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx, nums[i]);
        }   
        for(int i=0;i<n;i++){
            if(nums[i]>secondMx and nums[i] != mx){
                secondMx = nums[i];
            }
        }
        int thridMx = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>thridMx and nums[i] != mx and nums[i] != secondMx){
                thridMx = nums[i];
            }
        }
        return thridMx;

    }
};