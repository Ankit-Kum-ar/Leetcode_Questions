class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. Pivot element index...
        int idx = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }

        // 2. Check if pivot index not exist...
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 3. If pivot idx exist then... 
        reverse(nums.begin() + idx + 1, nums.end());

        // 4. e.g = [1,4,3,2] => [1,2,3,4] => [2,1,3,4]
        // Therefore check if any element greater than pivot. So
        // Swap them...
        int j = -1;
        for(int i=idx+1;i<n;i++) {
            if(nums[idx] < nums[i]){
                swap(nums[idx], nums[i]);
                break;
            }
        }
        return;
    }
};