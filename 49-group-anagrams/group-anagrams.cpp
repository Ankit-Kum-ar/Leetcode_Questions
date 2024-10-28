class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> m;
        for(int i=0;i<arr.size();i++) {
            string lex = arr[i];
            sort(lex.begin(), lex.end());
            if(m.find(lex) != m.end()) {
                m[lex].push_back(arr[i]);
            }
            else {
                vector<string> temp;
                temp.push_back(arr[i]);
                m[lex] = temp;
            }
        }
        vector<vector<string>> ans;

        for(auto x:m) {
            ans.push_back(x.second);
        }

        return ans;
    }
};