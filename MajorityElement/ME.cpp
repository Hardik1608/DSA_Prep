#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 0; i<n ; i++){
            if (nums[i] == el){
                cnt++;
            }
            else cnt--;

            if(cnt == 0) el = nums[i];

        }

        return el;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,2};

    int result = sol.majorityElement(nums);
    cout << result << endl;
}