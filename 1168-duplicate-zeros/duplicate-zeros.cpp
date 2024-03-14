class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i<n) {
            if(arr[i] == 0){
                int j = n-1;
                while(j>i){
                    arr[j] = arr[j-1];
                    j--;
                }
                i += 2;
            }
            else i++;
        }
    }
};