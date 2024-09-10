class Solution {
public:
    string largestOddNumber(string num) {
        int idx = -1;
        for(int i=num.length()-1;i>=0;i--) {
            int x = int(num[i]);
            if(x%2 != 0) {
                idx = i;
                break;
            }
        }

        if(idx == -1) return "";

        string ans;
        for(int i=0;i<=idx;i++) {
            ans.push_back(num[i]);
        }

        return ans;
    }
};