#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int> arr, int target){
    map<int,int> mp;

    for(int i=0;i<arr.size();i++){
        int rem = target - arr[i];
        if(mp.find(rem) != mp.end()){
            return {mp[rem], i};
        }
        mp[arr[i]] = i;
    }

    return {};
}

int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(arr,target);

    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
}