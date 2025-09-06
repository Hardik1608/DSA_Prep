#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map <int,int> mpp;
        int n = nums.size();

        for (int i = 0; i<n; i++){
            int num = nums[i];
            int moreNeeded = target - num;

            if (mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }

        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 18, 1, 5};
    int target = 23;
    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}