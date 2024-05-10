class Solution {
public:
    int rev(int n) {
        int x = 0;
        while(n != 0) {
            int rem = n%10;
            x = x*10 + rem;
            n = n/10; 
        }
        return x;
    }
    int countNicePairs(vector<int>& nums) {
        // Making the vector as nums[i] - rev(nums[i])
        for(int i=0;i<nums.size();i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        // Make a map that hold the frequency of each number.
        unordered_map<int, int> m;
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            // To find the number of pairs, we have to check
            // before increment the frequency that number
            // has already exist or not. If exist then 
            // add the perv freq of that number and increase
            // the freq of that number also.
            if(m.find(nums[i]) != m.end()) {
                count = count%1000000007;
                count += m[nums[i]];
                m[nums[i]]++;
            }
            else m[nums[i]]++;
        }

        return count%1000000007;

    }
};