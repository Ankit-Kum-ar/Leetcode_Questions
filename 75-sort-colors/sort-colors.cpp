class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid = 0;
        while(mid <= hi) {
            if(nums[mid] == 2) {
                swap(nums[mid], nums[hi]);
                hi--;
            }
            else if(nums[mid] == 0) {
                swap(nums[mid], nums[lo]);
                mid++;
                lo++;
            }
            else mid++;
        }
    }
};