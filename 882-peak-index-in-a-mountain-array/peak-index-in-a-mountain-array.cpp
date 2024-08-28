class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 1, j = n-2;
        while(i <= j) {
            int m = i + (j-i)/2;
            if(arr[m] > arr[m-1] and arr[m] > arr[m+1]) return m;
            else if(arr[m-1] > arr[m]) j = m-1;
            else i = m+1;
        }
        return -1;
    }
};