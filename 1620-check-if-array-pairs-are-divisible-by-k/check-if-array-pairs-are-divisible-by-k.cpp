class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto x:arr) {
            x = (x%k + k)%k;
            mp[x]++;
        }

        if(mp.find(0) != mp.end()) {
            if(mp[0]%2 != 0) return false;
            mp.erase(0);
        }

        for(auto x: mp) {
            int key = x.first;
            key = k - key;
            if(mp.find(key) == mp.end()) return false;
            if(mp[x.first] != mp[key]) return false;
        }

        return true;
    }
};