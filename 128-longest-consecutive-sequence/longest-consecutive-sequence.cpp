class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        // 1. Sort The nums...
        sort(nums.begin(), nums.end());

        // 2. Set the variables for lastSmaller, cnt, mx...
        int lastSmaller = INT_MIN;
        int cnt = 0; // Bcz lastSmaller is INT_MIN
        int mx = 1; // Min. longest sequence is 1.

        // 3. Iterate a loop...
        for(int i=0;i<nums.size();i++) {
            // a. First check if nums[i] - 1 == lastSmaller...
            // i.e. 2 - 1 == 1
            if(nums[i] - 1 == lastSmaller) {
                cnt++;
                lastSmaller = nums[i];
            }

            // b. If the nums[i] == lastSmaller then nothing do...
            // i.e. 2 == 2

            // c. If the nums[i] != lastSmaller then...
            // i.e. 100 != 2
            if(nums[i] != lastSmaller) {
                cnt = 1; // Bcz one element count.
                lastSmaller = nums[i];
            }

            mx = max(mx, cnt);
        }

        return mx;
    }
};