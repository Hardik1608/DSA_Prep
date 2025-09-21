#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
private:
    void swap(vector<int>& nums, int m, int n){
        int temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int dip = -1;

        // find the dip
        for (int i = n-1; i>0 ; i--){
            if (nums[i-1] < nums[i]){
                dip = i-1;
                break;
            }
        }
        if (dip == -1){
            return reverse(nums.begin(), nums.end());
            return;
        }

        // swap with element just bigger than dip
        for(int i=n-1; i>0 ; i--){
            if (nums[i] > nums[dip]){
                swap(nums, i, dip);
                break;
            }
        }

        // reverse the array after dip
        reverse(nums.begin()+ dip + 1, nums.end());

    }

};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};

    sol.nextPermutation(nums);

    for (int x: nums) cout << x << " ";
    return 0;
}