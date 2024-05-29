/*
    Approach :- This problem is base on the prefix sum concept.
        num[] = {1,2,3,4}
        prefixSum num[] = {1, 1+2=3, 3+3=6, 6+4=10 }
                        = {1, ,3, 6, 10}.

    T.C = O(n), S.C = O(1).
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
        return nums;
    }
};