/*
    Approach :- Firstly, count the occurence of each element
    in array. Toh uske liye hashmaps ka use kra (key-value)
    property ka. Jisme key toh arr[i] and value hogi 'i'.
    So, now we have to check each element has unique 
    occurence. Uske liye two unorderd sets banye jisme ek
    mein toh arr[i] insert krwaye and ek mein ouccrence
    jo maps mein store kri thi. Toh sets ki property hai ki
    same element dobara insert ni ho skta. Therefore, 
    haar element ki unique occurence ke karan dono sets ka
    size same hona chaiye. Otherwise false hai.
*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]]++;
        }
        unordered_set<int> s1; // For elements
        for(int i=0;i<arr.size();i++) s1.insert(arr[i]);

        unordered_set<int> s2; // For occurence
        for(int i=0;i<arr.size();i++) s2.insert(mp[arr[i]]);
        
        if(s1.size() == s2.size()) return true;
        return false;
    }
};