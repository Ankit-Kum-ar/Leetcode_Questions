class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long mx=0, i=0, ans=0;
        while(mx<n){
            if(i<nums.size() && nums[i]<=mx+1){
                mx+=nums[i];
                i++;
            }
            else{
                ans++;
                mx+=mx+1;
            }
        }
        return ans;
    }
};