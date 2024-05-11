/*
    Approach :- Here we have to swap those character whose
    are alphabets for that just simply check the ascii code
    and then swap according to that.
*/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j) {
            int x = int(s[i]);
            int y = int(s[j]);
            if((x >= 65 and x <= 90) || (x >= 97 and x <= 122)) {
                if((y >= 65 and y <= 90) || (y >= 97 and y <= 122)) {
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }
                else j--;
            }
            else i++;
        }
        return s;
    }
};