/*
    Approach :- Take two stacks where we store the characters,
    if the character is "#" then pop char from the stack.
    Otherwise push char to their respective stacks of strings.
    Then check some condition to find the answer.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '#' and s1.size() > 0) {
                s1.pop();
            }
            else if(s[i] != '#'){
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++) {
            if(t[i] == '#' and s2.size() > 0) {
                s2.pop();
            }
            else if(t[i] != '#'){
                s2.push(t[i]);
            }
        }

        if(s1.size() != s2.size()) return false;
        while(s1.size() > 0) {
            if(s1.top() != s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};