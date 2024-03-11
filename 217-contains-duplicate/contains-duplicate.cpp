class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int countNumbers = 1;
        sort(nums.begin(), nums.end());
        int x = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] != x){
                countNumbers++;
                x = nums[i];
            }
        }
        if(countNumbers < nums.size()) return true;
        return false;
    }
};