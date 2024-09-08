class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge cases for size = 0 or 1.
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            // Check if the mid is greater than left and right element...
            if(nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]) return mid;

            // Also check if mid is smaller than mid+1 then left most array portion haven't the peak element...
            else if(nums[mid] < nums[mid+1]) lo = mid+1;

            // Same for the righ most array...
            else hi = mid - 1;
        }
        return -1;
    }
};