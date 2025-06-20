#include<iostream>
#include<vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr) {
        
        int maxi = -1;
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            ans[i] = maxi;
            maxi = max(maxi,arr[i]);
            
        }

        return ans;
}

int main(){
    vector<int> arr = {17,18,5,4,6,1};

    vector<int> ans = replaceElements(arr);

    for(int it:ans){
        cout<<it<<" ";
    }
    // ans -> 18 6 6 6 1 -1
}