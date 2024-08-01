class Solution {
public:
    int trap(vector<int>& heights) {
        // 1. Previous Greatest Element Array...
        int n = heights.size();
        vector<int> prev(n);
        int temp = heights[0];
        prev[0] = -1;
        for(int i=1;i<n;i++) {
            if(temp < heights[i-1]) {
                temp = heights[i-1];
            }
            prev[i] = temp;
        }

        // 2. Next Greatest Element Array...
        vector<int> next(n);
        temp = heights[n-1];
        next[n-1] = -1;
        for(int i=n-2;i>=0;i--) {
            if(temp < heights[i+1]) {
                temp = heights[i+1];
            }
            next[i] = temp;
        }

        // 3. Find min of the both arrays
        for(int i=0;i<n;i++) {
            prev[i] = min(prev[i], next[i]);
        }

        // 4. Compare the prev[i] with heights[i], If prev greater
        // than heights so subtract them and add to answer.

        int count = 0;
        for(int i=0;i<n;i++) {
            if(prev[i] > heights[i]) {
                count += (prev[i] - heights[i]);
            }
        }
        return count;


    }
};