class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        string str = "";
        for(int i=0;i<s.length();i++) {
            if(isupper(s[i])) {
                str += tolower(s[i]);
            }
            else if(isdigit(s[i])) {
                str += s[i];
            }
            else if(isalpha(s[i])) {
                str += s[i];
            }
        }

        if(str.length() == 1) return true;
        for(int i=0,j=str.length()-1;i<(str.length())/2;i++,j--) {
            if(str[i] != str[j]) return false;
        }
        return true;
    }
};