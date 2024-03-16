class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 1) return mat[0][0];
        int sum = 0;
        if(n%2 == 0) {
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i == j) sum += mat[i][j];
                    if(i+j == n-1) sum += mat[i][j];
                }
            }
        }
        else {
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i == j and i != n/2) sum += mat[i][j];
                    if(i+j == n-1) sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};