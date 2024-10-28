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
        unordered_map<int, int> m;
        int cnt = 0;
        for(int i=0;i<nums.size();i++) {
            int num = nums[i] - rev(nums[i]);
            if(m.find(num) != m.end()) {
                cnt = cnt%1000000007;
                cnt += m[num];
            }
            m[num]++;
        }        

        cnt = cnt%1000000007;
        return cnt;
    }
};