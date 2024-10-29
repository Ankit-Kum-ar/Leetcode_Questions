class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length() != str2.length()) return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(int i=0;i<str1.length();i++) {
            m1[str1[i]]++;
            m2[str2[i]]++;
        }

        for(auto x: m1) {
            char ch = x.first;
            if(m2.find(ch) == m2.end()) return false;
        }

        unordered_map<int, int> n1; // <Occurence of character, No. of repetation of Occurenece digit>
        unordered_map<int, int> n2;

        for(auto x : m1) {
            n1[x.second]++;
        }
        for(auto x : m2) {
            n2[x.second]++;
        }

        for(auto x : n1) {
            int freq = x.first;
            if(n2.find(x.first) == n2.end()) {
                return false;
            }
            if(n1[freq] != n2[freq]) return false;
        }

        return true;
    }
};