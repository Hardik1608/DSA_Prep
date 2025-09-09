#include <bits/stdc++.h>
using namespace std;

int longestSubarraySum(vector<int>& nums, int k) {
    unordered_map<long long, int> seen;
    seen[0] = -1;  
    long long prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefix_sum += nums[i];

        if (seen.count(prefix_sum - k)) {
            max_len = max(max_len, i - seen[prefix_sum - k]);
        }

        
        if (!seen.count(prefix_sum)) {
            seen[prefix_sum] = i;
        }
    }
    return max_len;
}

int main() {
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout << longestSubarraySum(nums, k) << endl; 
    return 0;
}
