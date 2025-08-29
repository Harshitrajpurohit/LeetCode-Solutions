#include <iostream>
#include <vector>
using namespace std;

int rec(int m, int n, vector<vector<int>> &dp, int i=0,int j=0){
    if(i>=m || j>= n){
        return 0;
    }
    if(i == m-1 && j == n-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = rec(m,n,dp,i+1,j) + rec(m,n,dp,i,j+1);
}

int uniquePaths(int m, int n) {

//1. DP Solution
    // vector<vector<int>> dp(m, vector<int>(n,-1));
    // return rec(m,n, dp);


//2. Combination solution (nCr)
    // m+n-2 C m-1
    int N = m+n-2;
    int r = m-1;
    double res=1;
    for(int i=1;i<=r;i++){
        res = res * (N - r + i) / i;
    }
    return (int)res;
}

int main(){
    int m = 3, n=7;

    int ans = uniquePaths(m,n);
    cout<<ans<<endl;
    // ans -> 28
}