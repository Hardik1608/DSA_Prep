#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        for (int i=0; i<n; i++){
            if (ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }  
        return ans;      
    }

};


void printVectorOfVectors(const vector<vector<int>>& v) {
    for (const auto& interval : v) {
        cout << "[";
        for (size_t i = 0; i < interval.size(); ++i) {
            cout << interval[i];
            if (i != interval.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << endl;
}

int main(){
    Solution sol;
    vector<vector<int>> inter = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = sol.merge(inter);

    printVectorOfVectors(ans);
    return 0;
}