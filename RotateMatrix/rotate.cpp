#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void reverse(vector<int> &row){
        int left = 0;
        int right = row.size() - 1;

        while(left < right){
            int temp = row[left];
            row[left] = row[right];
            row[right] = temp;
            left ++;
            right --;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // computing the transpose
        int n = matrix.size();
        for (int i = 0; i< n; i++){
            for (int j=i; j<n; j++){
                if (i!=j){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        // reversing the row
        for (int i=0; i<n; i++){
            reverse(matrix[i]);
        }
        
    }
};


int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);

    // Print the rotated matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}