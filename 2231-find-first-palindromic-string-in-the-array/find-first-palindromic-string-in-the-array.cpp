class Solution {
public:
    bool palindrome(string s) {
        int n = s.length();
        for(int i=0,j=n-1;i<n/2;i++,j--) {
            if(s[i] != s[j]) return false; 
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++) {
            if(palindrome(words[i]) == true ) {
                return words[i];
            }
        }
        return "";
    }
};