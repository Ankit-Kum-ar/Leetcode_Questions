class Solution {
public:
    int rev (int x) {
        int temp = 0;
        while(x != 0) {
            int rem = x%10;
            temp = temp * 10 + rem;
            x = x/10;
        }
        return temp;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++) {
            s.insert(nums[i]);
            if(nums[i] > 9) {
                s.insert(rev(nums[i]));
            }
        }
        return s.size();
    }
};