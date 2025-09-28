#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int i = 0;  
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];  
            }
        }
        return i + 1; 
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    Solution sol;
    int newLength = sol.removeDuplicates(nums);

    cout << "Length after removing duplicates: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}