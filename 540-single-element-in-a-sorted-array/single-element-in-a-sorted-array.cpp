class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi) {
            if(nums[lo] != nums[lo+1]) {
                return nums[lo];
            }
            else lo = lo + 2;

            if(nums[hi] != nums[hi - 1]) {
                return nums[hi];
            }
            else hi = hi - 2;
        }

        return -1;

    }
};