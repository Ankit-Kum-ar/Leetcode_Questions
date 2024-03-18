class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0,j=0;
        while(i<s.length() and j<t.length()) {
            if(s[i] != t[j]) return t[j];
            i++;
            j++;
        }
        if(t.length()>s.length()) return t[t.length() - 1];
        return 'f';
    }
};