class Solution {
public:
    vector<string> ans;
    void printParathesis(string s, int n, int nOpen, int nClose) {
        if(nOpen == n and nClose == n) {
            ans.push_back(s);
            return;
        }

        if(nOpen<n) printParathesis(s+'(',n,nOpen+1,nClose);
        if(nClose<nOpen)printParathesis(s+')',n,nOpen,nClose+1);
    
    }
    vector<string> generateParenthesis(int n) {
        printParathesis("",n,0,0);
        return ans;
    }
};