class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        // Transpose matrix dim. are interchange with real ones.
        vector<vector<int>> transpose_Matrix(c, vector<int>(r));
        for(int i=0;i<c;i++) {
            for(int j=0;j<r;j++) {
                transpose_Matrix[i][j] = matrix[j][i];
            }
        }
        return transpose_Matrix;
    }
};