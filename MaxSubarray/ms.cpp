#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = -123456;
        int sum = 0;
        for (int i=0; i<n; i++){
            sum = sum + nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }

            if(sum < 0){
                sum = 0;
            }

        }
        return maxSum;
    }
};

int main() {
    vector<int> nums = {-1, -2, -3, -4};
    Solution sol;
    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}