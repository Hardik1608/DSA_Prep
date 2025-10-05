#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool findSubsetSum(int ind, int sum, vector<int> &arr, int n, int target) {
        if (ind == n) return sum == target;

        // take
        bool take = findSubsetSum(ind + 1, sum + arr[ind], arr, n, target);

        // leave
        bool leave = findSubsetSum(ind + 1, sum, arr, n, target);

        return take || leave;
    }

public:
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        return findSubsetSum(0, 0, arr, n, target);
    }
};


int main() {
    Solution sol;
    vector<int> arr = {3, 34, 0, 12, 5, 2};
    int target = 9;
    if (sol.isSubsetSum(arr, target)) {
        cout << "Subset with given sum exists." << endl;
    } else {
        cout << "No subset with given sum exists." << endl;
    }
    return 0;
}