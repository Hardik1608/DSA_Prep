#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
    bool SearchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = n*m - 1;

        while (low <= high){
            int mid = (low + high)/2;
            int row = mid / m;
            int col = mid % m;

            if (mat[row][col] == target) return true;
            else if (mat[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 90;

    bool ans = sol.SearchMatrix(mat, target);

    cout << ans << endl;

    return 0;
}