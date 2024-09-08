class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int ans = INT_MAX;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;

            // 1. Check if the left Array is sorted then take the 
            // smallest element from that leftSorted Array which 
            // is at lo.
            if(nums[lo] <= nums[mid]) {
                ans = min(ans, nums[lo]);
                lo = mid + 1;
            }

            // 2. Now check if the left is not sorted then right
            // would be sorted and the smallest element should be
            // at mid.
            else if(nums[mid] <= nums[hi]) {
                ans = min(ans, nums[mid]);
                hi = mid - 1;
            }
        }

        return ans;
    }
};