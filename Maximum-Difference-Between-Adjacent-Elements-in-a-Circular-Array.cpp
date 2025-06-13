#include<iostream>
#include<vector>

using namespace std;

int maxAdjacentDistance(vector<int> arr){
    int mxDiff = INT_MIN;
    int n=arr.size();

    for(int i=1;i<n;i++){
        if(mxDiff < abs(arr[i-1] - arr[i])){
            mxDiff = abs(arr[i-1] - arr[i]);
        }
    }
    if(mxDiff < abs(arr[n-1] - arr[0])){
        mxDiff = abs(arr[n-1] - arr[0]);
    }

    return mxDiff;
}

int main(){
    vector<int> arr = {-5,-10,-5};
    
    int ans = maxAdjacentDistance(arr);

    cout<<ans;
    // ans -> 5
}