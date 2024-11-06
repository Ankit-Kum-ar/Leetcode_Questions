class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0) return false;
        stack<int> st;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else {
                if(st.size() == 0) return false;
                char ch = st.top();
                st.pop();
                char th = s[i];
                if(ch == '(' and th == ')') continue;
                else if(ch == '[' and th == ']') continue;
                else if(ch == '{' and th == '}') continue;
                else return false;
            }
        }

        return st.empty();
    }
};