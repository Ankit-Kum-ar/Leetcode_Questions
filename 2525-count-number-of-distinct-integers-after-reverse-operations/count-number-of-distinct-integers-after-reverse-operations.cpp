class Solution {
public:
    int reverseInteger(int n) {
        if(n < 10) return n;
        int x = 0;
        while(n != 0) {
            int rem = n % 10;
            x = x*10 + rem;
            n = n / 10;
        }
        return x;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int x = reverseInteger(nums[i]);
            nums.push_back(x);
        }

        unordered_set<int> st;
        for(int i=0;i<nums.size();i++) {
            st.insert(nums[i]);
        }

        return st.size();
    }
};