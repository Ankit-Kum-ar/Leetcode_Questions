/*
    Approach :- Esme humne 2 hashmaps ka use kra hai. Toh
    ek sarre elements ki freq and elements honge or dusra
    temproary basis ke liye hai jisme basically operations
    performed honge. 
    One loop iterate from 100 to 999 which includes only
    even numbers then for example i = 234 then extract each
    digit from the number such as first = 4, second = 3, 
    third = 2. So check in temp that these elements exist or
    not. If they found then decrease the freq of that element
    in the temp map. If freq become 0 then it is not exist in
    map temp. If all first, second, third found then push
    that element in vector "v".
*/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> m; // Main hashmap
        unordered_map<int, int> temp; // Temproary hashmap
        for(int i=0;i<digits.size();i++) m[digits[i]]++;
        vector<int> v;
        for(int i=100;i<1000;i=i+2) {
            temp = m;
            int x = i;
            int first = x%10;
            x = x/10;
            int second = x%10;
            x = x/10;
            int third = x%10;
            x = x/10;
            if(temp.find(first) != temp.end() and temp[first]>0){
                temp[first]--;
            }
            else continue;
            if(temp.find(second) != temp.end() and temp[second]>0){
                temp[second]--;
            }
            else continue;
            if(temp.find(third) != temp.end() and temp[third]>0){
                temp[third]--;
            }
            else continue;
            v.push_back(i);
        }
        return v;
    }
};