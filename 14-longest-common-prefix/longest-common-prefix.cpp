class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(), strs.end());
       string str = "";
       string first = strs[0];
       string second = strs[strs.size() - 1];
       for(int i=0,j=0;i<min(first.length(), second.length());i++,j++) {
        if(first[i] == second[j]) {
            str += first[i];
        }
        else break;
       }
       return str;
    }
};