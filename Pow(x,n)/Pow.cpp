#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include<iostream>

class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n;
        double ans = 1.00;
        if (binForm < 0){
            x = 1/x;
            binForm = -binForm;
        }

        while (binForm > 0){
            if (binForm % 2 == 1){
                ans = ans * x;
            }
            x *= x; 
            binForm /= 2;
        }

        return ans;

    }        
};

int main () {
    Solution sol;
    double x = 2;
    int n = 12;

    double ans = sol.myPow(x, n);

    cout << ans << endl;

    return 0;
}
