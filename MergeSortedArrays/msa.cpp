#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;     
    int j = n-1;      
    int k = m+n-1;    

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
    }

};

int main(){
    Solution sol;
    vector<int> n1 = {1,3,5,7,0,0,0,0};
    int m = 4;
    vector<int> n2 = {2,4,6,89};
    int n = 4;

    sol.merge(n1, m, n2, n);

    for (int num : n1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}