#include<iostream>
#include<vector>

using namespace std;

void suffix(vector<int> arr){
    int n = arr.size();
    vector<int> suf(n,0);
    suf[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i] = suf[i+1] + arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<suf[i]<<" ";
    }
    cout<<endl;
    int l=1;
    int r=3;

    int ans = suf[l] - (r+1 <= n-1 ? suf[r+1] : 0);
    cout<<ans<<endl;
}

void prefixMax(vector<int> arr){
    int n = arr.size();
    vector<int> prefMax(n,0);
    prefMax[0] = arr[0];
    for(int i=1;i<n;i++){
        prefMax[i] = max(prefMax[i-1],arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<prefMax[i]<<" ";
    }
    cout<<endl;
    int val = 3;

    cout<<prefMax[3]; // max value till 3

}

int main(){
    vector<int> arr = {2,5,7,4,3,8,6,7,10,4,6,3,11};
    int n = arr.size();

    prefixMax(arr);
}