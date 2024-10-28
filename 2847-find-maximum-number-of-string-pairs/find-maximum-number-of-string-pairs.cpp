class Solution {
public:
    string reve(string s) {
        for(int i=0,j=s.length()-1;i<s.length()/2;i++,j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> st;
        int cnt = 0;
        for(int i=0;i<words.size();i++) {
            string rev = reve(words[i]);
            if(st.find(rev) != st.end()) cnt++;
            else st.insert(words[i]);
        }
        return cnt;
    }
};