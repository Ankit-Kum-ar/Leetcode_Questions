/*
    Approach :- In this problem, We have to count different elements
    after inserting reverse of each existing elements. So for that
    we take help of sets jisme kewal unique elements hi count hote 
    hai. So push_back all elements in vector after reversing them.
    Then inserting all elements of vector in unordered set and
    return the size of set.
*/
class Solution {
public:
    void rev (vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x < 9) nums.push_back(x);
            else {
                int temp = 0;
                while(x != 0) {
                    int rem = x%10;
                    temp = temp*10 + rem;
                    x = x/10;
                }
                nums.push_back(temp);
            }
        }
    }
    int countDistinctIntegers(vector<int>& nums) {
        rev(nums);
        unordered_set<int> ans;
        for(int i=0;i<nums.size();i++) {
            ans.insert(nums[i]);
        }
        return ans.size();
    }
};