class Solution {
public:
    bool left(vector<int>& nums,int i){
        int j = i;
        i = i-1;
        while(i>=0){
            if(nums[j]>nums[i]) return true;
            i--;
        }
        return false;
    }
    bool right(vector<int>& nums,int i){
        int j = i;
        i = i+1;
        while(i<nums.size()){
            if(nums[j]<nums[i]) return true;
            i++;
        }
        return false;
    }
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int count = nums.size() - 2 ;
        // return count;
        int n = nums.size();
        int count = 0;
        for(int i = 1;i<n-1;i++){
            if(left(nums,i) and right(nums,i)) count++;
        }
        return count;

    }
};