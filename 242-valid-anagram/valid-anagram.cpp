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
        unordered_map<char, int> m2;
        for(int i=0;i<s.length();i++) {
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++) {
            m2[t[i]]++;
        }

        for(auto x:m1) {
            char ch1 = x.first;
            int freq1 = x.second;
            if(m2.find(ch1) != m2.end()) {
                int freq2 = m2[ch1];
                if(freq1 != freq2) return false;
            }
            else return false;
        }
        return true;
    }
};