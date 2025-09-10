#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLen = 0;
    int l = 0;
    int r = 0;
    int len = 0;
    // int hash[256] = {-1};
    vector<int> hash(256,-1);

    while (r < n){
        if (hash[s[r]] != -1){
            if (hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }
        len = r - l + 1;
        maxLen = max(maxLen, len);
        hash[s[r]] = r;
        r ++;
    } 


    return maxLen;        
    }
};


int main(){
    string s = "abba";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    cout << result << endl;
}