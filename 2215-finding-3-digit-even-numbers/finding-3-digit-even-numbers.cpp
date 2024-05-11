class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> m;
        for(int i=0;i<digits.size();i++) {
            m[digits[i]]++;
        }
        
        vector<int> v;
        for(int i=100;i<=998;i=i+2) {
            int x = i;
            int f = x%10;
            x = x/10;
            int s = x%10;
            x = x/10;
            int t = x%10;
            x = x/10;

            if(m.find(f) != m.end()) {
                m[f]--;
                if(m[f] == 0) m.erase(f);
                if(m.find(s) != m.end()) {
                    m[s]--;
                    if(m[s] == 0) m.erase(s);
                    if(m.find(t) != m.end()) v.push_back(i);
                    m[s]++;
                }
                m[f]++;
            }
        }
        return v;
    }
};