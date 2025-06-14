#include<iostream>
#include<vector>

using namespace std;

// TC-> O(n) SC-> O(n)
vector<int> rearrangeArray(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n,0);
    int posIndex=0;
    int negIndex=1;

    for(int i=0;i<n;i++){
        if(arr[i]>= 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};

    vector<int> ans = rearrangeArray(arr);

    for(int i:ans){
        cout<<i<<" ";
    }
    // ans -> [3,-2,1,-5,2,-4]
    return 0;

}