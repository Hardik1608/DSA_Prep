#include <iostream>
#include <vector>
#include <set>
using namespace std;



class Solution{
public:
        int longestConsecutive(vector <int> &nums){
            int maxLen = 0;
            int cnt = 0;
             set <int> st(nums.begin(), nums.end());
            int n = nums.size();

            if (n == 0) return 0;

            for (int it : st){
                if (!st.count(it - 1)){
                    int x = it;
                    cnt = 1;
                    while (st.count(x + 1)){
                        x++;
                        cnt++;
                    }
                    maxLen = max(maxLen, cnt);
                }
            }

            return maxLen;
        }


};

int main(){
    Solution sol;
    vector <int> nums = {1,5,545,234,32,5,3,2,4,4,4,4,4,4,6};

    int result = sol.longestConsecutive(nums);

    cout<< "The longest consecutive subsequence is " << result << endl;

    return 0;

}