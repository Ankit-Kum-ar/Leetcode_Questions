/*
    Approach :- The approach is simple by using the two hasmaps.
    So we count frequency of each character in the map. After 
    count the frequency we check that each character also present
    in both string and if they present then check the frequency of
    that character in both string .If equal then return true
    otherwise false.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        // Solving this problem using two hashmaps.
        unordered_map<char, int> m1;
        for(int i=0;i<s.length();i++) {
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++) {
            char ch = t[i];
            if(m1.find(ch) != m1.end()){
                m1[ch]--;
                if(m1[ch] == 0) m1.erase(ch);
            }
            else return false;
        }
        if(m1.size()>0) return false;
        return true;
    }
};