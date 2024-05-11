class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // Check if that original is bigger than repeated.
        if(name.length() > typed.length()) return false;

        // Through sets, we check that each and every element
        // present in both strings.
        unordered_set<char> s;
        unordered_set<char> t;
        for(int i=0;i<name.length();i++) s.insert(name[i]);
        for(int i=0;i<typed.length();i++) {
            t.insert(typed[i]);
        }
        if(s.size() != t.size()) return false;

        // Two pointer approach through which we traverse
        // in both string and find out the answer.
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