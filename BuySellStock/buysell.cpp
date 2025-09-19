#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprof = -1;
        int cprof = -1;
        int min = prices[0];

        for (int i = 0; i<n ; i++){
            if (prices[i] < min){
                min = prices[i];
                cprof = 0;
            }

            else{
                cprof = prices[i] - min;
            }
            maxprof = max(maxprof, cprof);
        }

        return maxprof;
        
    }
};

int main() {
    Solution sol;
    vector<int> prices = {10, 15, 5, 3, 2, 1};
    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}