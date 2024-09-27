class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool flag = true;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                flag = false;
                break;
            }
        }

        if(flag == true) return;

        int j = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};