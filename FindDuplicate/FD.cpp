#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = nums[0];

        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,1,3,4,2};
    int dup = sol.findDuplicate(nums);

    cout << dup << endl;
    return 0;
}