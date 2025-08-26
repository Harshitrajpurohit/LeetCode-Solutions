#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double myPow(double x, int n){

    double ans = 1;
    long long m = n;
    if (n < 0){
        x = 1 / x;
        m = (long long)n * -1;
    }
    while (m > 0){
        if (m % 2 == 1){
            ans *= x;
            m--;
        }
        else{
            x = x * x;
            m /= 2;
        }
    }

    return ans;
}

int main(){
    double x = 2.00000;
    int n = 10;

    cout<< myPow(x,n);
    // ans -> 1024.00000
}