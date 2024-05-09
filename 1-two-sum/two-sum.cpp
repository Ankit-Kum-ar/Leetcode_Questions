/*
    Approach :- Here we take help of hashmaps in which we 
    take key as nums[i] and value as index of nums[i]. So
    We subtract the current nums[i] and target value. If
    the subtract value present in maps then return the 
    indices of current nums and key-value of that subtract
    value in maps. Otherwise assign the values in map which
    is in format of nums[i] as key and value as index.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            int temp = target - nums[i];
            if(mp.find(temp) != mp.end()) {
                ans.push_back(i);
                ans.push_back(mp[temp]);
                break;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};