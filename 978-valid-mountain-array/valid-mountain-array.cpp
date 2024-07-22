class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;

        int mx = INT_MIN;
        int idx = -1;
        for(int i=0;i<n;i++) {
            if(mx < arr[i]) {
                mx = arr[i];
                idx = i;
            }
        }

        if(idx == n-1 || idx == 0) return false;

        bool flag1 = true;
        bool flag2 = true;
        for(int i=0;i<idx-1;i++) {
            if(arr[i] >= arr[i+1]) {
                flag1 = false;
                break;
            }
        }
        if(flag1 == false) return false;
        for(int i=idx;i<n-1;i++) {
            if(arr[i] <= arr[i+1]) {
                flag2 = false;
                break;
            }
        }

        if(flag2 == false) return false;

        return true;


    }
};