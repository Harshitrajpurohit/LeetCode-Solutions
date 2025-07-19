#include<iostream>

using namespace std;

int trailingZeroes(int n){
    int cnt = 0;
    while (n >= 5){
        n = n / 5;
        cnt += n;
    }

    return cnt;
}

int main(){
    int n = 13;
    int ans = trailingZeroes(n);
    cout<<ans<<endl;
    // ans -> 2
}