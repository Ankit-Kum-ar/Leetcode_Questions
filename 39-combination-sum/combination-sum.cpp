class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int> candidates, vector<int> v, int target, int idx) {
        if(target == 0) {
        ans.push_back(v);
        return;
    }
    if(target < 0) return;
    for(int i=idx;i<candidates.size();i++) {
        v.push_back(candidates[i]);
        combination(candidates,v,target-candidates[i],i);
        v.pop_back(); // Here we pop back, bcz when a new call occur for next element then vector should be empty. It shouldn't contain any previous element.
    }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        int n = candidates.size();
        combination(candidates,v,target,0);
        return ans;
    }
};