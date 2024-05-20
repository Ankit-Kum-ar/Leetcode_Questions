// See explanation for approach. 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0; // Variable to track the subarrays count.
        unordered_map<int, int> s; // <value, frequency> 
        int n = nums.size();

        vector<int> pre(n); // Prefix array.
        pre[0] = nums[0]; 
        for(int i=1;i<n;i++) {
            pre[i] = nums[i] + pre[i-1];
        }

        for(int i=0;i<n;i++) {
            if(pre[i] == k) count++;
            int rem = pre[i] - k;
            if(s.find(rem) != s.end()) count += s[rem];
            s[pre[i]]++;
        }
        return count;
    }
};