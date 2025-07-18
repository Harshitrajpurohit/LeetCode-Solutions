#include<iostream>
#include<vector>

using namespace std;

int countPrimes(int n){
    if (n <= 2)
        return 0;
    vector<bool> prime(n, true);

    for (int i = 2; i * i <= n; i++){
        if (prime[i]){
            for (int j = i * i; j < n; j += i){
                prime[j] = false;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i < prime.size(); i++){
        if (prime[i])
            cnt++;
    }
    return cnt;
}


int main(){
    int n = 10;

    int ans = countPrimes(n);
    cout<<ans<<endl;
    // ans -> 4
}