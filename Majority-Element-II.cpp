#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    int ele1=INT_MIN, cnt1=0;
    int ele2=INT_MIN, cnt2=0;

    for(int i=0;i<n;i++){
        if(cnt1==0 && nums[i] != ele2){
            ele1 = nums[i];
            cnt1++;
        }else if(cnt2==0 && nums[i] != ele1){
            ele2 = nums[i];
            cnt2++;
        }else if(nums[i] == ele1){
            cnt1++;
        }else if(nums[i] == ele2){
            cnt2++;
        }else{
            cnt1--; cnt2--;
        }
    }

    vector<int> ans;
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(ele1==nums[i]){
            cnt1++;
        }
        if(ele2==nums[i]){
            cnt2++;
        }
    }
    if(cnt1 > int(n/3)){
        ans.push_back(ele1);
    }
    if(cnt2 > int(n/3)){
        ans.push_back(ele2);
    }
    return ans;
}

int main(){
    // vector<int> arr1 = {0,3,4,1,0};
    vector<int> arr2 = {1,2,1,2};

    vector<int> ans = majorityElement(arr2);
    for(int i:ans){
        cout<<i<<" ";
    } // ans -> [1,2]
}