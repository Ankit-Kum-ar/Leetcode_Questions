class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length() > typed.length()) return false;
        unordered_set<char> s;
        unordered_set<char> t;
        for(int i=0;i<name.length();i++) s.insert(name[i]);
        for(int i=0;i<typed.length();i++) {
            t.insert(typed[i]);
        }
        if(s.size() != t.size()) return false;
        int i=0, j=0;
        while(i<name.length() and j<typed.length()) {
            if(name[i] == typed[j]) {
                j++;
                if(name[i+1] == typed[j]) i++;
            }
            else {
                if(name[i+1] != typed[j]) return false;
                i++;
            }
        }
        if(i < name.length()) return false;
        return true;

    }
};