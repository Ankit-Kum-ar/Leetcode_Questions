class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string str = goal + goal;
        if(str.find(s) < s.size()) return true;
        return false;
    }
};