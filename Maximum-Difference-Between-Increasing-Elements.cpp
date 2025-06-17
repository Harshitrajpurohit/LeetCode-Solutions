#include<iostream>
#include<vector>

using namespace std;


int maximumDifference(vector<int> arr){

    int maxProd = -1;
    int mini = arr[0];

    for(int i=1;i<arr.size();i++){
        int diff = arr[i] - mini;
        maxProd = max(maxProd, diff);
        mini = min(mini, arr[i]);
    }
    if(maxProd<=0)return -1;

    return maxProd;
}

int main(){
    vector<int> arr = {7,1,5,4};

    int ans = maximumDifference(arr);

    cout<<ans;
    // ans -> 4
}