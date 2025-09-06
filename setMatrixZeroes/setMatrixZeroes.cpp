// Brute Force Solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == 0){
                    markRow(matrix, i, n);
                    markCol(matrix, j, m);
                }
            }
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == -123456){
                    matrix[i][j] = 0;
                }
            }
        }

    }

    void markRow(vector<vector<int>>& matrix, int i, int n){
        for (int j=0; j<n; j++){
            if (matrix[i][j] != 0){
                matrix[i][j] = -123456;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix,int j, int m){
        for (int i=0; i<m; i++){
            if (matrix[i][j] != 0){
                matrix[i][j] = -123456;
            }
        }
    }

};

// Better Solution
