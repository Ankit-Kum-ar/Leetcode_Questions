class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }

        for(int i=0;i<t.length();i++) {
            if(mp.find(t[i]) != mp.end()) {
                mp[t[i]]--;
                if(mp[t[i]] == 0) mp.erase(t[i]);
            }
        }

        if(mp.size() == 0) return true;
        return false;
    }
};