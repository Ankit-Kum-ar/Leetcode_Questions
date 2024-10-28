class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            int d = target - nums[i];
            if(m.find(d) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[d]);
                break;
            }
            else m[nums[i]] = i;
        }

        return ans;
    }
};