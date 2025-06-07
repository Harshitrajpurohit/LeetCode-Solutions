#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotateArray(vector<int> &arr, int k){
    k = k % arr.size(); // Handle cases where k > n

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k=3;

    rotateArray(arr,k);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}