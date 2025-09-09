#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int currSum = 0;
        int left = 0;
        int n = nums.size();
        int maxLen = 0;

        for (int right = 0; right < n ; right ++){
            currSum += nums[right];

            while (currSum > k && left <= right){
                currSum = currSum - nums[left];
                left += 1;
            }

            if (currSum == k){
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
        
    }
};

int main(){
    Solution sol;
    vector <int> nums = {10, 5, 2, 7, 1, 4, 1};
    int k = 15;
    int maxL = sol.longestSubarray(nums, k);
    cout << "The longest Subarray with sum " << k << " is " << maxL << endl;
    return 0;


}