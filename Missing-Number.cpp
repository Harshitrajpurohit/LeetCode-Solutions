#include<iostream>
#include<vector>

using namespace std;

int MissingNumber(vector<int> arr){
    int n = arr.size();

    int ans = 0;
    int xorAll = 0;
    for(int i=0;i<n;i++){
        xorAll ^= i+1;
        ans ^= arr[i];
    }

    return xorAll ^ ans;
}

int main(){
    vector<int> arr = {3,0,1};

    int ans = MissingNumber(arr);

    cout<<ans<<endl;

    return 0;
}